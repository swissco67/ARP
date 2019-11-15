#ifndef ActionInitialization_h
#define ActionInitialization_h 1

#include "G4VUserActionInitialization.hh"
#include "AnalysisManager.hh"

class AnalysisManager;
class G4GeneralParticleSource;

class ActionInitialization: public G4VUserActionInitialization
{
  public:
    ActionInitialization(AnalysisManager* );
    virtual ~ActionInitialization();

    virtual void BuildForMaster() const;
    virtual void Build() const;

private:
    AnalysisManager* analysis;
};

#endif

    
