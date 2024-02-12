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
#include<iostream>
#include <iomanip>
#include <string>
#include "Toy.h"

namespace seneca {

    Toy::Toy() : orderID(0), toyName(" "), toysOrdered(0), toyPrice(0.0) {}

    void Toy::update(int numItems) { toysOrdered = numItems; }

    Toy::Toy(const std::string& toy) {
        size_t startPos = 0, endPos;


        endPos = toy.find(':');
        orderID = std::stoi(toy.substr(startPos, endPos - startPos));


        startPos = endPos + 1;
        endPos = toy.find(':', startPos);
        toyName = toy.substr(startPos, endPos - startPos);

        toyName.erase(0, toyName.find_first_not_of(' '));
        toyName.erase(toyName.find_last_not_of(' ') + 1);


        startPos = endPos + 1;
        endPos = toy.find(':', startPos);
        toysOrdered = std::stoi(toy.substr(startPos, endPos - startPos));


        startPos = endPos + 1;
        toyPrice = std::stod(toy.substr(startPos));

    }

    std::ostream& operator<<(std::ostream& os, const Toy& t) {
        double subtotal = t.toyPrice * t.toysOrdered;
        double tax = subtotal * Toy::HST;
        double total = subtotal + tax;

        os << "Toy"
            << std::setw(8) << t.orderID << ":"
            << std::setw(18) << std::right << t.toyName
            << std::setw(3) << t.toysOrdered << " items"
            << std::setw(8) << std::fixed << std::setprecision(2) << t.toyPrice << "/item  subtotal:"
            << std::setw(7) << std::fixed << std::setprecision(2) << subtotal
            << " tax:"
            << std::setw(6) << std::fixed << std::setprecision(2) << tax
            << " total:"
            << std::setw(7) << std::fixed << std::setprecision(2) << total << '\n';

        return os;
    }

}