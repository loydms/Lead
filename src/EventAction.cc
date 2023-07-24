#include "EventAction.hh"
#include "RunAction.hh"
#include "DetectorConstruction.hh"
#include "G4Event.hh"
#include "Writer.hh"
#include "G4RunManager.hh"



EventAction::EventAction(
) : G4UserEventAction(){
  n = 0;
}

EventAction::~EventAction(){}

void EventAction::BeginOfEventAction(const G4Event*)
{
  auto run = static_cast<Run*>(G4RunManager::GetRunManager()->GetNonConstCurrentRun());
  //if (!(n%100)){std::cout << n << std::endl;}
  run->clearCurrent();
}

void EventAction::EndOfEventAction(const G4Event*)
{
  n ++;
  auto run = static_cast<Run*>(G4RunManager::GetRunManager()->GetNonConstCurrentRun());
  auto writer = DetectorConstruction::GetWriter();
  if (run->getCurrentCount() >= 50){
  writer->addScint();
  run->saveData();
}
int s = writer->getScint();
if ((!(s%50)) && (s<4000)){std::cout << s << " Neutrons" << std::endl;}
}
