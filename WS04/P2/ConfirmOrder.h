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
#ifndef SENECA_CONFIRMORDER_H
#define SENECA_CONFIRMORDER_H
#include <iostream>
#include "Toy.h"

namespace seneca {

	class ConfirmOrder {
		const Toy** toys; // Dynamic array of pointers to toy
		size_t numToys; // Number of toys

	public:

        ConfirmOrder(); // constructor
        ~ConfirmOrder(); // Destructor
        ConfirmOrder(const ConfirmOrder& other); // Copy constructor
        ConfirmOrder(ConfirmOrder&& other) noexcept; // Move constructor
        ConfirmOrder& operator=(const ConfirmOrder& other); // Copy assignment operator
        ConfirmOrder& operator=(ConfirmOrder&& other) noexcept; // Move assignment operator
        ConfirmOrder& operator+=(const Toy& toy); // Adding a toy
        ConfirmOrder& operator-=(const Toy& toy); // Removes a toy


        void resize(size_t newSize);

        friend std::ostream& operator<<(std::ostream& os, const ConfirmOrder& order);

	};


}



#endif // !SENECA_CONFIRMORDER_H
