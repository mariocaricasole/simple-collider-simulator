#ifndef TRACKER_PARAMETERISATION_HH
#define TRACKER_PARATETERISATION_HH

#include "G4VPVParameterisation.hh"
#include "G4SystemOfUnits.hh"

class TrackerParameterisation : public G4VPVParameterisation
{ 
  public:
  
    TrackerParameterisation();
    virtual ~TrackerParameterisation();
    void ComputeTransformation(const G4int copyNo, G4VPhysicalVolume *physVol) const;
    void ComputeDimensions(G4Tubs &trackerLayer, const G4int copyNo, const G4VPhysicalVolume * physVol) const;

  private:
#include "DetectorsParameters.hh"

};

#endif
