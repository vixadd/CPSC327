#pragma once
#include <string>
#include <vector>
#include "Watch.h"

class Smalltalk
{
public:
	//derived class will set Nationality, iPerson. iPerson is just a counter used to distinguish objects of the same type
	Smalltalk(std::string myNationality,int iPerson=0);
	
	//if pWatch !=0 then be sure to delete the pointer
	virtual ~Smalltalk(void);
	
	//cycles through and returns phrases created in populatePhrases
	//takes the form Nationality iPerson: phrase
	//for instance the following string comes from an American instance, the 10th iPerson and it is printing AMERICAN_PHRASE_2 
	//AMERICAN 10:Why yes, I would like to supersize that
	std::string saySomething();

	//returns the time or I_DO_NOT_HAVE_A_WATCH string
	std::string getTime();

	//if this object has a watch it is taken away, 
	//this means return the pointer and set this->pWatch =NULL;
	Watch* takeWatch();

	//if already have a watch then return false and dont change pWatch pointer
	//otherwise accept watch (return true) and set this->pWatch=pWatch
	bool giveWatch(Watch *pWatch);

	//ABC, implement in derived classes
	virtual void populatePhrases()=0;
	
protected:
	const std::string			nationality;	//populated by derived classes using initilizer list from constants.h
	std::vector<std::string>	mySmallTalk;	//populated by populatePhrases in derived classes
	int							iPerson;		//what number this person is (just a way to track objects)
	int 						current_phrase;	//which phrase was last returned (use % operator to cycle through phrases)
	Watch 						*pWatch;		//if 0 don't have a watch, otherwise does have a watch
};

