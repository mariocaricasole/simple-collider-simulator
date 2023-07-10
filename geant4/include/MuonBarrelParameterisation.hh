#ifndef MUON_BARREL_PARAMETERISATION_HH
#define MUON_BARREL_PARAMETERISATION_HH

#include "G4VPVParameterisation.hh"
#include "G4SystemOfUnits.hh"
#include "G4Box.hh"

class MuonBarrelParameterisation : public G4VPVParameterisation
{
  public:
    MuonBarrelParameterisation();
    virtual ~MuonBarrelParameterisation();

    void ComputeTransformation(const G4int copyNo, G4VPhysicalVolume *physVol) const;
    void ComputeDimensions(G4Box &muonChamber, const G4int copyNo, const G4VPhysicalVolume *physVol) const;

  private:
#include "DetectorsParameters.hh"
};

#endif
