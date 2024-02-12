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

#include <iostream>
#include "Child.h"

namespace seneca {
	
	void Child::copyToys(const Toy* source[], size_t count) { // To do deep copying for each of the toys
		toys = new const Toy * [count];
		for (size_t i = 0; i < count; ++i) {
			toys[i] = new Toy(*source[i]);
		}
		numToys = count;
	}

	Child::Child(std::string name, int age, const Toy* toys[], size_t count)
		: childName(std::move(name)), childAge(age), toys(nullptr), numToys(0) {
		copyToys(toys, count);
	}

	Child::~Child() {
		for (size_t i = 0; i < numToys; ++i) {
			delete toys[i];
		}
		delete[] toys;
	}

	size_t Child::size() const {
		return numToys;
	}

	Child::Child(Child&& other) noexcept
		: childName(std::move(other.childName)),
		childAge(other.childAge),
		toys(other.toys),
		numToys(other.numToys) {

		other.toys = nullptr;
		other.numToys = 0;
		other.childAge = 0;
	}

	Child::Child(const Child& other)
		: childName(other.childName), childAge(other.childAge), toys(nullptr), numToys(0) {
		copyToys(other.toys, other.numToys);
	}


	Child& Child::operator=(const Child& other) {
		if (this != &other) {
			for (size_t i = 0; i < numToys; ++i) {
				delete toys[i];
			}
			delete[] toys;
			childName = other.childName;
			childAge = other.childAge;
			copyToys(other.toys, other.numToys);
		}
		return *this;
	}


	Child& Child::operator=(Child&& other) noexcept {
		if (this != &other) {
			for (size_t i = 0; i < numToys; ++i) {
				delete toys[i];
			}
			delete[] toys;

			childName = std::move(other.childName);
			childAge = other.childAge;
			toys = other.toys;
			numToys = other.numToys;

			other.toys = nullptr;
			other.numToys = 0;
			other.childAge = 0;
		}
		return *this;
	}

	std::ostream& operator<<(std::ostream& os, const Child& child) {
		static int callCount = 0;
		callCount++;
		os << "--------------------------\n"
			<< "Child " << callCount << ": " << child.childName << " " << child.childAge << " years old:\n"
			<< "--------------------------\n";
		if (child.numToys == 0) {
			os << "This child has no toys!\n"
			<< "--------------------------\n";
		}
		else {
			for (size_t i = 0; i < child.numToys; ++i) {
				os << *child.toys[i];
			}
			os << "--------------------------\n";
		}
		return os;
	}

}

