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

#include "./includes/constants.h"
#include "./includes/Smalltalk_American.h"

Smalltalk_American::Smalltalk_American(int iPerson)
:Smalltalk_American(AMERICAN, iPerson)
{
	populatePhrases();
}

Smalltalk_American::Smalltalk_American(std::string myNationality, int iPerson)
:Smalltalk(myNationality, iPerson)
{
	// Set random phrase for the current phrases.
	this->current_phrase = rand() % 5 + 1;
}

/*
 * @see ~Smalltalk()
 */
Smalltalk_American::~Smalltalk_American(void) {}

void Smalltalk_American::populatePhrases() {

	mySmallTalk.push_back(AMERICAN_PHRASE_1);
	mySmallTalk.push_back(AMERICAN_PHRASE_2);
	mySmallTalk.push_back(AMERICAN_PHRASE_3);
	mySmallTalk.push_back(AMERICAN_PHRASE_4);
	mySmallTalk.push_back(AMERICAN_PHRASE_5);

}
