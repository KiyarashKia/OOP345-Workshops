/***********************************************************************
// Workshop 2 Part 2
// Module: StringSet
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
#ifndef SENECA_STRINGSET_H
#define SENECA_STRINGSET_H
#include <iostream>
#include <string>

namespace seneca {

	class StringSet {
		std::string* strArr{};
		size_t arrSize{0};

	public:
		StringSet() = default;
		StringSet(const char* fName);
		size_t size() const;
		std::string operator[](size_t index) const;
		~StringSet();
		StringSet(const StringSet& other);
		StringSet& operator=(const StringSet& other);
		StringSet(StringSet&& other) noexcept;
		StringSet& operator=(StringSet&& other) noexcept;
	};




}
#endif