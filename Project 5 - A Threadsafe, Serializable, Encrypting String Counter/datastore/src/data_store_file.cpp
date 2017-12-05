/*
 * Data Store file for the abstract impl
 * of Data store.
 *
 * Author: David Kroell
 * Version: 12/04/2017
 */

#include "../includes/data_store_file.h"

DataStore_File::DataStore_File(std::string filename, Crypto* crypto)
:DataStore(crypto),
 myFileName(filename)
{}

DataStore_File::~DataStore_File()
{

}

bool DataStore_File::load(std::vector<String_Data> &myVector)
{
	return false;
}

bool DataStore_File::save(std::vector<String_Data> &myVector)
{
	return false;
}

bool DataStore_File::openFile(std::fstream& myfile,const std::string& myFileName, std::ios_base::openmode mode)
{
	return false;
}

void DataStore_File::closeFile(std::fstream& myfile)
{

}
