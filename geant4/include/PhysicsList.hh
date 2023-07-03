#ifndef PHYSICS_HH
#define PHYSICS_HH

#include "FTFP_BERT.hh"

//using FTFP_BERT physics list as a base class
class PhysicsList : public FTFP_BERT
{
public:
	PhysicsList();
	~PhysicsList();
};

#endif
