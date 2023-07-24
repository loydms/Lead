#include "G4RunManagerFactory.hh"
#include "G4UImanager.hh"
#include "G4RunManager.hh"

#include "DetectorConstruction.hh"
#include "ActionInitialization.hh"
#include "physicslist.hh"

#include "FTFP_BERT_HP.hh"
#include "G4EmStandardPhysics.hh"
#include "G4OpticalPhysics.hh"

#include "G4VisExecutive.hh"
#include "G4UIExecutive.hh"


int main(int argc, char** argv)
{
  // Interactive
  G4UIExecutive* ui = new G4UIExecutive(argc, argv);

  //Construct the default run manager
  //auto runManager = G4RunManagerFactory::CreateRunManager();
  auto runManager = new G4RunManager;
  //Set manador initialization classes
  //runManager->SetUserInitialization(new DetectorConstruction());

  //Physics List
  G4VModularPhysicsList* physicsList = new FTFP_BERT_HP;
  //auto physicsList = new PhysicsList;
  physicsList->ReplacePhysics(new G4EmStandardPhysics());
  //auto optical = new G4OpticalPhysics();
  //optical->SetScintByParticleType(true);
  physicsList->RegisterPhysics(new G4OpticalPhysics);
  G4OpticalParameters::Instance()->SetScintByParticleType(true);
  //runManager->SetUserInitialization(physicsList);
  runManager->SetUserInitialization(physicsList);
  runManager->SetUserInitialization(new ActionInitialization);

  runManager->SetUserInitialization(new DetectorConstruction());

  //Initialize G4 kernel
  runManager->Initialize();



  G4VisManager* visManager = new G4VisExecutive;

  visManager->Initialize();

  //Get the pointer to the UI manager and set verbosities
  G4UImanager* UI = G4UImanager::GetUIpointer();

  //UI->ApplyCommand("/control/execute init_vis.mac");
  ui->SessionStart();
  delete ui;


  // job termination
  delete runManager;
  delete visManager;
  return 0;
}
