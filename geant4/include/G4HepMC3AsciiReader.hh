#ifndef G4_HEPMC3_ASCII_READER_HH
#define G4_HEPMC3_ASCII_READER_HH

#include "G4HepMC3Interface.hh"
#include "HepMC3/ReaderAscii.h"
#include <iostream>
#include <fstream>

class G4HepMC3AsciiReader : public G4HepMC3Interface
{
public:
    G4HepMC3AsciiReader();
    ~G4HepMC3AsciiReader();

    void SetFileName(G4String name);
    G4String GetFileName() const;

    void SetVerboseLevel(G4int i);
    G4int GetVerboseLevel() const;

    void Initialize();

private:
    G4String fileName;
    HepMC3::ReaderAscii *asciiInput;

    G4int verbose;

    virtual HepMC3::GenEvent* GenerateHepMC3Event();

};


#endif
