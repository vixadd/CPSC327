/*
 * StringParserClass.cpp
 *
 *  Created on: Oct 8, 2017
 *      Author: keith
 */

#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <iterator>
#include <string.h>

#include "../327_proj3_test/includes/StringParserClass.h"

KP_StringParserClass::StringParserClass::StringParserClass() {
	pStartTag 		= '\0';
	pEndTag   		= '\0';
	areTagsSet 		= false;
}



KP_StringParserClass::StringParserClass::~StringParserClass() {
	cleanup();
}



int KP_StringParserClass::StringParserClass::setTags(const char* pStart, const char* pEnd) {


	return 0;
}



int KP_StringParserClass::StringParserClass::getDataBetweenTags(char *pDataToSearchThru,
																std::vector<std::string> & myVector)
{

	return 0;
}

