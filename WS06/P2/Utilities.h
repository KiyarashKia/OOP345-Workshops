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