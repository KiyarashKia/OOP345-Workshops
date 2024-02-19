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
#pragma once
#ifndef SENECA_MOVIE_H
#define SENECA_MOVIE_H
#include <iostream>
#include <string>

namespace seneca {

	class Movie {
		std::string m_title;
		size_t m_year{};
		std::string m_description;

	public:
		Movie() = default;
		const std::string& title() const;
		Movie(const std::string& strMovie);
	
		template<typename T>
		void fixSpelling(T& spellChecker) {
			spellChecker(m_description);
			spellChecker(m_title);
		}

		friend std::ostream& operator <<(std::ostream& os, const Movie& movie);
	};


}

#endif // !SENECA_MOVIE_H