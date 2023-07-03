#include "DetectorsConstruction.hh"

//constructor
DetectorConstruction::DetectorConstruction()
{
	DefineMaterials();
	#include "DetectorsParameters.icc"
}


//destructor
DetectorConstruction::~DetectorConstruction()
{}


// DEFINING MATERIALS
void DetectorConstruction::DefineMaterials()
{
	//instance of Nist manager
	G4NistManager *nist = G4NistManager::Instance();
	
	//get all elements' and material definitions from nist manager
	Silicon = nist->FindOrBuildMaterial("G4_Si");
	Lead = nist->FindOrBuildMaterial("G4_Pb");
	Argon = nist->FindOrBuildMaterial("G4_Ar");
	G4Element *C = nist->FindOrBuildElement("C");
	G4Element *H = nist->FindOrBuildElement("H");
	
	//world material
	Air = nist->FindOrBuildMaterial("G4_Galactic");

	//define scintillator material
	Scinti = new G4Material("Scintillator", 1.032*g/cm3, 2);
	Scinti->AddElement(C, 9);
	Scinti->AddElement(H,10);
}


G4VPhysicalVolume* DetectorConstruction::Construct()
{
	/* DETECTOR GEOMETRY */

	//experimental hall
	G4Box *solidHall = new G4Box("solidHall", expHall_x, expHall_y, expHall_z);
	G4LogicalVolume *logicHall = new G4LogicalVolume(solidHall, Air, "logicHall");
	G4VPhysicalVolume *physHall= new G4PVPlacement(0, G4ThreeVector(0., 0., 0.), logicHall, "physHall", 0, false, 0, true);
	
	
	//tracker
	G4VSolid *solidTracker = new G4Tubs("solidTracker", trkTubs_rmin, trkTubs_rmax, trkTubs_dz, trkTubs_sphi, trkTubs_dphi);
	G4LogicalVolume *logicTracker = new G4LogicalVolume(solidTracker, Silicon, "logicTracker");
	G4VPhysicalVolume *physTracker = new G4PVPlacement(0, G4ThreeVector(0., 0., 0.), logicTracker, "physTracker", logicHall, false, 0, true);


	//tracker layers
	G4VSolid * solidTrackerLayer = new G4Tubs("solidTracker", trkTubs_rmin, trkTubs_rmax, trkTubs_dz, trkTubs_sphi, trkTubs_dphi);
	G4LogicalVolume *logicTrackerLayer = new G4LogicalVolume(solidTrackerLayer, Silicon, "logicTrackerLayer", 0,0,0);
	G4VPVParameterisation *trackerParam = new TrackerParametrisation;
	G4VPhysicalVolume *physTrackerLayer = new G4PVParameterised("physTrackerLayer",logicTrackerLayer,logicTracker, kXAxis, notrkLayers, trackerParam);

	//calorimeter
	G4VSolid *solidCalorimeter = new G4Tubs("solidCalorimeter", caloTubs_rmin, caloTubs_rmax, caloTubs_dz, caloTubs_sphi, caloTubs_dphi);
	G4LogicalVolume *logicCalorimeter = new G4LogicalVolume(solidCalorimeter, Scinti, "logicCalorimeter", 0,0,0);
	G4VPhysicalVolume *physCalorimeter = new G4PVPlacement(0, G4ThreeVector(), logicCalorimeter, "physCalorimeter", logicHall, false, 0);

	//calorimeter layers
	G4VSolid *solidCalorimeterLayer = new G4Tubs("solidCalorimeterLayer", caloRing_rmin, caloRing_rmax, caloRing_dz, caloRing_sphi, caloRing_dphi);
	G4LogicalVolume *logicCalorimeterLayer = new G4LogicalVolume(solidCalorimeterLayer, Lead, "logicCalorimeterLayer", 0,0,0);
	G4VPVParameterisation *calorimeterParams = new CalorimeterParametrisation;
	G4VPhysicalVolume *physCalorimeterLayer = new G4PVParameterised("physCalorimeterLayer", logicCalorimeterLayer, logicCalorimeter, kXAxis, nocaloLayers, calorimeterParams);

	//muon counters (placed all around z-axis)
	G4VSolid *solidMuonCounter= new G4Box("solidMuonCounter", muBox_width, muBox_thick, muBox_length);
	G4LogicalVolume *logicMuonCounter= new G4LogicalVolume(solidMuonCounter, Scinti, "logicMuonCounter", 0,0,0);
	G4VPhysicalVolume *physMuonCounter;

	for(int i=0; i<nomucounter; i++)
	{
		G4double phi, x, y, z;
		phi = 360.*deg/nomucounter*i;
		x = muBox_radius*std::sin(phi);
		y = muBox_radius*std::cos(phi);
		z = 0.*cm;
		G4RotationMatrix rm;
		rm.rotateZ(phi);
		physMuonCounter = new G4PVPlacement(G4Transform3D(rm, G4ThreeVector(x,y,z)), logicMuonCounter, "physMuonCounter", logicHall, false, i);
	}

	return physHall;
}
