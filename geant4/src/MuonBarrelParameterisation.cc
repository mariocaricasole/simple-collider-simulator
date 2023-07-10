#include "MuonBarrelParameterisation.hh"

#include "G4VPhysicalVolume.hh"
#include "G4ThreeVector.hh"
#include "G4Tubs.hh"

MuonBarrelParameterisation::MuonBarrelParameterisation()
{
    #include "DetectorsParameters.icc"
}

MuonBarrelParameterisation::~MuonBarrelParameterisation()
{}

void MuonBarrelParameterisation::ComputeTransformation(const G4int copyNo, G4VPhysicalVolume* physVol) const
{
    //evaluate three indices based on copy number
    G4int i,j,k;
    k = copyNo/48;  //index of the wheel
    j = copyNo/12 - k*4;    //index of the layer
    i = copyNo - 12*j - k*48; //index of an item on a ring

    //use indices to recover orientation and position of muon counters as a function of the copy number
    G4double phi, x, y, z;
    phi = 360.*deg/nomucounter*i;

    //define translation vector
    x = muBox_radius[j]*std::sin(phi);
    y = muBox_radius[j]*std::cos(phi);
    z = 250.*(k-2)*cm;
    G4ThreeVector pos(x,y,z);

    //define rotation matrix
    G4RotationMatrix *rm = new G4RotationMatrix();
    rm->rotateZ(phi);

    //set rotation and translation to physvolume
    physVol->SetTranslation(pos);
    physVol->SetRotation(rm);
}

void MuonBarrelParameterisation::ComputeDimensions(G4Box &muonChamber, const G4int copyNo, const G4VPhysicalVolume *physVol) const
{
    G4int i,j,k;
    //evaluate three indices based on copy number
    k = copyNo/48;  //index of the wheel
    j = copyNo/12 - k*4;    //index of the layer
    i = copyNo - 12*j - k*48; //index of an item on a ring

    muonChamber.SetXHalfLength(muBox_width[j]);
    muonChamber.SetYHalfLength(muBox_thick);
    muonChamber.SetZHalfLength(muBox_length);
}
