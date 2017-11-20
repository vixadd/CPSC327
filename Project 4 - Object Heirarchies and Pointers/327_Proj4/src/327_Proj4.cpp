// smalltalk_VirtualAbstractVector.cpp : Defines the entry point for the console application.
//
#include <iostream>
#include <vector>

#include "./includes/constants.h"
#include "./includes/Functions.h"
#include "./includes/Smalltalk_American.h"
#include "./includes/Smalltalk_Brit.h"
#include "./includes/Smalltalk.h"
#include "./includes/ST_American_DonutEnthusiest.h"
#include "./includes/Watch.h"


using namespace std;

//TODO make sure you have the right number of watches

//TODO make sure you consider the case where you have more watches than people

//TODO make sure you do not do a deep copy any watches when giving or taking them
//     the simplest way is give and take the watch a few times and verify that the old recipients have 
//     a null pWatch pointer
//     and that the pointer returned from the last takeWatch is the same as the one you began with on giveWatch

//TODO make sure saySomething() cycles through appropriate phrases


void demo(){
	int numEachGroup = 2;
	int numwatches = 5;

	std::vector<std::unique_ptr<Smalltalk> > myv1
		= getPeople(numEachGroup,numEachGroup, numEachGroup, numwatches);

	// First test just outputs values at random.
	std::cout << std::endl << "================= Test 1 ===================" << std::endl << std::endl;
	int arr_size = myv1.size();
	for (int i = 0; i < arr_size; i++) {
		std::cout << myv1[i]->saySomething() << endl;
		std::cout << myv1[i]->getTime() << endl;
	}

	// Cleaning up after myself.
	// So valgrind doesn't get annoyed.
	myv1.clear();

	std::cout << std::endl << "============================================" << std::endl << std::endl;

	// Second test exchanges watches, and displays watches being given and taken.
	std::cout << std::endl << "================= Test 2 ===================" << std::endl << std::endl;
	std::cout << "Giving BRIT 0 watch to American_Donut_Enthusiest 1" << std::endl;
	std::cout << "Giving BRIT 1 watch to American 0" << std::endl;

	unique_ptr<Smalltalk> ptr_brit_0 (std::move(new Smalltalk_Brit(0)));
	unique_ptr<Smalltalk> ptr_brit_1 (std::move(new Smalltalk_Brit(1)));
	unique_ptr<Smalltalk> ptr_amer_0 (std::move(new Smalltalk_American(0)));
	unique_ptr<Smalltalk> ptr_amdt_1 (std::move(new ST_American_DonutEnthusiest(1)));

	ptr_brit_0->giveWatch(new Watch());
	ptr_brit_1->giveWatch(new Watch());

	std::cout << "\n \t -----------Before-------------" << std::endl;
	std::cout << "\t" << ptr_brit_0->getTime() << std::endl;
	std::cout << "\t" << ptr_brit_1->getTime() << std::endl << std::endl;
	std::cout << "\t" << ptr_amer_0->getTime() << std::endl;
	std::cout << "\t" << ptr_amdt_1->getTime() << std::endl;

	// Attempt to transfer shallow copy of watch over to the Donut Enthusiest.
	ptr_amdt_1->giveWatch(ptr_brit_0->takeWatch());
	ptr_amer_0->giveWatch(ptr_brit_1->takeWatch());

	//Try to break this:
	ptr_brit_1->giveWatch(ptr_brit_0->takeWatch());

	//Try to give a watch to someone who already has a watch.
	cout << std::endl << "\t Giving watch to someone who already has one." << std::endl;
	unique_ptr<Watch> ptr (std::move(new Watch()));
	bool result = ptr_amdt_1->giveWatch(ptr.get());
	std::cout << "\n \t Result of trying to give watch to someone who has one: " << result <<  std::endl;

	std::cout << "\n \t ---------- After -------------" << std::endl;
	std::cout << "\t" << ptr_brit_0->getTime() << std::endl;
	std::cout << "\t" << ptr_brit_1->getTime() << std::endl << std::endl;
	std::cout << "\t" << ptr_amer_0->getTime() << std::endl;
	std::cout << "\t" << ptr_amdt_1->getTime() << std::endl;


	std::cout << std::endl << "============================================" << std::endl << std::endl;
}

int main() {
	demo();

//the above call produces the following console output
	
//	BRIT 0:Im a bit knackered mate
//	BRIT 0:The time is: 27 minutes after1
//	BRIT 1:Im a bit knackered mate
//	BRIT 1:The time is: 27 minutes after1
//	AMERICAN 0:Why yes, I would like to supersize that
//	AMERICAN 0:I do not have a watch
//	AMERICAN 1:Why yes, I would like to supersize that
//	AMERICAN 1:I do not have a watch
//	AMERICAN_DONUT_ENTHUSIEST 0:Dunkin Donuts is a horrendous, disappointing compromise
//	AMERICAN_DONUT_ENTHUSIEST 0:I do not have a watch
//	AMERICAN_DONUT_ENTHUSIEST 1:Dunkin Donuts is a horrendous, disappointing compromise
//	AMERICAN_DONUT_ENTHUSIEST 1:I do not have a watch

	
}
