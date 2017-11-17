/*
 * Smalltalk.cpp
 *
 *  Created on: Nov 11, 2017
 *      Author: silver
 */

#include <iostream>
#include <vector>


#include "./includes/constants.h"
#include "./includes/Smalltalk.h"

Smalltalk::Smalltalk(std::string myNationality, int pPerson)
:nationality(myNationality),
 pWatch(0),
 iPerson(pPerson),
 current_phrase(1)
{ }

/*
"You can't have a pure virtual destructor without a body.
Just give it an empty body in the inheriting classes.
With a regular pure virtual method, the overriding function
is called instead, with destructors, they are all called,
so you have to provide a body. The =0 just means that it must
be overridden, so still a useful construct if you need it."

(Bjarne Stroustrup, The C++ Programming Language, Oct. 1985)

Hence, no need to implement destructor in any of the base classes.
*/

Smalltalk::~Smalltalk() {

	if( pWatch != 0 ) {
		delete pWatch;
	}

}


std::string Smalltalk::getTime() {

	if(pWatch == 0) {
		return nationality + " " + std::to_string(this->iPerson) + ":" + I_DO_NOT_HAVE_A_WATCH;
	}

	return nationality + " " + std::to_string(this->iPerson) + ":" + this->pWatch->getTime();
}


std::string Smalltalk::saySomething() {

	if(mySmallTalk.empty())
		return "VECTOR IS EMPTY NOTHING RETURNED.";

	std::string phrase = "";

	for(unsigned int idx = 1; idx <= this->mySmallTalk.size(); idx++) {
		if(idx == this->current_phrase) {
			phrase = mySmallTalk.at(idx-1);
		}
	}

	return nationality + " " + std::to_string(this->iPerson) + ":" + phrase;
}

Watch* Smalltalk::takeWatch() {
	if(pWatch == 0) {
		return 0;
	}

	Watch *shallowCopy = pWatch;

	pWatch = 0;

	return shallowCopy;
}

bool Smalltalk::giveWatch(Watch *iWatch) {
	if(iWatch == 0) {
		return false;
	}

	pWatch = iWatch;
	return true;
}




