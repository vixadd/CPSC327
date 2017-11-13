/*
 * Smalltalk_American.cpp
 *
 *	Implementation for the Smalltalk
 *	American source as described in
 *	the given skeleton.
 *
 *	       See: ../includes/Smalltalk_American.h
 *  Created on: Nov 11, 2017
 *      Author: davidkroell
 */

#include <iostream>
#include <string>

#include "./includes/Smalltalk_American.h"

Smalltalk_American::Smalltalk_American(int iPerson)
:Smalltalk("American", iPerson)
{

}

Smalltalk_American::Smalltalk_American(std::string myNationality, int iPerson)
:Smalltalk(myNationality, iPerson)
{

}

Smalltalk_American::~Smalltalk_American(void) {

}

void Smalltalk_American::populatePhrases() {

}




