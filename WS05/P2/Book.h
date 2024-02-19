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
#pragma once
#ifndef SENECA_BOOK_H
#define SENECA_BOOK_H
#include <iostream>
#include <string>

namespace seneca {

	class Book {
		std::string author;
		std::string bookTitle;
		std::string pubCountry;
		size_t pubYear;
		double bookPrice;
		std::string desc;

	public:
		Book() : pubYear(0), bookPrice(0.0) {};
		const std::string& title() const;
		const std::string& country() const;
		const size_t& year() const;
		double& price();
		Book(const std::string& strBook);


		template<typename T>
		void fixSpelling(T& spellChecker) {
			spellChecker(desc);
		}


		friend std::ostream& operator <<(std::ostream& os, const Book& book);
	};



}

#endif // !SENECA_BOOK_H
