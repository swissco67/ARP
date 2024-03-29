#include "G4ios.hh"
#include "G4SteppingManager.hh"
#include "G4Step.hh"
#include "G4Track.hh"
#include "G4StepPoint.hh"
#include "G4VPhysicalVolume.hh"
#include "SteppingAction.hh"
#include "AnalysisManager.hh"
#include "G4SystemOfUnits.hh"

SteppingAction::SteppingAction(AnalysisManager* pAnalysis)
{ 
analysis = pAnalysis;
fSecondary = 0; 
}

SteppingAction::~SteppingAction()
{ 
}

void SteppingAction::UserSteppingAction(const G4Step* aStep)
{ 
  G4SteppingManager*  steppingManager = fpSteppingManager;
  G4Track* theTrack = aStep -> GetTrack();

  // check if it is alive
  if(theTrack-> GetTrackStatus() == fAlive) { return; }

  // Retrieve the secondary particles
    fSecondary = steppingManager -> GetfSecondary();

#ifdef ANALYSIS_USE  
   for(size_t lp1=0;lp1<(*fSecondary).size(); lp1++)
     { 
       // Retrieve the info about the generation of secondary particles 
       G4String volumeName = (*fSecondary)[lp1] -> GetVolume() -> GetName(); // volume where secondary was generated 
       G4String secondaryParticleName =  (*fSecondary)[lp1]->GetDefinition() -> GetParticleName();  // name of the secondary
       G4double secondaryParticleKineticEnergy =  (*fSecondary)[lp1] -> GetKineticEnergy(); // kinetic energy
      // G4String process = (*fSecondary)[lp1]-> GetCreatorProcess()-> GetProcessName();   // process creating it
       G4double charge = (*fSecondary)[lp1] -> GetDynamicParticle() -> GetDefinition() -> GetPDGCharge();
       G4int AA = (*fSecondary)[lp1] -> GetDynamicParticle() -> GetDefinition() -> GetBaryonNumber();
          
     if (volumeName == "Tracker") 
//Testing with larger volume!
//if (volumeName == "DiaVol_phys")
	 {
	   if ((secondaryParticleName == "proton") ||
               (secondaryParticleName == "neutron")||
               (secondaryParticleName == "alpha") ||
               (secondaryParticleName == "deuton") || 
               (secondaryParticleName == "triton") || 
               (secondaryParticleName == "He3") || 
	       (secondaryParticleName =="GenericIon"))
               analysis -> FillSecondaries(AA, charge, secondaryParticleKineticEnergy/MeV); 	
          }
   }
#endif	 
}

