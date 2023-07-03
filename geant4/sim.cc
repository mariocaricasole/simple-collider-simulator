#include <iostream>

#include "G4MTRunManager.hh"
#include "G4UIExecutive.hh"
#include "G4UImanager.hh"
#include "G4VisExecutive.hh"
#include "G4VisManager.hh"

#include "DetectorsConstruction.hh"
#include "PhysicsList.hh"
#include "ActionInitialization.hh"
#include "PrimaryGenerator.hh"

int main(int argc, char** argv)
{
    //define run manager
    G4RunManager *runManager = new G4RunManager();

    /* USER ACTIONS */
    runManager->SetUserInitialization(new DetectorConstruction());
    runManager->SetUserInitialization(new PhysicsList());
    runManager->SetUserInitialization(new ActionInitialization());

    G4UIExecutive *ui = 0;

    if(argc==1)
    {
        ui = new G4UIExecutive(argc, argv);
    }
	
    //visualization manager
    G4VisManager *visManager = new G4VisExecutive();
    visManager->Initialize();

    //user interface manager
    G4UImanager *UImanager = G4UImanager::GetUIpointer();

    //if no argument is passed, use visualization mode, otherwise go to batch mode
    if(ui)
    {
        UImanager->ApplyCommand("/control/execute vis.mac");
        ui->SessionStart();
    }
    else
    {
        G4String command = "/control/execute/ ";
        G4String fileName = argv[1];
        UImanager->ApplyCommand(command+fileName);
    }

    return 0;
}
