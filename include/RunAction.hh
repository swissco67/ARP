#ifndef RunAction_h
#define RunAction_h 1

#include "G4UserRunAction.hh"
#include "globals.hh"
#include "AnalysisManager.hh"
#include <map>

class RunAction : public G4UserRunAction
{
public:
#ifdef ANALYSIS_USE
    RunAction(AnalysisManager* analysis);
#else
    RunAction();
#endif

   ~RunAction();

public:
    void BeginOfRunAction(const G4Run*);
    void EndOfRunAction(const G4Run*);

private:
#ifdef ANALYSIS_USE
 AnalysisManager* analysisMan;
#endif

};
#endif





