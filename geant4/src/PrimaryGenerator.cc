#include "PrimaryGenerator.hh"

PrimaryGeneratorAction::PrimaryGeneratorAction()
{
	//build particle gun, single shot
	fParticleGun = new G4ParticleGun(1);
}

PrimaryGeneratorAction::~PrimaryGeneratorAction(){
	delete fParticleGun;
}

void PrimaryGeneratorAction::GeneratePrimaries(G4Event *anEvent)
{
	G4ParticleTable *particleTable = G4ParticleTable::GetParticleTable();
	G4ParticleDefinition *particle = particleTable->FindParticle("proton");

	G4ThreeVector pos(0., 0., 0.);
	G4ThreeVector mom(0., 1., 0.);

	fParticleGun->SetParticleDefinition(particle);
	fParticleGun->SetParticlePosition(pos);
	fParticleGun->SetParticleMomentumDirection(mom);
	fParticleGun->SetParticleMomentum(100*GeV);

	fParticleGun->GeneratePrimaryVertex(anEvent);
}
