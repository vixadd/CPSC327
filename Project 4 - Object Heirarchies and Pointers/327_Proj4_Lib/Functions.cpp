/*
 * Functions.cpp
 *
 *  Created on: Nov 5, 2017
 *      Author: keith
 */
#include <iostream>

#include "./includes/Functions.h"
#include "./includes/Smalltalk_American.h"
#include "./includes/ST_American_DonutEnthusiest.h"
#include "./includes/Smalltalk_Brit.h"
#include "./includes/Watch.h"
#include "./includes/constants.h"

//create a vector with a brit,american, donut enthusiest using unique pointers
//use c++11 and then returning by value is fine since the compiler will move the vector
//on return rather than recreate it(if using C++11).
std::vector<std::unique_ptr<Smalltalk>> getPeople(int numBrit,
		int numAmerican, int numbAmericanDonutEnthusiest,
		int numWatches) {
	
	//create a vector to hold SmallTalk unique pointers
	std::vector<std::unique_ptr<Smalltalk>> smalltalkVect;

	//add British people to vector
	for(int cnt =0; cnt < numBrit; cnt++) {
		smalltalkVect.push_back(std::move(std::unique_ptr<Smalltalk>(new Smalltalk_Brit(cnt))));
	}

	//add Americans to vector
	for(int cnt = 0; cnt < numAmerican; cnt++) {
		smalltalkVect.push_back(std::move(std::unique_ptr<Smalltalk>(new Smalltalk_American(cnt))));
	}

	//add american_donut_enthusiest  to vector
	for(int cnt = 0; cnt < numbAmericanDonutEnthusiest; cnt++) {
		smalltalkVect.push_back(std::move(std::unique_ptr<Smalltalk>(new ST_American_DonutEnthusiest(cnt))));
	}

	//create some watches (as long as number watches <= numb people)
	//then give the watches away to first NUM_WATCHES people in the vector
	//keep in mind that you are responsible for deleting any pointers to
	//watches allocated on the heap when you are finished using the vector you return
	//from this function(see Smalltalk header for hints)

	int arr_size = smalltalkVect.size();
	for(int i = 0; i < arr_size; i++) {
		if(numWatches == 0) break;
		Watch* thisWatch = new Watch();
		smalltalkVect.at(i)->giveWatch(thisWatch);

		thisWatch = NULL;
		numWatches--;
	}

	//return your vector
	return smalltalkVect;
}
