#include "RunAction.hh"
#include "PrimaryGeneratorAction.hh"
#include "DetectorConstruction.hh"
#include "run.hh"

#include "G4RunManager.hh"
#include "G4AnalysisManager.hh"
#include "G4Run.hh"
#include "G4AccumulableManager.hh"
#include "G4LogicalVolumeStore.hh"
#include "G4LogicalVolume.hh"
#include "G4UnitsTable.hh"
#include "G4SystemOfUnits.hh"

RunAction::RunAction()
{
    auto analysisManager = G4AnalysisManager::Instance();
}

RunAction::~RunAction(){}


G4Run* RunAction::GenerateRun() {
    return new Run;
}

void RunAction::BeginOfRunAction(const G4Run*)
{
  G4cout << "Begin of Run Action" << "\n";
}

void RunAction::EndOfRunAction(const G4Run* run)
{
  G4cout << "End of Run Action " << "\n";
}
