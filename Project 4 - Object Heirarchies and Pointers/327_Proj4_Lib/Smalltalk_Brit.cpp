/*
 * Smalltalk_Brit.cpp
 *
 *  Created on: Nov 11, 2017
 *      Author: silver
 */

#include <iostream>

#include "./includes/constants.h"
#include "./includes/Smalltalk_Brit.h"

Smalltalk_Brit::Smalltalk_Brit(int iPerson)
:Smalltalk(BRIT, iPerson)
{
	populatePhrases();
}

/*
 * @see ~Smalltalk()
 */
Smalltalk_Brit::~Smalltalk_Brit() {}

void Smalltalk_Brit::populatePhrases() {
	mySmallTalk.push_back(BRIT_1);
	mySmallTalk.push_back(BRIT_2);
	mySmallTalk.push_back(BRIT_3);
	mySmallTalk.push_back(BRIT_4);
	mySmallTalk.push_back(BRIT_5);
	mySmallTalk.push_back(BRIT_6);
	mySmallTalk.push_back(BRIT_7);

}
