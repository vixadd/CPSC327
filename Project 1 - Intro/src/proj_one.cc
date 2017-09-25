/*
 * proj_one.cc
 *
 * 	This is the implementation of the
 * 	interface displayed in the
 * 	proj_one.hh header file.
 *
 *  Created on: Sep 8, 2017
 *      Author: davidkroell
 */

#include "proj_one.hh"
#include <iostream>

proj::proj(int pI, char * pStr) {
	i = pI;
	str =  pStr;
}

proj::~proj() {}; // Destructor is empty.

char* proj::getString() {
	return str;
}

int proj::getInteger() {
	return i;
}

int* proj::showReferenceOfI() {
	return &i;
}



