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
#include "G4TouchableHandle.hh"
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
  auto touch = postStep->GetTouchableHandle();
  G4int copyNo = touch->GetReplicaNumber();

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
/*
  std::cout << "particle " << particle << std::endl;
  std::cout << "process  " << procName << std::endl;
  std::cout << "start e  " << preStep->GetTotalEnergy() << std::endl;
  std::cout << "after e  " << postStep->GetTotalEnergy() << std::endl;
  std::cout << "start body " << preStep->GetPhysicalVolume()->GetName() <<std::endl;
  std::cout << "end body " << postPv->GetName() << std::endl;
  //std::cout << "start z " << preStep->GetPosition().z() << std::endl;
  //std::cout << "stop  z " << postStep->GetPosition().z() << std::endl;

  if (postPv->GetName() == prePv->GetName()){
    //if(postPv->GetName() == "Wrap"){track->SetTrackStatus(fStopAndKill);}
  }
*/
  if ((particle == "alpha") && (status == 2))
  {
  //run->setValues(posLi.x() / cm, posLi.y() / cm);
  run->setBody(postPv->GetName());
  if ((postPv->GetName() == "Scint1") || (postPv->GetName() == "Scint2"))
  {body = postPv->GetName();}
  }

  if ((particle == "gamma" && (procName == "compt")))
  {
    run->setBody(postPv->GetName());
    //if ((postPv->GetName() == "Scint1") || (postPv->GetName() == "Scint2"))
    //{body = postPv->GetName();}
  }

  //Add hits to run:: array[totalpixels]
  // dont care about ligth cone for this
  if (postPv->GetName() == "Det" && particle == "opticalphoton")
    {
      run->increment();
      //if (body == "Scint1")
      //{writer->increment();}
      //if (body == "Scint2")
      //{writer->incrementB();}
      track->SetTrackStatus(fStopAndKill);
    }

  if (run->rawData)
  {
    if (postPv->GetName() == "Det" && particle == "opticalphoton")
    {
    auto pos = postStep->GetPosition();
    run->addDataRaw(pos.x() / cm, pos.y() / cm, copyNo);
    return;
    }

      return;
  }

  return;
}
