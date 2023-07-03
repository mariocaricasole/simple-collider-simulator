#ifndef G4_HEPMC3_ASCII_READER_HH
#define G4_HEPMC3_ASCII_READER_HH

#include "G4HepMC3Interface.hh"
#include "G4HepMC3AsciiReaderMessenger.hh"

#include "HepMC3/ReaderAscii.h"

#include <iostream>
#include <fstream>

class G4HepMC3AsciiReader : public G4HepMC3Interface
{
public:
    G4HepMC3AsciiReader();
    ~G4HepMC3AsciiReader();
    
    //(re)initialize ascii reader
    void Initialize();

    //getter and setter of file name
    inline G4String GetFileName() {return fileName; }
    inline void SetFileName(G4String name) {fileName = name; }

private:
    G4String fileName;

    //ascii reader from HepMC3 and custom UI messenger to change file name
    HepMC3::ReaderAscii *asciiInput;
    G4HepMC3AsciiReaderMessenger *messenger;

    //generate HepMC3 event
    virtual HepMC3::GenEvent* GenerateHepMC3Event();
};
#endif
