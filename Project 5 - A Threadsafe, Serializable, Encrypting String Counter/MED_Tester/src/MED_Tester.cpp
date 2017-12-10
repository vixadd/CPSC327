//============================================================================
// Name        : MED_Tester.cpp
// Author      : David Kroell
// Version     : 12/07/2017
// Copyright   :
// Description : MED Tester for the thread safe libraries.
//============================================================================


#include <iostream>       // std::cout
#include <thread>         // std::thread
#include <sstream>
#include <fstream>

// Include static libraries that are developed.
#include "./includes/data_store.h"
#include "./includes/data_store_file.h"
#include "./includes/string_database.h"
#include "./includes/crypto.h"
#include "./includes/crypto_AES.h"
#include "./includes/HexHelper.h"


//I've provided some hints in the form of comments and commented out code
//use them if you wish

//global database object
String_Database myGlobalCache;

bool testSerialization(const std::string &MYFILE1, const std::string &MYFILE2,
		Crypto *pCrypto) {

	DataStore_File myDataStore_File1(MYFILE1, pCrypto);
	myGlobalCache.save(&myDataStore_File1);

	//clear cache
	myGlobalCache.clear();
	std::cout<<"Clearing Cache\n";

	//load it
	myGlobalCache.load(&myDataStore_File1);
	std::cout<<"Loading from file "+ MYFILE1 +" \n";

	//save to a different file
	DataStore_File myDataStore_File2(MYFILE2, pCrypto);
	myGlobalCache.save(&myDataStore_File2);
	std::cout<<"Saving to file "+ MYFILE2 +" \n";

//	I use my own objects here to compare the files
// ++ So do I!
	std::fstream myFile1(MYFILE1, ios::in);
	std::fstream myFile2(MYFILE2, ios::in);
	std::string str1;
	std::string str2;
	int lineCount = 0;

	bool allGood = true;

	if(myFile1.is_open() && myFile2.is_open()){
		while(std::getline(myFile1, str1)){
			if(std::getline(myFile2, str2)){
				lineCount++;
				if(!str1.compare(str2)){
					// They're the same!
					std::cout << "All good so far... Line " << lineCount << " is equal!" << std::endl;
				}
				else{
					std::cout << "Uh oh! The files are not the same!" << std::endl;
					allGood = false;
				}
			}
			else{
				std::cout << "The files are different lengths!"
						<< MYFILE1 << " is longer than " << MYFILE2 << std::endl;
				allGood = false;
			}
		}

		if(getline(myFile2, str2)){
			std::cout << "The files are different lengths!"
					<< MYFILE2 << " is longer than " << MYFILE1 << std::endl;
		}

		myFile1.close();
		myFile2.close();
	}


	return allGood;
}

// Helper function for adding a string to the global database.
void add_string(std::string str) {
	myGlobalCache.add(str);
}

//
// Comments with a -- are David's
// Comments with a ++ are Jonah's
//
int main() {


	//I created and ran a bunch(20) of threads that added different strings to a string_database instance
	int number_of_threads = 20;
	int size = number_of_threads;
	std::thread arrayThreads[number_of_threads];

	std::vector<std::string> stringsAdded; // ++ For hanging onto the strings we add to the Global Cache.

	// -- Create the number of threads, and add to the global cache.
	while(number_of_threads > 0) {

		std::string str = "thread: " + std::to_string(number_of_threads); // ++ Turns out, if you do `str = "some string" + some_int, it'll increment the pointer by some_int.
		std::cout << str << std::endl;


		arrayThreads[number_of_threads-1] = std::thread(add_string, str);
		stringsAdded.push_back(str); // ++ Also add the string to our local vector so we can compare later.
		number_of_threads--;
	}

	//Then I waited for all of them to finish so my program did not crash

	// -- Loop through all of the threads, and join them.
	for(int i = 0; i < size; i++) {
		arrayThreads[i].join();
		std::cout << "Joining thread: " << i << std::endl; // -- for debugging
	}

	//Then I went through my string_database instance and made sure that it held the correct data


	std::vector<std::string>::iterator stringsAddedIterator; // ++ STL ftw!

	// ++ This basically just checks to make sure the strings were added to the Global Cache the correct number of times.
	for(stringsAddedIterator = stringsAdded.begin();
	        stringsAddedIterator != stringsAdded.end();
	        stringsAddedIterator++){
		if(myGlobalCache.getCount(*stringsAddedIterator) != 1){
			std::cout << "Something went wrong with adding strings to the global cache!" << std::endl;
		}
		else{
			std::cout << "The string '" << *stringsAddedIterator <<
					"' was successfully added to the global cache." << std::endl;
		}
	}


	//then I tested  serialization
	//first without encryption, 
	if(testSerialization("helloInput.txt", "helloOutput.txt", NULL)){
		std::cout << "Serialization test without encryption ran successfully." << std::endl;
	}
	else{
		std::cout << "Serialization test without encryption was unsuccessful!" << std::endl;
	}

	//then with
	Crypto_AES myCrypto("I Like Rollos   ");
	if(testSerialization("helloInputEncrypt.txt", "helloOutputEncrypt.txt", &myCrypto)){
		std::cout << "Serialization test with encryption ran successfully." << std::endl;
	}
	else{
		std::cout << "Serialization test with encryption was unsuccessful!" << std::endl;
	}
}
