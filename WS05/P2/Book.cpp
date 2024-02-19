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
#include <iostream>
#include <iomanip>
#include "Book.h"


namespace seneca {


	Book::Book(const std::string& strBook) {
		size_t start = 0, end;

		//Extract Author
		end = strBook.find(',', start);
		author = strBook.substr(start, (end - start));
		author.erase(0, author.find_first_not_of(' '));
		author.erase(author.find_last_not_of(' ') + 1);

		// Extrat Title
		start = end + 1;
		end = strBook.find(',', start);
		bookTitle = strBook.substr(start, (end - start));
		bookTitle.erase(0, bookTitle.find_first_not_of(' '));
		bookTitle.erase(bookTitle.find_last_not_of(' ') + 1);

		// Extract Country 
		start = end + 1;
		end = strBook.find(',', start);
		pubCountry = strBook.substr(start, (end - start));
		pubCountry.erase(0, pubCountry.find_first_not_of(' '));
		pubCountry.erase(pubCountry.find_last_not_of(' ') + 1);

		// Extract Price
		start = end + 1;
		end = strBook.find(',', start);
		bookPrice = std::stod(strBook.substr(start, end - start));

		// Extract Year
		start = end + 1;
		end = strBook.find(',', start);
		pubYear = std::stoi(strBook.substr(start, end - start));

		// Extract Description
		start = end + 1;
		desc = strBook.substr(start);
		desc.erase(0, desc.find_first_not_of(' '));
		desc.erase(desc.find_last_not_of(' ') + 1);
	}

	const std::string& Book::title() const { return bookTitle; }

	const std::string& Book::country() const { return pubCountry; }

	const size_t& Book::year() const { return pubYear; }

	double& Book::price() { return bookPrice; }


	std::ostream& operator<<(std::ostream& os, const Book& book) {
		os << std::setw(20) << std::right << book.author << " | ";
		os << std::setw(22) << book.title() << " | ";
		os << std::setw(5) << book.country() << " | ";
		os << std::setw(4) << book.year() << " | ";
		os << std::setw(6) << std::fixed << std::setprecision(2) << book.bookPrice << " | ";
		os << std::left << book.desc << std::endl;
		return os;
	}


}
