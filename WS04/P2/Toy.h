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
#ifndef SENECA_TOY_H
#define SENECA_TOY_H
#include <iostream>

namespace seneca {

	class Toy {
		int orderID;
		std::string toyName;
		int toysOrdered;
		double toyPrice;
		static constexpr double HST = 0.13; // constexpr static to initialize globally and having that evaluation at compile-time

	public:
		Toy(); // Default constructor
		void update(int numItems); // Modifier / Updater of number of ordered toys
		Toy(const std::string& Toy); // String argument constructor to extract object's attributes



		friend std::ostream& operator << (std::ostream& os, const Toy& t); // Insertion Operator
	};


}




#endif // !SENECA_TOY_H
