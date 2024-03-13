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
#ifndef SENECA_EMPLOYEE_H
#define SENECA_EMPLOYEE_H
#include <iostream>
#include <string>
#include "Person.h"

namespace seneca {

	class Employee : public Person {
	private:
		std::string m_name;
		int m_age;
		std::string m_id;


	public:
		Employee(std::istream& in);

		std::string status() const override;
		std::string name() const override;
		std::string age() const override;
		std::string id() const override;

		void display(std::ostream& out) const override;



	};

}

#endif