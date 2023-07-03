#ifndef CALORIMETER_HH
#define CALORIMETER_HH

#include "G4VPVParameterisation.hh"

class CalorimeterParametrisation : public G4VPVParameterisation
{
public:
    CalorimeterParametrisation();
    ~CalorimeterParametrisation();

    void ComputeTransformation(const G4int copyNo, G4VPhysicalVolume *physVol) const;
    void ComputeDimensions(G4Tubs & calorimeterLayer, const G4int copyNo, const G4VPhysicalVolume * physVol) const;

private:
    //detector parameters imported here
    #include "DetectorsParameters.hh"
};

#endif
