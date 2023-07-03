#ifndef GENERATOR_HH
#define GENERATOR_HH

#include "G4VUserPrimaryGeneratorAction.hh"
#include "G4HepMC3AsciiReader.hh"
#include "G4HepMC3Interface.hh"
#include "G4SystemOfUnits.hh"
#include "G4ParticleTable.hh"

class PrimaryGeneratorAction : public G4VUserPrimaryGeneratorAction
{
public:
	PrimaryGeneratorAction();
	~PrimaryGeneratorAction();

	//generate primary vertexes routine
	virtual void GeneratePrimaries(G4Event*);

private:
	//HepMC3 ascii file reader
	G4HepMC3AsciiReader *asciiInput;
};

#endif
