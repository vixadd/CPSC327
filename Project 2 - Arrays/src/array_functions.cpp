/*
 * functionstocomplete.cpp
 *
 *  Created on: Sep 10, 2017
 *      Author: davidkroell
 */


#include "array_functions.h"
#include "utilities.h"

using namespace std;

/*
 * Data needed for the computations
 */
struct Word {
	string word;
	int count;
};

Word* wordPointer = new Word[0];
int nextAvailableSlot = 0;
int size_of_array = 0;

/*
 * Data gathering Methods for functions.
 */
void clearArray() {
	Word* newArr = new Word[0];
	delete[] wordPointer;
	wordPointer = newArr;

	size_of_array = 0;
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

	// Check if word is already in the Array.
	for(int i = 0; i < size_of_array; i++) {
		if(wordPointer[i].word == token)
		{
			wordPointer[i].count += 1;

			return;
		}
	}


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


	return false;
}

void closeFile(std::fstream& myfile) {

}

int writeArraytoFile(const std::string &outputfilename) {

	return 0;
}

void sortArray(constants::sortOrder so) {

}





