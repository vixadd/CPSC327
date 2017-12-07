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

// Include static libraries that are developed.
#include "./includes/data_store.h"
#include "./includes/data_store_file.h"
#include "./includes/string_database.h"
#include "./includes/crypto.h"
#include "./includes/crypto_AES.h"
#include "./includes/HexHelper.h"

// TODO - Develop the implmentation
// TODO - Test the libraries here, the prof will use his
//        own test version of this file.


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
	//	std::cout<<"Clearing Cache\n";

	//load it
	myGlobalCache.load(&myDataStore_File1);
	//	std::cout<<"Loading from file "+ MYFILE1 +" \n";

	//save to a different file
	DataStore_File myDataStore_File2(MYFILE2, pCrypto);
	myGlobalCache.save(&myDataStore_File2);
	//	std::cout<<"Saving to file "+ MYFILE2 +" \n";

//	I use my own objects here to compare the files
	return true;
}

// Helper function for adding a string to the global database.
void add_string(std::string str) {
	myGlobalCache.add(str);
}

//
// Comments with a -- are David's
//
int main() {


	//I created and ran a bunch(20) of threads that added different strings to a string_database instance
	int number_of_threads = 4;
	int size = number_of_threads;
	std::thread arrayThreads[number_of_threads];

	// -- Create the number of threads, and add to the global cache.
	while(number_of_threads > 0) {

		std::string str = "thread: " + number_of_threads;

		arrayThreads[number_of_threads-1] = std::thread(add_string, str);
		number_of_threads--;
	}

	//Then I waited for all of them to finish so my program did not crash

	// -- Loop through all of the threads, and join them.
	for(int i = 0; i < size; i++) {
		arrayThreads[i].join();
		// std::cout << "Joining" << std::endl; // -- for debugging
	}

	//Then I went through my string_database instance and made sure that it held the correct data
	// -- We can gdb to confirm this.

	// TODO - Left off here 12/07/2017 at 2:00 AM - Went to bed.

	//then I tested  serialization
	//first without encryption, 
	//testSerialization(NO_ENCRYPT_FILE1, NO_ENCRYPT_FILE2, 0);

	//then with
	//Crypto_AES myCrypto("I Like Rollos   ");
	//testSerialization(ENCRYPT_FILE1, ENCRYPT_FILE2, &myCrypto);
}
