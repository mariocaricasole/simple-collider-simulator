#include "PrimaryGenerator.hh"

PrimaryGeneratorAction::PrimaryGeneratorAction()
{
	//primary generator creates initial particles and vertexes as instructed from Ascii file reader
	asciiInput = new G4HepMC3AsciiReader();
}

PrimaryGeneratorAction::~PrimaryGeneratorAction(){
	delete asciiInput;
}

void PrimaryGeneratorAction::GeneratePrimaries(G4Event *anEvent)
{
	//before generating primaries, initialize the ascii input reader (be sure to update the file name)
	asciiInput->Initialize();
	asciiInput->GeneratePrimaryVertex(anEvent);
}
