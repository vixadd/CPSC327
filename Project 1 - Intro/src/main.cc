/*
 * main.cc
 *
 * 	This is the main program that uses
 * 	the project one class defined in
 * 	proj_one.hh
 *
 *  Created on: Sep 8, 2017
 *      Author: davidkroell
 */

#include <iostream>
#include "proj_one.hh"

using namespace std;

int main() {
	proj Project1(100, "Hello, World!");
	cout << Project1.getString() << endl;
	cout << "We created an integer i = " << Project1.getInteger() << endl;
	cout << "The reference for integer i is: " << Project1.showReferenceOfI() << endl;
}
