#ifndef G4_HEPMC3_ASCII_READER_MESSENGER_HH
#define G4_HEPMC3_ASCII_READER_MESSENGER_HH

#include "G4UImessenger.hh"
#include "G4UIcmdWithAString.hh"
#include "G4UIdirectory.hh"

//dummy declaration, overwritten by actual class
class G4HepMC3AsciiReader;

class G4HepMC3AsciiReaderMessenger : public G4UImessenger
{
public:
    G4HepMC3AsciiReaderMessenger(G4HepMC3AsciiReader *fread);
    ~G4HepMC3AsciiReaderMessenger();

    //setter and getter
    void SetNewValue(G4UIcommand *command, G4String newValues);
    G4String GetCurrentValue(G4UIcommand *command);

private:
    //customized ascii reader
    G4HepMC3AsciiReader *fReader;

    //directory and "open" command
    G4UIdirectory *readerDir;
    G4UIcmdWithAString *open;
};

#endif
