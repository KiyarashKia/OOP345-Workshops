/***********************************************************************
// Workshop 5 Part 2
// Module: Book
// File: Book.cpp
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
#include <fstream>
#include <string>
#include <stdexcept>
#include <iostream>
#include <iomanip>
#include "SpellChecker.h"


namespace seneca {


    SpellChecker::SpellChecker(const char* filename) {
        std::ifstream file(filename);

        if (!file.is_open()) {
            throw std::runtime_error("Bad file name!");
        }

        size_t start = 0, end;
        std::string line, badWord, goodWord;

        for (int i = 0; std::getline(file, line) && i < strSize; ++i) {
            end = line.find(' ', start);
            if (end == std::string::npos) {
                throw std::runtime_error("Invalid format!");
            }

            badWord = line.substr(start, end - start);
            badWord.erase(0, badWord.find_first_not_of(' '));
            badWord.erase(badWord.find_last_not_of(' ') + 1);

            start = end + 1;
            goodWord = line.substr(start);
            goodWord.erase(0, goodWord.find_first_not_of(' '));
            goodWord.erase(goodWord.find_last_not_of(' ') + 1);

            m_badWords[i] = badWord;
            m_goodWords[i] = goodWord;
            start = 0;
        }
        file.close();
    }



    void SpellChecker::operator()(std::string& text) {
        for (auto i = 0; i < strSize; ++i) {
            while (text.find(m_badWords[i]) != std::string::npos) {
                text.replace(text.find(m_badWords[i]), m_badWords[i].size(), m_goodWords[i]);
                ++m_replaceCount[i];
            }
        }
    }

        void SpellChecker::showStatistics(std::ostream & out) const {
            out << "Spellchecker Statistics" << std::endl;

            for (auto i = 0; i < strSize; ++i)
                out << std::setw(15) << std::right << m_badWords[i] << ": " << m_replaceCount[i] << " replacements" << std::left << std::endl;
            }
        }


    

