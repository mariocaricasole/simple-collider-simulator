#include "G4HepMC3AsciiReader.hh"

G4HepMC3AsciiReader::G4HepMC3AsciiReader()
{
    //define new HepMC3 ascii reader and UI messenger
    asciiInput = new HepMC3::ReaderAscii(fileName);
    messenger = new G4HepMC3AsciiReaderMessenger(this);
}


G4HepMC3AsciiReader::~G4HepMC3AsciiReader()
{
    delete asciiInput;
    delete messenger;
}


//delete old HepMC3 ascii reader and create a new one with the current filename
void G4HepMC3AsciiReader::Initialize()
{
    delete asciiInput;
    asciiInput = new HepMC3::ReaderAscii(fileName);
}


//generate new HepMC3Event from the file, reading the next event (if present)
HepMC3::GenEvent *G4HepMC3AsciiReader::GenerateHepMC3Event()
{
    HepMC3::GenEvent *evt = new HepMC3::GenEvent();
    asciiInput->read_event((*evt));
    if(!(evt))    return 0;

    return evt;
}
