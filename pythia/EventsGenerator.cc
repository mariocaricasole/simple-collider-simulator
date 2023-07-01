#include <iostream>

#include "Pythia8/Pythia.h"
#include "Pythia8Plugins/HepMC3.h"
#include "HepMC3/GenEvent.h"
#include "HepMC3/WriterAscii.h"


int main()
{
	//number of events
	int nEvents = 10;
	
	//initialize HepMC conversion interface
	HepMC3::Pythia8ToHepMC3 ToHepMC;
	
	//build pythia object and initialize
	Pythia8::Pythia pythia;
	//define parameters of beams and simulation
	pythia.readString("Beams:idA = 2212");	//proton beam
	pythia.readString("Beams:idB = 2212");	//proton beam
	pythia.readString("Beams:eCM = 14.e3");	//center-of-mass energy of 14 TeV
	//setting on the physics interactions 
	pythia.readString("SoftQCD:all = on");	
	pythia.readString("HardQCD:all = on");
	
	pythia.init();
	
	for(int i =0; i<nEvents; i++)
	{
		if(!pythia.next()) continue;
		//specify file where HepMC events are stored
		HepMC3::WriterAscii ascii_io("event" + std::to_string(i)+".dat");
		HepMC3::GenEvent hepmcevt( HepMC3::Units::GEV, HepMC3::Units::MM );
		ToHepMC.fill_next_event(pythia.event, &hepmcevt);
		
		ascii_io.write_event(hepmcevt);
		ascii_io.close();
		hepmcevt.clear();
	}

	return 0;
}
