/***********************************************************************
// Workshop 6 Part 2
// Version 1.0
// Author
// Description
//	Name      : Kiarash Kia
//	Student ID: 108688235
//	Email     : kkia2@myseneca.ca
//	Submitted 1 day late referred to the accommodation letter
//
//	I have done all the coding by myself and only copied the code
//	 that my professor provided to complete my workshops and
//	 assignments.
// Revision History
// -----------------------------------------------------------
// Name                 Date            Reason
***********************************************************************/
#ifndef UTILITIES_H
#define UTILITIES_H

#include <istream>
#include "Person.h"
#include "Employee.h"


namespace seneca {
	Person* buildInstance(std::istream& in);
	void trim(std::string& str);
}


#endif