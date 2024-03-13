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
#include "College.h"
#include <iostream>
#include <iomanip>

namespace seneca {

    College::~College() {
        for (auto& person : m_persons) {
            delete person;
        }
        m_persons.clear();
    }

    College& College::operator+=(Person* thePerson) {
        m_persons.push_back(thePerson);
        return *this;
    }

    void College::display(std::ostream& out) const
    {
        out << "------------------------------------------------------------------------------------------------------------------------" << std::endl;
        out
            << "|                                        Test #1 Persons in the college!                                               |" << std::endl;
        out << "------------------------------------------------------------------------------------------------------------------------" << std::endl;

        for (auto person = m_persons.begin(); person != m_persons.end(); person++)
        {
            (*person)->display(out);
            out << std::endl;
        }
        out << "------------------------------------------------------------------------------------------------------------------------" << std::endl;
        out
            << "|                                        Test #2 Persons in the college!                                               |" << std::endl;
        out << "------------------------------------------------------------------------------------------------------------------------" << std::endl;

        for (auto person = m_persons.begin(); person != m_persons.end(); person++)
        {
            out << std::left << "| " << std::setw(10) << (*person)->status();
            out << "| " << std::setw(10) << (*person)->id();
            out << "| " << std::setw(20) << (*person)->name();
            out << " | " << std::setw(3) << (*person)->age() << " |" << std::endl;
        }
        out << "------------------------------------------------------------------------------------------------------------------------" << std::endl;
    }


}
