#ifndef ANALYSISMANAGER_HH
#define ANALYSISMANAGER_HH 

#include "globals.hh"
#include "g4root.hh"

// Define the total number of columns in the ntuple
const G4int MaxNtCol = 5;

class AnalysisManager
{ 

public:
   AnalysisManager();
  ~AnalysisManager();
  
  void book(); // booking the ROOT file

  void SetPrimaryEnergy(G4double energy); // Store the energy of the primary particles

  void StoreEnergyDeposition(G4double edep);// Fill the ntuple with energy deposition per event
  
  void FillSecondaries(G4int AA, G4double charge, G4double energy); 
  // Information about secondary particles

  void finish();
  // Close the ROOT file with all the results stored in nutples 

private:
  G4bool factoryOn; 
  G4int  fNtColId[MaxNtCol];

};

#endif




