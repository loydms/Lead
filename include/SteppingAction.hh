#ifndef SteppingAction_h
#define SteppingAction_h

#include "G4UserSteppingAction.hh"
#include "globals.hh"

class G4LogicalVolume;

class EventAction;

class SteppingAction : public G4UserSteppingAction
{
  public:
    SteppingAction();
    ~SteppingAction() override;
    G4String body;

    void UserSteppingAction(const G4Step*) override;
  bool rawData;
};

#endif
