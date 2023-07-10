#ifndef DETECTORCONSTRUCTION_HH
#define DETECTORCONSTRUCTION_HH

#include "G4VUserDetectorConstruction.hh"
#include "G4NistManager.hh"
#include "G4Box.hh"
#include "G4Tubs.hh"
#include "G4LogicalVolume.hh"
#include "G4VPhysicalVolume.hh"
#include "G4PVPlacement.hh"
#include "G4PVParameterised.hh"
#include "G4SystemOfUnits.hh"
#include "G4VisAttributes.hh"

#include "TrackerParameterisation.hh"
#include "CalorimeterParameterisation.hh"
#include "MuonBarrelParameterisation.hh"

class DetectorConstruction : public G4VUserDetectorConstruction
{
public:
    DetectorConstruction();
    ~DetectorConstruction();

    virtual G4VPhysicalVolume* Construct();

private:
    //declare materials needed in the detector
    G4Material *Air, *Scinti, *Silicon, *Argon, *Lead, *Steel;

    //define material properties
    void DefineMaterials();

    //declare detector parameters
    #include "DetectorsParameters.hh"

};

#endif
