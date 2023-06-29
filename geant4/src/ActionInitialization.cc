#include "ActionInitialization.hh"

//constructor
ActionInitialization::ActionInitialization() 
{}

//destructor
ActionInitialization::~ActionInitialization()
{}

//build
void ActionInitialization::Build() const
{
	PrimaryGeneratorAction *generator = new PrimaryGeneratorAction();
	SetUserAction(generator);
}
