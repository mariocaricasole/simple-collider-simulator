#include "G4HepMC3AsciiReader.hh"

G4HepMC3AsciiReader::G4HepMC3AsciiReader()
{
    fileName = "event0.dat";
    verbose = 0;

    asciiInput = new HepMC3::ReaderAscii(fileName);
}

G4HepMC3AsciiReader::~G4HepMC3AsciiReader()
{
    delete asciiInput;
}

void G4HepMC3AsciiReader::Initialize()
{
    delete asciiInput;

    asciiInput = new HepMC3::ReaderAscii(fileName);
}

HepMC3::GenEvent *G4HepMC3AsciiReader::GenerateHepMC3Event()
{
    HepMC3::GenEvent *evt = new HepMC3::GenEvent();
    asciiInput->read_event((*evt));
    if(!(evt))    return 0;

    return evt;
}
