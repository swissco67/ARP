//  code based on the basic example B2
//
#include "SensitiveDetector.hh"
#include "G4HCofThisEvent.hh"
#include "G4Step.hh"
#include "G4ThreeVector.hh"
#include "G4SDManager.hh"
#include "G4ios.hh"
#include "G4SystemOfUnits.hh"

SensitiveDetector::SensitiveDetector(const G4String& name,
                         const G4String& hitsCollectionName, AnalysisManager* analysis_manager) 
 : G4VSensitiveDetector(name),
   fHitsCollection(NULL)
{
  collectionName.insert(hitsCollectionName);
  analysis = analysis_manager;
}

SensitiveDetector::~SensitiveDetector() 
{}

void SensitiveDetector::Initialize(G4HCofThisEvent* hce)
{
  // Create hits collection

  fHitsCollection 
    = new SensitiveDetectorHitsCollection(SensitiveDetectorName, collectionName[0]); 

  // Add this collection in hce

  G4int hcID 
    = G4SDManager::GetSDMpointer()->GetCollectionID(collectionName[0]);
  hce->AddHitsCollection( hcID, fHitsCollection ); 
}

G4bool SensitiveDetector::ProcessHits(G4Step* aStep, 
                                     G4TouchableHistory*)
{  
  // energy deposit
  G4double edep = aStep->GetTotalEnergyDeposit();

  if (edep==0.) return false;

  G4String volumeName = aStep -> GetPreStepPoint() -> GetPhysicalVolume()-> GetName();

  if(volumeName != "Tracker") 
    return false;  

  SensitiveDetectorHit* newHit = new SensitiveDetectorHit();

  newHit -> SetEdep(edep);
  
  fHitsCollection -> insert( newHit );

  return true;
}

void SensitiveDetector::EndOfEvent(G4HCofThisEvent*)
{
#ifdef ANALYSIS_USE
// Initialisation of total energy deposition per event to zero
 G4double totalEdepInOneEvent =0;
 
 G4int NbHits = fHitsCollection->entries();
   //G4cout << "number of hits " <<NbHits << G4endl;
    
   for (G4int i=0;i<NbHits;i++) 
	{
        G4double edep = (*fHitsCollection)[i]->GetEdep();
	totalEdepInOneEvent = totalEdepInOneEvent + edep;
      } 


 if (totalEdepInOneEvent!=0)analysis-> StoreEnergyDeposition(totalEdepInOneEvent/keV);
#endif 
}
