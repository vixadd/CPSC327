/*
 * ST_American_DonutEnthusiest.cpp
 *
 *  Created on: Nov 11, 2017
 *      Author: silver
 */

#include <iostream>

#include "./includes/constants.h"
#include "./includes/ST_American_DonutEnthusiest.h"

ST_American_DonutEnthusiest::ST_American_DonutEnthusiest(int iPerson)
:Smalltalk_American(AMERICAN_DE, iPerson)
{
	populatePhrases();

	// Set random phrase for the current phrases.
	this->current_phrase = rand() % 5 + 1;
}

/*
 * @see ~Smalltalk()
 */
ST_American_DonutEnthusiest::~ST_American_DonutEnthusiest() {}

void ST_American_DonutEnthusiest::populatePhrases() {
	this->mySmallTalk.push_back(AMERICAN_DE_PHRASE_1);
	this->mySmallTalk.push_back(AMERICAN_DE_PHRASE_2);
	this->mySmallTalk.push_back(AMERICAN_DE_PHRASE_3);
	this->mySmallTalk.push_back(AMERICAN_DE_PHRASE_4);
	this->mySmallTalk.push_back(AMERICAN_DE_PHRASE_5);
}



