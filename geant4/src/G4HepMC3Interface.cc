#include "G4HepMC3Interface.hh"

G4HepMC3Interface::G4HepMC3Interface()
{
	hepmc3Event = 0;
}


G4HepMC3Interface::~G4HepMC3Interface()
{
    delete hepmc3Event;
}


G4bool G4HepMC3Interface::CheckVertexInsideWorld(const G4ThreeVector &pos) const
{
    //get the solid world volume and check if the pos argument is inside it
    G4Navigator *navigator = G4TransportationManager::GetTransportationManager()->GetNavigatorForTracking();

    G4VPhysicalVolume *world = navigator->GetWorldVolume();
    G4VSolid *solid = world->GetLogicalVolume()->GetSolid();
    EInside qinside = solid->Inside(pos);

    if(qinside!=kInside)    return false;
    else    return true;
}


void G4HepMC3Interface::HepMC3ToG4(const HepMC3::GenEvent* hepmc3Event, G4Event *g4event)
{
    //loop over all vertices
    for(auto vitr : hepmc3Event->vertices())
    {
        //Check if it's a real vertex
        G4bool qvtx=false;
        for(auto pitr : vitr->particles_out())
            {
                if(!pitr->end_vertex() && pitr->status()==1)
                {
                    qvtx=true;
                    break;
                }
            }

        if(!qvtx)   continue;

        //check if the vertex is inside the world volume
        HepMC3::FourVector pos = vitr->position();
        G4LorentzVector xvtx(pos.x(), pos.y(), pos.z(), pos.t());
        if(!CheckVertexInsideWorld(xvtx.vect()*mm)) continue;

        //if it is, then generate primary vertex object
        G4PrimaryVertex *g4vtx = new G4PrimaryVertex(xvtx.x()*mm, xvtx.y()*mm, xvtx.z()*mm, xvtx.t()*mm/c_light);

        //loop over all particles and output as a primary particles
        for(auto vpitr : vitr->particles_out())
        {
            if(vpitr->status() != 1) continue;

            G4int pdgCode = vpitr->pdg_id();
            pos = vpitr->momentum();
            G4LorentzVector p(pos.px(), pos.py(), pos.pz(), pos.e());
            G4PrimaryParticle *g4prim = new G4PrimaryParticle(pdgCode, p.x()*GeV, p.y()*GeV, p.z()*GeV);

            g4vtx->SetPrimary(g4prim);
        }
        //add to the G4Event the primary vertex
        g4event->AddPrimaryVertex(g4vtx);
    }
}


//generic method, will be overwritten in G4HepMC3AsciiReader class to actually take the next event in the file
HepMC3::GenEvent *G4HepMC3Interface::GenerateHepMC3Event()
{
    HepMC3::GenEvent *aEvent = new HepMC3::GenEvent();
    return aEvent;
}


void G4HepMC3Interface::GeneratePrimaryVertex(G4Event *anEvent)
{
    //delete last HepMC3 event and generate a new event
    delete hepmc3Event;
    hepmc3Event = GenerateHepMC3Event();

    if(! hepmc3Event)
    {
        G4cout << "HepMC3Intnterface: no generated particles, run terminated..." << G4endl;
        G4RunManager::GetRunManager()->AbortRun();
        return;
    }
    //convert the new event into a G4Event
    HepMC3ToG4(hepmc3Event, anEvent);
}
