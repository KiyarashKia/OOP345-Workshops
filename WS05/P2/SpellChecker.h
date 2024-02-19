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
#ifndef SENECA_SPELLCHECKER_H
#define SENECA_SPELLCHECKER_H
#include <iostream>
#include <string>

namespace seneca {

	static const int strSize = 6;

	class SpellChecker {
		std::string m_badWords[strSize]{};
		std::string m_goodWords[strSize]{};
		size_t m_replaceCount[strSize]{};

	public:
		SpellChecker();
		SpellChecker(const char* filename);
		void operator()(std::string& text);
		void showStatistics(std::ostream& out) const;
	};
	
	}

#endif // !SENECA_SPELLCHECKER_H
