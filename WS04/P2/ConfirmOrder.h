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

        friend std::ostream& operator<<(std::ostream& os, const ConfirmOrder& order);

	};


}



#endif // !SENECA_CONFIRMORDER_H
