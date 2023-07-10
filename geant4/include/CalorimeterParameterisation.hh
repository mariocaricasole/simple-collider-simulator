#ifndef CALORIMETER_PARAMETERISATION_HH
#define CALORIMETER_PARAMETERISATION_HH

#include "G4VPVParameterisation.hh"

class CalorimeterParameterisation : public G4VPVParameterisation
{
public:
    CalorimeterParameterisation();
    ~CalorimeterParameterisation();
    void ComputeTransformation(const G4int copyNo, G4VPhysicalVolume *physVol) const;
    void ComputeDimensions(G4Tubs & calorimeterLayer, const G4int copyNo, const G4VPhysicalVolume * physVol) const;

private:
    #include "DetectorsParameters.hh"

};

#endif
