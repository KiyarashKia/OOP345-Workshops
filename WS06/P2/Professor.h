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
#ifndef SENECA_PROFESSOR_H
#define SENECA_PROFESSOR_H
#include "Employee.h"
#include <string>
#include <iostream>
namespace seneca

{

    class Professor : public Employee
    {
        std::string m_department;

    public:
        Professor(std::istream& in);
        void display(std::ostream& out) const;
        std::string status() const;
        std::string department() const;

    };

}
#endif // !SENECA_PROFESSOR_H