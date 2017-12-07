/*
 * String database impl for the Project
 * extracted from header.
 *
 * Author: David Kroell
 * Version: 12/04/2017
 */

#include "../includes/string_database.h"

String_Database::String_Database()
{}

String_Database::~String_Database() // Not sure if we're supposed to do stuff for these.
{}

void String_Database::add(std::string &myString)
{
	String_Data s(myString);

	bool notSeen = true;
	for(String_Data sd : this->myStrings) {
		if(sd.operator==(s)) {
			sd.increment();
			notSeen = false;
			break;
		}
	}

	if(notSeen)
		std::lock_guard<std::mutex> m(this->mutex); // Not sure if a lockguard should go here.
		myStrings.push_back(s);
}

int String_Database::getCount(std::string &myString)
{
	String_Data s(myString);

	for (String_Data sd : this->myStrings) {
		if(sd.operator==(s))
			return sd.getCount();
	}

	return -1;
}

void String_Database::clear()
{
	this->myStrings.clear();
}

bool String_Database::load(DataStore  *myDataStore)
{
	if(myDataStore) {

		std::lock_guard<std::mutex> m(this->mutex); // Not sure if a lockguard should go here.
		return myDataStore->load(this->myStrings);

	} else {
		return false;
	}
}

bool String_Database::save(DataStore *myDataStore)
{
	if(myDataStore) {

		std::lock_guard<std::mutex> m(this->mutex); // Not sure if the lockguard should go here.
		return myDataStore->save(this->myStrings);

	} else {
		return false;
	}
}
