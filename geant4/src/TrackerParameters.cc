#include "TrackerParameters.hh"

#include "G4VPhysicalVolume.hh"
#include "G4ThreeVector.hh"
#include "G4Tubs.hh"

TrackerParametrisation::TrackerParametrisation()
{
    #include "DetectorsParameters.icc"
}

TrackerParametrisation::~TrackerParametrisation()
{}

void TrackerParametrisation::ComputeTransformation(const G4int, G4VPhysicalVolume* physVol) const
{
    G4ThreeVector origin;
    physVol->SetTranslation(origin);
}

void TrackerParametrisation::ComputeDimensions(G4Tubs& trackerLayer, const G4int copyNo, const G4VPhysicalVolume*) const
{
    trackerLayer.SetInnerRadius(tracker_radius[copyNo]);
    trackerLayer.SetOuterRadius(tracker_radius[copyNo]+tracker_thick);
    trackerLayer.SetZHalfLength(tracker_length[copyNo]);
    trackerLayer.SetStartPhiAngle(trkTubs_sphi);
    trackerLayer.SetDeltaPhiAngle(trkTubs_dphi);
}
