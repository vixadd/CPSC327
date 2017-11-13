/*
 * Functions.h
 *
 *  Created on: Nov 5, 2017
 *      Author: keith
 */

#ifndef FUNCTIONS_H_
#define FUNCTIONS_H_
#include <memory>
#include <vector>
#include <time.h>
//for delays
#include <chrono>
#include <thread>
#include "Smalltalk.h"


//create a vector with brit(),american(), and donut enthusiest() using unique pointers.  Since we are
//using c++11 returning by value is fine since the compiler will move the vector on return 
//rather than recreate it (this means there is no copy penalty)
std::vector<std::unique_ptr<Smalltalk>> getPeople(int numBrit = 1,
		int numAmerican = 1, int numbAmericanDonutEnthusiest = 1,
		int numWatches = 0);

#endif /* FUNCTIONS_H_ */
