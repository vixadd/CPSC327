/*
 * StringParserClass.cpp
 *
 *  Created on: Oct 8, 2017
 *      Author: keith
 */

#include <string>
#include <string.h>

#include "../327_proj3_test/includes/StringParserClass.h"
#include "../327_proj3_test/includes/constants.h"

KP_StringParserClass::StringParserClass::StringParserClass()
:pStartTag(0), pEndTag(0), areTagsSet(false) {}



KP_StringParserClass::StringParserClass::~StringParserClass() {
	cleanup();
}



int KP_StringParserClass::StringParserClass::setTags(const char* pStart, const char* pEnd){

	if(!pStart || !pEnd)
		return ERROR_TAGS_NULL;

	strcpy(pStartTag, pStart);
	strcpy(pEndTag, pEnd);


	if(!pStartTag || !pEndTag) {
		return ERROR_TAGS_NULL;
	} else {
		areTagsSet = true;
	}

	return SUCCESS;
}



int KP_StringParserClass::StringParserClass::getDataBetweenTags(char *pDataToSearchThru,
																std::vector<std::string> & myVector)
{
	if (!pStartTag || !pEndTag) {
		return ERROR_TAGS_NULL;
	}

	if (!pDataToSearchThru) {
		return ERROR_DATA_NULL;
	}

	// TODO - Parse XML

	return SUCCESS;
}

void KP_StringParserClass::StringParserClass::cleanup()
{
	// Do Nothing
}

int KP_StringParserClass::StringParserClass::findTag(char *pTagToLookFor, char *&pStart, char *&pEnd)
{
	return FAIL;
}



