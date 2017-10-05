/*
 * functionstocomplete.cpp
 *
 *  Created on: Sep 10, 2017
 *      Author: davidkroell
 */

#include <locale>

#include "array_functions.h"
#include "utilities.h"
#include "constants.h"


using namespace std;
using namespace constants;

/*
 * Data needed for the computations
 */
struct Word {
	string word;
	int count;
};

Word* wordPointer = new Word[0];
fstream filePointer;

bool open = false;
int nextAvailableSlot = 0;
int size_of_array = 0;

string toLower(string myString);

/*
 * Data gathering Methods for functions.
 */
void clearArray() {
	Word* newArr = new Word[0];
	delete[] wordPointer;
	wordPointer = newArr;

	size_of_array = 0;
	nextAvailableSlot = 0;
}

int getArraySize() {
	return nextAvailableSlot;
}

string getArrayWordAt(int i) { return wordPointer[i].word; }

int getArrayWord_NumbOccur_At(int i) { return wordPointer[i].count; }

/*
 * ========================================
 * 				Main Functions
 * ========================================
 */

bool processFile(fstream &myfstream) {

	if (myfstream.is_open()){

		string line;
		while(getline(myfstream, line)) {
			processLine(line);
		}
		return true;

	} else return false;
}

void processLine(string &myString) {

	istringstream stream(myString);
	string word;
	while(stream >> word)
	{
		processToken(word);
	}
}

void processToken(string &token) {

	strip_unwanted_chars(token);

	if(token == "")
		return;

	string tempToken = token;
	for (int i = 0; token[i]; i++) token[i] = tolower(token[i]);

	// Check if word is already in the Array.
	for(int i = 0; i < size_of_array; i++) {

		string arrayWord = getArrayWordAt(i);

		for (int j = 0; arrayWord[j]; j++) arrayWord[j] = tolower(arrayWord[j]);

		if(arrayWord == token)
		{
			wordPointer[i].count += 1;

			return;
		}
	}

	// We didn't find any similarities, so lets get our old token back.
	token = tempToken;

	// Get old and new sizes for the arrays
	int old_array_size = size_of_array;
	int new_array_size = size_of_array + 10;

	// Check if the array is full. If so, extend the array for wordPointer.
	if(nextAvailableSlot == size_of_array - 1 || nextAvailableSlot == 0)
	{
		Word* newArr = new Word[new_array_size];
		std::copy(wordPointer, wordPointer + std::min(old_array_size, new_array_size), newArr);
		delete[] wordPointer;
		wordPointer = newArr;

		size_of_array = new_array_size;
	}

	Word entry;
	entry.word = token;
	entry.count = 1;

	// Populate the next slot with the pointer.
	wordPointer[nextAvailableSlot] = entry;

	// Increment next available slot for the next new insertion.
	nextAvailableSlot++;
}

bool openFile(fstream& myfile, const string& myFileName, ios_base::openmode mode) {

	myfile.open(myFileName.c_str(), mode);



	return myfile.is_open();
}

void closeFile(std::fstream& myfile) {
	if(!myfile.is_open()) {
		myfile.close();
	}
}

int writeArraytoFile(const std::string &outputfilename) {

	if(getArraySize() == 0) {
		return FAIL_NO_ARRAY_DATA;
	}

	ofstream mFile;
	mFile.open(outputfilename.c_str());

	if(mFile.is_open()) {

		for(int i = 0; i < getArraySize(); i++) {
			mFile << wordPointer[i].word << " " << wordPointer[i].count << endl;
		}

		return SUCCESS;
	} else {
		return FAIL_FILE_DID_NOT_OPEN;
	}

	return FAIL;
}

void sortArray(constants::sortOrder so) {

	switch( so ) {
	case NONE:     // --> None is invoked. Leave the Array untouched.

		return;
	case ASCENDING:                   // --> sort alphabetically in ascending order.

		for( int i = 1; i < getArraySize(); i++) {

			int j = i;
			while(toLower(wordPointer[j].word) < toLower(wordPointer[j-1].word)) {

				Word temp = wordPointer[j];
				wordPointer[j] = wordPointer[j-1];
				wordPointer[j-1] = temp;

				if(j == 1) {
					break;
				} else {
					j--;
				}
			}
		}



		return;
	case DESCENDING:           // --> sort alphabetically in descending order.

		for( int i = 0; i < getArraySize()-1; i++) {

			int j = i;
			while(toLower(wordPointer[j].word) > toLower(wordPointer[j+1].word)) {

				Word temp = wordPointer[j];
				wordPointer[j] = wordPointer[j+1];
				wordPointer[j+1] = temp;

				if(j == 1) {
					break;
				} else {
					j--;
				}
			}
		}
		return;
	case NUMBER_OCCURRENCES:           // --> Sort by number of occurrences in array.
		for( int i = 1; i < getArraySize(); i++) {

			int j = i;
			while(wordPointer[j].count < wordPointer[j-1].count) {

				Word temp = wordPointer[j];
				wordPointer[j] = wordPointer[j-1];
				wordPointer[j-1] = temp;

				if(j == 1) {
					break;
				} else {
					j--;
				}

			}
		}
		return;
	}
}

string toLower(string myString) {
	for (int i = 0; myString[i]; i++) myString[i] = tolower(myString[i]);

	return myString;
}





