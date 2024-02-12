/***********************************************************************
// Workshop 4 Part 2
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
#ifndef SENECA_CHILD_H
#define SENECA_CHILD_H
#include <iostream>
#include "Toy.h"

namespace seneca {

	class Child {
		std::string childName;
		int childAge;
		const Toy** toys;
		size_t numToys;

	public:
		Child(std::string name, int age, const Toy* toys[], size_t count); // Constructor
		~Child(); // Destructor
		Child(const Child& other); // Copy Constructor
		Child& operator=(const Child& other); // Copy assignment operator
		size_t size() const;
		Child(Child&& other) noexcept; // Move Constructor
		Child& operator=(Child&& other) noexcept; // Move Assignment operator

		
		friend std::ostream& operator<<(std::ostream& os, const Child& child);

	private:
		void copyToys(const Toy* source[], size_t count);
	};


}

#endif // !SENECA_CHILD_H
