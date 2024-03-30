/***********************************************************************
// Workshop 9 Part 2
// Version 1.0
// Author
// Description
//	Name      : Kiarash Kia
//	Student ID: 108688235
//	Email     : kkia2@myseneca.ca
//
//
//	I have done all the coding by myself and only copied the code
//	 that my professor provided to complete my workshops and
//	 assignments.
// Revision History
// -----------------------------------------------------------
// Name                 Date            Reason
***********************************************************************/
#ifndef SENECA_TREASUREMAP_H
#define SENECA_TREASUREMAP_H

#include <cstddef>
#include <iostream>
#include <string>

namespace seneca {
    class TreasureMap {
        size_t rows = 0;
        size_t colSize = 0;
        std::string* map = nullptr;
    public:
        TreasureMap(const char* filename);
        ~TreasureMap();

        std::ostream& display(std::ostream& os) const;
        void enscribe(const char* filename);
        void recall(const char* filename);
        void clear();
        size_t findTreasure(char mark);
    };


    size_t digForTreasure(const std::string& segment, char mark);
}

#endif // SENECA_TREASUREMAP_H