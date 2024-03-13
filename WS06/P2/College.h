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
#ifndef SENECA_COLLEGE_H
#define SENECA_COLLEGE_H
#include <iostream>
#include <vector>
#include <list>
#include "Person.h"


namespace seneca {

	class College {
	private:
		std::vector<Person*> m_persons;

	public:
		College() = default;

		College(const College& other) = delete;
		College& operator=(const College& other) = delete;

		College(College&& other) noexcept = default;
		College& operator=(College&& other) noexcept = default;

		~College();

		College& operator+=(Person* PersontoAdd);

		void display(std::ostream& out) const;

		template<typename T>
		void select(const T& test, std::list<const Person*>& persons) const {
			for (const auto& person : m_persons) {
				if (test(person)) {
					persons.push_back(person);
				}
			}
		}

	};

}

#endif