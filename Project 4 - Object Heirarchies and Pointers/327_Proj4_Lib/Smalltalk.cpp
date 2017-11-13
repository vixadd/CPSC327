/*
 * Smalltalk.cpp
 *
 *  Created on: Nov 11, 2017
 *      Author: silver
 */

#include <iostream>
#include <vector>

#include "./includes/Smalltalk.h"

Smalltalk::Smalltalk(std::string myNationality, int pPerson)
:nationality(myNationality),
 pWatch(0),
 iPerson(pPerson),
 current_phrase(0)
{

}

Smalltalk::~Smalltalk() {

}

std::string Smalltalk::getTime() {
	return "";
}

std::string Smalltalk::saySomething() {
	return "";
}

Watch* Smalltalk::takeWatch() {
	return new Watch();
}

bool Smalltalk::giveWatch(Watch *pWatch) {
	return false;
}




