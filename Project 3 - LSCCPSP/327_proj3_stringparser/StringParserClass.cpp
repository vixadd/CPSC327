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

	pStartTag = strdup(pStart);
	pEndTag = strdup(pEnd);


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

	myVector.clear();

	//Initialize pointers
	char *startTagStartPointer;
	char *endTagStartPointer;
	char *startTagEndPointer;
	char *endTagEndPointer;

	// Pointers for the start tag
	startTagStartPointer = &pDataToSearchThru[0];
	endTagStartPointer   = &pDataToSearchThru[0];

	// Pointers for the end tag.
	startTagEndPointer   = &pDataToSearchThru[0];
	endTagEndPointer     = &pDataToSearchThru[0];

	// Find the location of the start and end pointer.
	int mFindStartTag = findTag(pStartTag, startTagStartPointer, endTagStartPointer);
	int mFindEndTag   = findTag(pEndTag, startTagEndPointer, endTagEndPointer);

	// While the start tag and end tag are in the string we're looking into,
	// Then extract data between the tags.
	while(mFindStartTag == SUCCESS && mFindEndTag == SUCCESS) {

		// Initialize the iteration pointer to the character after
		// the '>' in our start tag, and initialize the string to be
		// inserted into the vector to an empty string.
		char *itrPtr = (endTagStartPointer+1);
		std::string insString = "";

		// Extract the given string between the pointer
		// after the end of the start tag, and before
		// the start of the end tag.
		while (itrPtr != startTagEndPointer) {
			insString += *itrPtr;
			itrPtr++;
		}

		// Push the resulting insertion string to the vector.
		myVector.push_back(insString);

		// Reset the pointer to occure after the tag insertion we just completed
		// And rerun the find tags to find a new tag.
		startTagStartPointer = (endTagEndPointer+1);
		endTagStartPointer   = (endTagEndPointer+1);
		startTagEndPointer   = (endTagEndPointer+1);
		endTagEndPointer     = (endTagEndPointer+1);

		// Rerun the start and end tag to find a new tag position
		// from the new starting point.
		mFindStartTag = findTag(pStartTag, startTagStartPointer, endTagStartPointer);
		mFindEndTag   = findTag(pEndTag, startTagEndPointer, endTagEndPointer);
	}

	return SUCCESS;
}

void KP_StringParserClass::StringParserClass::cleanup()
{
	// Do Nothing???
}

int KP_StringParserClass::StringParserClass::findTag(char *pTagToLookFor, char *&pStart, char *&pEnd)
{
	if (!pEnd || !pStart) {
		return FAIL;
	}

	char* mTag = "";

	// Find location of the starttag
	while (pStart != 0) {

		if (*pStart == '<') {

			// Store the start of the pointer temporarily.
			char *& tempStart = pStart;

			// Find the End of the tag.
			while(pStart != 0) {

				// Store the tag contents in mTag
				mTag += *pStart;

				// Increment the startpointer.
				pStart += 1;

				// We have reached the end of the tag.
				if (*pStart == '>') {

					// Set the values of the start and end of the tag itself.
					pStart = tempStart;
					pEnd = pStart;
					break;
				}

			}

			// If the tag we found is equal to the sought after tag
			// Then break the loop. We found the Tag.
			if(mTag == pTagToLookFor)
				break; // We have the start and end pointer of the tag.
			else
				mTag = "";
		}
		pStart += 1;
	}

	if (mTag != "")
		return SUCCESS;
	else
		return FAIL;
}



