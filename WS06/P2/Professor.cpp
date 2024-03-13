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
#include "Utilities.h"
#include <iostream>
namespace seneca
{
    Professor::Professor(std::istream& in) : Employee(in)
    {
        std::getline(in, m_department);
        trim(m_department);
    }
    void Professor::display(std::ostream& out) const
    {
        Employee::display(out);
        out << m_department << "| Professor";
    }
    std::string Professor::status() const
    {
        return "Professor";
    }
    std::string Professor::department() const
    {
        return m_department;
    }
}