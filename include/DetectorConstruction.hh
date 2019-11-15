#ifndef DetectorConstruction_H 
#define DetectorConstruction_H 1
#include "G4VUserDetectorConstruction.hh"
#include "globals.hh"
#include "AnalysisManager.hh"

class G4VPhysicalVolume;
class DetectorMessenger;
class G4LogicalVolume;

class G4GDMLParser;

class DetectorConstruction : public G4VUserDetectorConstruction
{
public:
    DetectorConstruction(const G4GDMLParser&, AnalysisManager* analysis);
    ~DetectorConstruction();

    G4VPhysicalVolume* Construct();

    void ConstructSDandField();

private:
  AnalysisManager* analysis;
  const G4GDMLParser& fParser;
};
#endif
