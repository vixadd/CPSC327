/*
 * Functions.cpp
 *
 *  Created on: Nov 5, 2017
 *      Author: keith
 */

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

	//add brits to vector
	for(int cnt =0; cnt < numBrit; cnt++) {
		//Smalltalk_Brit sbTemp = Smalltalk_Brit(cnt);
		std::unique_ptr<Smalltalk> ptrTemp(new Smalltalk_Brit(cnt));
		smalltalkVect.push_back(std::move(ptrTemp));
	}

	//add americans  to vector
	for(int cnt = 0; cnt < numAmerican; cnt++) {
		std::unique_ptr<Smalltalk> ptrTemp(new Smalltalk_American(cnt));
		smalltalkVect.push_back(std::move(ptrTemp));
	}

	//add american donut enthusiest  to vector
	for(int cnt = 0; cnt < numbAmericanDonutEnthusiest; cnt++) {
		std::unique_ptr<Smalltalk> ptrTemp(new ST_American_DonutEnthusiest(cnt));
		smalltalkVect.push_back(std::move(ptrTemp));
	}

	//create some watches (as long as number watches <= numb people)	
	//then give the watches away to first NUM_WATCHES people in the vector
	//keep in mind that you are responsible for deleting any pointers to 
	//watches allocated on the heap when you are finished using the vector you return 
	//from this function(see Smalltalk header for hints)

	for( auto& p : smalltalkVect) {
		if(numWatches == 0) break;

		p->giveWatch(new Watch());

		numWatches--;
	}

	//return your vector
	return smalltalkVect;
}
