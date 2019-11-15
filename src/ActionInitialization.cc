#include "ActionInitialization.hh"
#include "PrimaryGeneratorAction.hh"
#include "SteppingAction.hh"
#include "G4RunManager.hh"
#include "AnalysisManager.hh"
#include "RunAction.hh"
#include "G4GeneralParticleSource.hh"

ActionInitialization::ActionInitialization(AnalysisManager* analysisMan):
G4VUserActionInitialization()
{
 analysis = analysisMan;
}


ActionInitialization::~ActionInitialization()
{
}

void ActionInitialization::BuildForMaster() const
{
	// In MT mode, to be clearer, the RunAction class for the master thread might be
	// different than the one used for the workers.
	// This RunAction will be called before and after starting the
	// workers.

}

void ActionInitialization::Build() const
{   

 // Initialize the primary particles
PrimaryGeneratorAction* primary = new PrimaryGeneratorAction(analysis);
SetUserAction(primary); 

#ifdef ANALYSIS_USE
 RunAction* run = new RunAction(analysis);
#else
 RunAction* run = new RunAction();
#endif

SetUserAction(run); 

SteppingAction* stepping = new SteppingAction(analysis);
SetUserAction(stepping);
	
}  

