#ifndef TRACKER_HH
#define TRACKER_HH

#include "G4VPVParameterisation.hh"
#include "G4SystemOfUnits.hh"

class TrackerParametrisation : public G4VPVParameterisation
{ 
  public:
    TrackerParametrisation();
    virtual ~TrackerParametrisation();

    void ComputeTransformation(const G4int copyNo, G4VPhysicalVolume *physVol) const;
    void ComputeDimensions(G4Tubs &trackerLayer, const G4int copyNo, const G4VPhysicalVolume * physVol) const;

  private:
  //detector parameters imported
  #include "DetectorsParameters.hh"

};

#endif
