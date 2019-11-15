#include "PrimaryGeneratorAction.hh"
#include "G4Event.hh"
#include "G4GeneralParticleSource.hh"

PrimaryGeneratorAction::PrimaryGeneratorAction(AnalysisManager* pAnalysis)
{
 gun = new G4GeneralParticleSource();
 analysis = pAnalysis;       
}

PrimaryGeneratorAction::~PrimaryGeneratorAction()
{
 delete gun;
}	

void PrimaryGeneratorAction::GeneratePrimaries(G4Event* anEvent)
{
 gun -> GeneratePrimaryVertex(anEvent);

#ifdef ANALYSIS_USE
 G4double energy = gun -> GetParticleEnergy();
 analysis -> SetPrimaryEnergy(energy);
#endif 
}



