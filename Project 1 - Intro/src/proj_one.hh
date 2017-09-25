/*
 * proj_one.hh
 *
 *	This is the header file for definitions
 *	in the project one class used for
 *	CPSC 327.
 *
 *  Created on: Sep 8, 2017
 *      Author: davidkroell
 */

#ifndef PROJ_ONE_HH_
#define PROJ_ONE_HH_


class proj {
private:
	int i;
	char * str;

public:
	proj(int pI, char * pStr);
	~proj();
	char* getString();
	int getInteger();
	int* showReferenceOfI();
};



#endif /* SRC_PROJ_ONE_HH_ -- Ending definition of headers.*/
