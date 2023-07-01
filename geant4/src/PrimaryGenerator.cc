#include "PrimaryGenerator.hh"

PrimaryGeneratorAction::PrimaryGeneratorAction()
{
	//build particle gun, single shot
	asciiInput = new G4HepMC3AsciiReader();
}

PrimaryGeneratorAction::~PrimaryGeneratorAction(){
	delete asciiInput;
}

void PrimaryGeneratorAction::GeneratePrimaries(G4Event *anEvent)
{
	asciiInput->GeneratePrimaryVertex(anEvent);
}
