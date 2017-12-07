/*
 * Data Storage implementation for Project 5
 * This is the implmentation of the class.
 *
 * 		Author: David Kroell
 * 		Version: 11/28/2017
 */

#include "../includes/data_store.h"


DataStore::DataStore(Crypto *pCrypt)
:myCrypto(pCrypt)
{}

DataStore::~DataStore(void)
{
	// Manage memory with obj destruction
	if (myCrypto != 0) {
		delete myCrypto;
	}
}

bool DataStore::load(std::vector<String_Data> &myVector)
{
	return false;
}

bool DataStore::save(std::vector<String_Data> &myVector)
{
	return false;
}

// Protected functions below

bool DataStore::decrypt(std::string &myString)
{
	if(this->myCrypto)
		return this->myCrypto->decrypt(myString);
	else
		return false;
}

bool DataStore::encrypt(std::string &myString)
{
	if(this->myCrypto)
		return this->myCrypto->encrypt(myString);
	else
		return false;
}
