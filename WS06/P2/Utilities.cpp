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
#include "Professor.h"
#include "Student.h"
#include "Utilities.h"
#include <iostream>
#include <string>
#include <limits>

namespace seneca {
    Person* buildInstance(std::istream& in) {

        while (in.peek() == ' ') in.ignore();
        char c = in.peek();

        switch (c) {
        case 'E':
        case 'e':
            in.ignore(256, ',');
            return new Employee(in);

        case 'P':
        case 'p':
            in.ignore(256, ',');
            return new Professor(in);

        case 'S':
        case 's':
            in.ignore(256, ',');
            return new Student(in);

        default:
   
            in.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            return nullptr;
        }
    }
    

    void trim(std::string& str) {
        if (str.empty()) return;

        // for left trim
        size_t firstNotOf = str.find_first_not_of(' ');
        if (firstNotOf != std::string::npos) {
            str.erase(0, firstNotOf);
        }
        else {
            str.clear();
            return;
        }

        // for Right trim
        size_t lastNotOf = str.find_last_not_of(' ');
        if (lastNotOf != std::string::npos) {
            str.erase(lastNotOf + 1);
        }
    }

}
