#include "SteppingAction.hh"
#include "EventAction.hh"
#include "DetectorConstruction.hh"
#include "run.hh"
#include "Writer.hh"

#include "G4Step.hh"
#include "G4Event.hh"
#include "G4RunManager.hh"
#include "G4LogicalVolume.hh"
#include "G4SystemOfUnits.hh"
#include "G4Scintillation.hh"

SteppingAction::SteppingAction()
{
  G4cout << "Generate Stepping" << G4endl;
}

SteppingAction::~SteppingAction()
{
  G4cout << "Delete Stepping" << G4endl;
}


void SteppingAction::UserSteppingAction(const G4Step* step)
{
  auto track = step->GetTrack();
  auto postStep = step->GetPostStepPoint();
  auto preStep = step->GetPreStepPoint();
  auto postPv = postStep->GetPhysicalVolume();
  auto prePv = preStep->GetPhysicalVolume();

  auto edep = step->GetTotalEnergyDeposit();
  if (!postPv){return;}

  auto particle = track->GetParticleDefinition()->GetParticleName();
  auto run = static_cast<Run*>(G4RunManager::GetRunManager()->GetNonConstCurrentRun());
  auto writer = DetectorConstruction::GetWriter();
  G4double calcX = 0;
  G4double calcY = 0;
  auto status = track->GetTrackStatus();
  auto posLi = postStep->GetPosition();
  auto stepProcess = (G4VProcess*)postStep->GetProcessDefinedStep();
  auto procName = stepProcess->GetProcessName();
  auto name = postPv->GetName();
  std::cout << "particle " << particle << std::endl;
  std::cout << "process  " << procName << std::endl;
  std::cout << "start e  " << preStep->GetTotalEnergy() << std::endl;
  std::cout << "after e  " << postStep->GetTotalEnergy() << std::endl;
  std::cout << "start body " << preStep->GetPhysicalVolume()->GetName() <<std::endl;
  std::cout << "end body " << postPv->GetName() << std::endl;
  //std::cout << "start z " << preStep->GetPosition().z() << std::endl;
  //std::cout << "stop  z " << postStep->GetPosition().z() << std::endl;

  if (name == prePv->GetName()){
    body = 0;
    if (name == "Scint1"){body = 1;}
    else if (name == "spacer"){body = 2;}
    else if (name == "Scint2"){body = 3;}
    run->addEnergy(body, edep);
    //if(postPv->GetName() == "Wrap"){track->SetTrackStatus(fStopAndKill);}
  }





  return;
}
