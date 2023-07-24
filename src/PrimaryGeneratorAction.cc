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
  loop = true;
  going = true;
  G4int n_particle = 1;
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
  if (going)
  {
  auto run = static_cast<Run*>(G4RunManager::GetRunManager()->GetNonConstCurrentRun());
  auto writer = DetectorConstruction::GetWriter();
  if ((writer->getScint() >= 2000) && loop)
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
    loop = false;
  }
  if (!loop){
      //uniform_real_distribution<double> dist(0.1, 2);
      //fParticleGun->SetParticleEnergy(dist(generator));
      fParticleGun->SetParticleEnergy(0.5*MeV);
    }
  if (writer->getScint() >= 4000)
  {
    std::cout << "Average From Gammas " << run->calculateAverage() << std::endl;
    going = false;
    return;
  }
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
  fParticleGun->SetParticlePosition(G4ThreeVector(x * cm, y * cm,-9.5*cm));
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
