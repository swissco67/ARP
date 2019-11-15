// Code based on the basic example B02

#ifndef SensitiveDetectorHit_h
#define SensitiveDetectorHit_h 1

#include "G4VHit.hh"
#include "G4THitsCollection.hh"
#include "G4Allocator.hh"
#include "G4ThreeVector.hh"
#include "tls.hh" // FOR MT

class SensitiveDetectorHit : public G4VHit
{
  public:
    SensitiveDetectorHit();
    SensitiveDetectorHit(const SensitiveDetectorHit&);
    virtual ~SensitiveDetectorHit();

    // operators
    const SensitiveDetectorHit& operator=(const SensitiveDetectorHit&);
    G4bool operator==(const SensitiveDetectorHit&) const;

    inline void* operator new(size_t);
    inline void  operator delete(void*);

    // methods from base class
    virtual void Draw();
    virtual void Print();

    // Set methods
    void SetEdep     (G4double de)      { fEdep = de; };
   
    G4double GetEdep() const     { return fEdep; };
 
  private:

      G4double      fEdep;
};

typedef G4THitsCollection<SensitiveDetectorHit> SensitiveDetectorHitsCollection;

extern G4ThreadLocal G4Allocator<SensitiveDetectorHit>* SensitiveDetectorHitAllocator;

inline void* SensitiveDetectorHit::operator new(size_t)
{
  if(!SensitiveDetectorHitAllocator)
      SensitiveDetectorHitAllocator = new G4Allocator<SensitiveDetectorHit>;
  return (void *) SensitiveDetectorHitAllocator->MallocSingle();
}

inline void SensitiveDetectorHit::operator delete(void *hit)
{
  SensitiveDetectorHitAllocator->FreeSingle((SensitiveDetectorHit*) hit);
}

#endif
