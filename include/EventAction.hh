#ifndef EventAction_h
#define EventAction_h

#include "G4UserEventAction.hh"
#include "globals.hh"
#include "run.hh"
class RunAction;

class EventAction : public G4UserEventAction
{
  public:
    EventAction();
    ~EventAction() override;
    int n;
    void BeginOfEventAction(const G4Event* event) override;
    void EndOfEventAction(const G4Event* event) override;
};

#endif
