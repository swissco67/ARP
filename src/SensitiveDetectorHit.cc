// Code based on basic example B02
//
#include "SensitiveDetectorHit.hh"
#include "G4UnitsTable.hh"
#include "G4VVisManager.hh"
#include "G4Circle.hh"
#include "G4Colour.hh"
#include "G4VisAttributes.hh"

#include <iomanip>

// THIS IS NECESSARY FOR MT MODE
G4ThreadLocal G4Allocator<SensitiveDetectorHit>* SensitiveDetectorHitAllocator=0;

SensitiveDetectorHit::SensitiveDetectorHit()
 : G4VHit(),
   fEdep(0.)
{}

SensitiveDetectorHit::~SensitiveDetectorHit() {}

SensitiveDetectorHit::SensitiveDetectorHit(const SensitiveDetectorHit& right)
  : G4VHit()
{
  fEdep      = right.fEdep;
}

const SensitiveDetectorHit& SensitiveDetectorHit::operator=(const SensitiveDetectorHit& right)
{
  fEdep      = right.fEdep;

  return *this;
}

G4bool SensitiveDetectorHit::operator==(const SensitiveDetectorHit& right) const
{
  return ( this == &right ) ? true : false;
}

void SensitiveDetectorHit::Draw()
{

}

void SensitiveDetectorHit::Print()
{
  G4cout
     << "HIT: Edep: "
     << std::setw(7) << G4BestUnit(fEdep,"Energy")
      << G4endl;
}

