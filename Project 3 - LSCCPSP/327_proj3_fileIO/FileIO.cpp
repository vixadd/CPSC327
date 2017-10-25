/*
 * FileReader.cpp
 *
 *  Created on: Oct 8, 2017
 *      Author: keith
 */
#include <iostream>
#include <fstream>
#include "../327_proj3_test/includes/FileIO.h"
#include "../327_proj3_test/includes/constants.h"

using namespace std;

int KP_FileIO::getFileContents(const std::string &filename, std::string &contents)
{
	fstream mFile;
	mFile.open(filename.c_str(), std::ios_base::in);

	if(mFile.is_open()) {

		string line;
		while(getline(mFile, line)) {
			contents += line.c_str();
		}

		return SUCCESS;
	} else {
		return COULD_NOT_OPEN_FILE_TO_READ;
	}
}

int KP_FileIO::writeVectortoFile(const std::string filename,std::vector<std::string> &myEntryVector)
{

	ofstream mFile;
	mFile.open(filename.c_str());

	if (mFile.is_open()) {

		for (string s : myEntryVector) {
			mFile << s << endl;
		}

		return SUCCESS;
	} else {
		return COULD_NOT_OPEN_FILE_TO_WRITE;
	}
}


