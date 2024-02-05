/***********************************************************************
// Workshop 2 Part 2
// Required Modules
// File:
// Version 1.0
// Author
// Description
//	Name      : Kiarash Kia
//	Student ID: 108688235
//	Email     : kkia2@myseneca.ca
//
//	I have done all the coding by myself and only copied the code
//	 that my professor provided to complete my workshops and
//	 assignments.
// Revision History
// -----------------------------------------------------------
// Name                 Date            Reason
***********************************************************************/
#include <iostream>
#include <iomanip>
#include "Pair.h"


namespace seneca {


    Pair::Pair() : m_key(""), m_value("") {}

    bool Pair::operator==(const Pair& other) const {
        return m_key == other.m_key;
    }


    std::ostream& operator<<(std::ostream& os, const Pair& pair) {
        os << std::right << std::setw(20) << pair.m_key << ": " << pair.m_value;
        return os;
    }

}