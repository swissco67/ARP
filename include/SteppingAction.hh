#ifndef SteppingAction_h
#define SteppingAction_h 1

#include "G4UserSteppingAction.hh"
#include "AnalysisManager.hh"
#include "G4Event.hh"
#include "G4EventManager.hh"
#include "G4ios.hh"
#include "globals.hh"

class G4Step;

class SteppingAction: public G4UserSteppingAction
{
public:
 SteppingAction(AnalysisManager* analysis);
 ~SteppingAction();

 void UserSteppingAction(const G4Step* aStep);

private:
 AnalysisManager* analysis; 
 G4TrackVector* fSecondary;
};
#endif
