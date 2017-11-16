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
 current_phrase(0)
{

}

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
//	for ( std::vector<std::string>::iterator it = mySmallTalk.begin(); it != mySmallTalk.end(); it++) {
//			mySmallTalk.erase(it);
//	}

//	mySmallTalk.clear();   // TODO - This section is broken.

	if( pWatch != 0 ) {
		delete pWatch;
	}
}


std::string Smalltalk::getTime() {
	std::string out = "";
	out += nationality;
	out += " ";
	out += iPerson + ":";

	if(pWatch == 0) {
		return out + I_DO_NOT_HAVE_A_WATCH;
	}

	out += pWatch->getTime();

	return out;

	return "";
}


std::string Smalltalk::saySomething() {

	if(mySmallTalk.empty())
		return "VECTOR IS EMPTY NOTHING RETURNED.";

	std::string out = "";
	int size = mySmallTalk.size();

	out += nationality;
	out += " ";
	out += this->iPerson + ":";

	if(current_phrase > size-1) return "INDEX_OUT_OF_BOUNDS_FOR_mySmallTalk_Error";

	out += mySmallTalk.at(current_phrase);

	return out;

	return "";
}

Watch* Smalltalk::takeWatch() {
	if(pWatch == 0) {
		std::cout << I_DO_NOT_HAVE_A_WATCH;
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




