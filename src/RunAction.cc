#include "RunAction.hh"
#include "AnalysisManager.hh"
#include "G4SystemOfUnits.hh"
#include "G4UnitsTable.hh"
#include "G4ios.hh"
#include "G4Run.hh"

#ifdef ANALYSIS_USE
RunAction::RunAction(AnalysisManager* analysis)
{ 

  analysisMan = analysis;

}
#else
RunAction::RunAction()
{ }
#endif

RunAction::~RunAction()
{
}

void RunAction::BeginOfRunAction(const G4Run* aRun)
{
  G4int run_number = aRun->GetRunID();
  G4cout << "### Run " << run_number << " start." << G4endl;

#ifdef ANALYSIS_USE
  // Create ROOT file, histograms and ntuple
  analysisMan -> book();
#endif 
}

void RunAction::EndOfRunAction(const G4Run* aRun)
{
  G4cout << "Number of events = " << aRun->GetNumberOfEvent() << G4endl;

#ifdef ANALYSIS_USE
// Close the output ROOT file with the results
   analysisMan -> finish(); 
#endif
}

