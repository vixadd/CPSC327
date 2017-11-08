// smalltalk_VirtualAbstractVector.cpp : Defines the entry point for the console application.
//
#include <iostream>

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
		int numwatches = 2;

		std::vector<std::unique_ptr<Smalltalk> > myv1 = getPeople(numEachGroup,
				numEachGroup, numEachGroup, numwatches);
		int cntr = 0;
		for (int i = 0; i < myv1.size(); i++) {
			std::cout << myv1[i]->saySomething() << endl;
			std::cout << myv1[i]->getTime() << endl;
		}
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
