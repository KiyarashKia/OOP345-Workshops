/***********************************************************************
// Workshop 5 Part 2
// Module: Book
// File: Book.cpp
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
#include <iomanip>
#include "Movie.h"

namespace seneca {

    Movie::Movie(const std::string& strMovie) {
        size_t start = 0, end;

        // Extract Title
        end = strMovie.find(',', start);
        m_title = strMovie.substr(start, end - start);
        m_title.erase(0, m_title.find_first_not_of(' '));
        m_title.erase(m_title.find_last_not_of(' ') + 1);

        // Extract Year
        start = end + 1;
        end = strMovie.find(',', start);
        m_year = std::stoi(strMovie.substr(start, end - start));

        // Extract Description
        start = end + 1;
        m_description = strMovie.substr(start);
        m_description.erase(0, m_description.find_first_not_of(' '));
        m_description.erase(m_description.find_last_not_of(' ') + 1);
    }

    const std::string& Movie::title() const { return m_title; }

    std::ostream& operator<<(std::ostream& os, const Movie& movie) {
            os << std::right << std::setw(40) << movie.m_title << " | "
            << std::setw(4) << movie.m_year << " | "
            << movie.m_description << '\n';

        return os;
    }

}