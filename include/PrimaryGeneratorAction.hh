#ifndef PrimaryGeneratorAction_hh
#define PrimaryGeneratorAction_hh 1

#include "G4VUserPrimaryGeneratorAction.hh"
#include "globals.hh"
#include "AnalysisManager.hh"

using namespace std; 


class G4GeneralParticleSource;
class G4Event;
class PrimaryGeneratorAction : public G4VUserPrimaryGeneratorAction
{
public:
PrimaryGeneratorAction(AnalysisManager*);
~PrimaryGeneratorAction();

void GeneratePrimaries(G4Event* anEvent);

private:  
G4GeneralParticleSource* gun;
AnalysisManager* analysis;
};
#endif
