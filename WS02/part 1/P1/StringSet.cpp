/***********************************************************************
// Workshop 2 Part 2
// Module: StringSet
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
#include <fstream>
#include "StringSet.h"

namespace seneca {


    StringSet::StringSet(const char* fName) : strArr(nullptr), arrSize(0) {
        std::ifstream file(fName);
        if (!file) {
            std::cerr << "Error opening file: " << fName << std::endl;
            return;
        }

        char ch;
        while (file.get(ch)) {
            if (ch == ' ') {
                arrSize++;
            }
        }

		strArr = new std::string[++arrSize];
        size_t index = 0;

        file.clear();
        file.seekg(0);

        while (file.get(ch)) {
            if (ch == ' ') {
                index++;
            } else {
                strArr[index] += ch;
            }
        }

        file.close();
    }

		size_t StringSet::size() const {
			return arrSize;
		}

		std::string StringSet::operator[](size_t index) const {
			if (index >= arrSize) {
				return "";
			}
			return strArr[index];
		}

		StringSet::~StringSet() {
			delete[] strArr;
		}

		StringSet::StringSet(const StringSet& other) : strArr(nullptr), arrSize(other.arrSize) {
			if (other.strArr) {
				strArr = new std::string[arrSize];
				for (size_t i = 0; i < arrSize; ++i) {
					strArr[i] = other.strArr[i];
				}
			}
		}

		StringSet& StringSet::operator=(const StringSet& other) {
			if (this != &other) {
				delete[] strArr;
				arrSize = other.arrSize;
				strArr = new std::string[arrSize];
				for (size_t i = 0; i < arrSize; ++i) {
					strArr[i] = other.strArr[i];
				}
			}
			return *this;
		}


	}



