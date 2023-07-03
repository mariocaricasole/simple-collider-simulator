#ifndef G4_HEPMC3_INTERFACE_HH
#define G4_HEPMC3_INTERFACE_HH

#include "G4VPrimaryGenerator.hh"
#include "G4RunManager.hh"
#include "G4LorentzVector.hh"
#include "G4Event.hh"
#include "G4PrimaryParticle.hh"
#include "G4PrimaryVertex.hh"
#include "G4TransportationManager.hh"
#include "G4PhysicalConstants.hh"
#include "G4SystemOfUnits.hh"
#include "G4Types.hh"

#include "HepMC3/GenEvent.h"
#include "HepMC3/GenVertex.h"
#include "HepMC3/GenParticle.h"

class G4HepMC3Interface : public G4VPrimaryGenerator
{
public:
    //constructor/destructor
    G4HepMC3Interface();
    ~G4HepMC3Interface();

    //get method
    HepMC3::GenEvent *GetHepMC3GenEvent() const {return hepmc3Event;}

    //generate primary vertexes routine
    virtual void GeneratePrimaryVertex(G4Event *anEvent);

private:
    //current HepMC3 event
    HepMC3::GenEvent *hepmc3Event;

    //check if a vertex is inside the world volume
    virtual G4bool CheckVertexInsideWorld(const G4ThreeVector &pos) const;

    //conversion routine from HepMC3 event to Geant4 event
    void HepMC3ToG4(const HepMC3::GenEvent *hepmc3evt, G4Event *g4event);

    //generate HepMC3 event
    virtual HepMC3::GenEvent* GenerateHepMC3Event();
};
#endif
