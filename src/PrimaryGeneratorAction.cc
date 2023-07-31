#include "PrimaryGeneratorAction.hh"
#include "DetectorConstruction.hh"
#include "run.hh"

#include "G4LogicalVolumeStore.hh"
#include "G4LogicalVolume.hh"
#include "G4Box.hh"
#include "G4RunManager.hh"
#include "G4ParticleGun.hh"
#include "G4ParticleTable.hh"
#include "G4ParticleDefinition.hh"
#include "G4SystemOfUnits.hh"
#include "Randomize.hh"
#include <math.h>
#include <chrono>
#include <random>
#define PI 3.14159265
using std::uniform_real_distribution;
using std::chrono::high_resolution_clock;


PrimaryGeneratorAction::PrimaryGeneratorAction():
  generator(high_resolution_clock::now().time_since_epoch().count())
{
  loop1 = true;
  loop2 = false;
  going = true;
  G4int n_particle = 1;
  G4int num = 0;
  totalWidth = DetectorConstruction::GetWidth() * DetectorConstruction::GetPixels() * DetectorConstruction::GetArrays();
  fParticleGun = new G4ParticleGun(n_particle);

  G4ParticleTable* particleTable = G4ParticleTable::GetParticleTable();
  G4String particleName;
  G4ParticleDefinition* neutron = particleTable->FindParticle(particleName="neutron");
  fParticleGun->SetParticleDefinition(neutron);
  fParticleGun->SetParticleEnergy(0.025 * eV);

}

PrimaryGeneratorAction::~PrimaryGeneratorAction()
{
  delete fParticleGun;
}

void PrimaryGeneratorAction::GeneratePrimaries(G4Event* anEvent)
{
  std::cout << "Creating Neutron" << std::endl;
  if (going)
  {
  auto run = static_cast<Run*>(G4RunManager::GetRunManager()->GetNonConstCurrentRun());
  auto writer = DetectorConstruction::GetWriter();
  if ((num >= 100000) && loop1)
  {
    G4ParticleTable* particleTable = G4ParticleTable::GetParticleTable();
    G4String particleName;
    G4ParticleDefinition* gamma = particleTable->FindParticle(particleName="gamma");
    fParticleGun->SetParticleDefinition(gamma);
    //fParticleGun->SetParticleEnergy(1*MeV);
    //G4cout << "Hit 1000 counts runs" << G4endl;
    std::cout << "Average From Neutrons " << run->calculateAverage() << std::endl;
    run->setParticle(1);
    //run->clearArray();
    loop1 = false;
    loop2 = true;
  }
  if ((num >= 200000) && loop2)
  {
    G4ParticleTable* particleTable = G4ParticleTable::GetParticleTable();
    G4String particleName;
    G4ParticleDefinition* gamma = particleTable->FindParticle(particleName="gamma");
    fParticleGun->SetParticleDefinition(gamma);
    //fParticleGun->SetParticleEnergy(1*MeV);
    //G4cout << "Hit 1000 counts runs" << G4endl;
    std::cout << "Average From Neutrons " << run->calculateAverage() << std::endl;
    run->setParticle(2);
    //run->clearArray();
    loop2 = false;
  }
  if (!loop1){
      //uniform_real_distribution<double> dist(0.1, 2);
      //fParticleGun->SetParticleEnergy(dist(generator));
      fParticleGun->SetParticleEnergy(0.25*MeV);
    }
  if (loop2){
      //uniform_real_distribution<double> dist(0.1, 2);
      //fParticleGun->SetParticleEnergy(dist(generator));
      fParticleGun->SetParticleEnergy(0.5*MeV);
      }
  if (num >= 300000)
  {
    std::cout << "Average From Gammas " << run->calculateAverage() << std::endl;
    going = false;
    return;
  }
  num ++;
  uniform_real_distribution<double> dist(-3, 3);
  uniform_real_distribution<double> dist2(-5.7,5.7);
  uniform_real_distribution<double> dist3(-0.011,0.011);
  //double thetaX = dist(generator);
  //double thetaY = dist(generator);
  //double x = dist3(generator);
  double y = dist2(generator);
  double x = dist2(generator);
  //fParticleGun->SetParticleMomentumDirection(G4ThreeVector(sin(thetaX*PI/180)*cm,sin(thetaY*PI/180)*cm,10*cm));
  x = 0;
  y = 0;
  fParticleGun->SetParticlePosition(G4ThreeVector(0 * cm, 0 * cm,-9.5*cm));
  fParticleGun->SetParticleMomentumDirection(G4ThreeVector(0,0,1));
  //fParticleGun->SetParticlePosition(G4ThreeVector(-(2.5*(0.63 + 0.085)+x)*cm,y*cm,-9.5*cm));
  fParticleGun->GeneratePrimaryVertex(anEvent);

  /*
  uniform_real_distribution<double> dist(-3, 3);
  uniform_real_distribution<double> dist2(totalWidth, -totalWidth);
  double thetaX = dist(generator);
  double thetaY = dist(generator);
  double x = dist2(generator);
  double y = dist2(generator);

  fParticleGun->SetParticleMomentumDirection(G4ThreeVector(sin(thetaX*PI/180)*cm,sin(thetaY*PI/180)*cm,10*cm));
  fParticleGun->SetParticlePosition(G4ThreeVector(x * cm, y * cm,-9.5*cm));
  //fParticleGun->SetParticleMomentumDirection(G4ThreeVector(0,0,1));
  //fParticleGun->SetParticlePosition(G4ThreeVector(0,0,-9.5*cm));
  fParticleGun->GeneratePrimaryVertex(anEvent);
  */
}
}
