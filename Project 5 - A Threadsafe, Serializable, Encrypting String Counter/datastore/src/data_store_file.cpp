/*
 * Data Store file for the abstract impl
 * of Data store.
 *
 * Author: David Kroell
 * Version: 12/04/2017
 */

#include "../includes/data_store_file.h"

#include <fstream>

DataStore_File::DataStore_File(std::string filename, Crypto* crypto)
:DataStore(crypto),
 myFileName(filename)
{

}

DataStore_File::~DataStore_File()
{

}

bool DataStore_File::load(std::vector<String_Data> &myVector)
{
	std::fstream thisFile;

	if(this->openFile(thisFile, this->myFileName, std::ios_base::in)) {
		std::string str;
		while(std::getline(thisFile, str)) {
			if(this->myCrypto){
				bool encrypted = myCrypto->decrypt(str);
			}

			myVector.push_back(str);
		}

		this->closeFile(thisFile);
		return true;

	} else {
		return false;
	}
}

bool DataStore_File::save(std::vector<String_Data> &myVector)
{
	std::fstream thisFile;
	if(this->openFile(thisFile, this->myFileName, std::ios_base::out)) {

		for(std::string str: myVector) {
			if(this->myCrypto) {
				bool encrypted = this->myCrypto->encrypt(str);
			}

			thisFile << str << std::endl;
		}

		thisFile.close();
		return true;

	} else {
		return false;
	}

}

bool DataStore_File::openFile(std::fstream& myfile,const std::string& myFileName, std::ios_base::openmode mode)
{
	myfile.open(myFileName.c_str(), mode);
	return myfile.is_open();
}

void DataStore_File::closeFile(std::fstream& myfile)
{
	if(myfile.is_open()) {
		myfile.close();
	}
}
