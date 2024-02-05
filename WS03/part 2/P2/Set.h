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
#ifndef SENECA_SET_H
#define SENECA_SET_H
#include <iostream>
#include "Collection.h"
#include <string>
#include <cmath>

namespace seneca {

    template<typename T>
    class Set : public Collection<T, 100> {
    public:
        bool add(const T& item) override {
            for (size_t i = 0; i < this->size(); i++) {
                if (this->operator[](i) == item) {
                    return false;
                }
            }
            return Collection<T, 100>::add(item);
        }
    };

    template<>
    bool Set<double>::add(const double& item) {
        for (size_t i = 0; i < this->size(); i++) {
            if (std::fabs(this->operator[](i) - item) <= 0.01) {
                return false;
            }
        }
        return Collection<double, 100>::add(item);
    }
}

#endif // !SENECA_SET_H
