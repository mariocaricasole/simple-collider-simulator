#include "CalorimeterParameterisation.hh"

#include "G4VPhysicalVolume.hh"
#include "G4ThreeVector.hh"
#include "G4Tubs.hh"
#include "G4SystemOfUnits.hh"

CalorimeterParameterisation::CalorimeterParameterisation()
{
#include "DetectorsParameters.icc"
}

CalorimeterParameterisation::~CalorimeterParameterisation()
{}

void CalorimeterParameterisation::ComputeTransformation(const G4int,G4VPhysicalVolume *physVol) const
{
    G4ThreeVector origin;
    physVol->SetTranslation(origin);
}

void CalorimeterParameterisation::ComputeDimensions(G4Tubs & calorimeterLayer, const G4int copyNo, const G4VPhysicalVolume*) const
{
    G4double innerRad = caloTubs_rmin + copyNo*(absorber_thick+scinti_thick);
    calorimeterLayer.SetInnerRadius(innerRad);
    calorimeterLayer.SetOuterRadius(innerRad+absorber_thick);
    calorimeterLayer.SetZHalfLength(caloTubs_dz);
    calorimeterLayer.SetStartPhiAngle(caloTubs_sphi);
    calorimeterLayer.SetDeltaPhiAngle(caloTubs_dphi);
}
