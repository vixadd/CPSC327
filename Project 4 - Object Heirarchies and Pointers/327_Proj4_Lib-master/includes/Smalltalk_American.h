#pragma once
#include <vector>
#include "Smalltalk.h"

class Smalltalk_American :
	public Smalltalk
{
public:
	//use base class call to set Nationality (See constants for Nationality strings)
	Smalltalk_American(int iPerson =1);
	Smalltalk_American(std::string myNationality,int iPerson =1);
	~Smalltalk_American(void);
	virtual void populatePhrases();
};

