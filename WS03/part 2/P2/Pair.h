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
#pragma once
#ifndef SENECA_PAIR_H
#define SENECA_PAIR_H

#include <iostream>

namespace seneca {

	class Pair
	{

		std::string m_key{};
		std::string m_value{};
	public:
		Pair();
		const std::string& getKey() { return m_key; }
		const std::string& getValue() { return m_value; }
		Pair(const std::string& key, const std::string& value) : m_key{ key }, m_value{ value } {};

		bool operator==(const Pair& other) const;
		friend std::ostream& operator<<(std::ostream& os, const Pair& pair);

	};


}


#endif // !SENECA_PAIR_H
