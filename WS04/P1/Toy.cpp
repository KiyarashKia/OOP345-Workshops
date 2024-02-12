#include<iostream>
#include <iomanip>
#include <string>
#include "Toy.h"

namespace seneca {

	Toy::Toy() : orderID(0) , toyName(" "), toysOrdered(0), toyPrice(0.0) {}

	void Toy::update(int numItems) {  toysOrdered = numItems; }

	Toy::Toy(const std::string& toy) {
        size_t startPos = 0, endPos;
        endPos = toy.find(':'); // Find the first delimiter
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

        os << "Toy " << std::setw(7) << std::left << t.orderID << ":"
            << std::setw(17) << std::right << t.toyName << "  "
            << std::setw(1) << t.toysOrdered << " items   "
            << std::setw(6) << std::fixed << std::setprecision(2) << t.toyPrice << "/item  "
            << "subtotal: " << std::setw(6) << subtotal
            << " tax: " << std::setw(5) << tax
            << " total: " << std::setw(6) << total << '\n';


        return os;
    }

}