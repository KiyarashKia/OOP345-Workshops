#include <iostream>
#include <iomanip>
#include "Book.h"


namespace seneca {


	Book::Book(const std::string& strBook) {
		size_t start = 0, end;

		//Extract Author
		end = strBook.find(',', start);
		author = strBook.substr(start, (end - start));

		// Extrat Title
		start = end + 1;
		end = strBook.find(',', start);
		bookTitle = strBook.substr(start, (end - start));

		// Extract Country 
		start = end + 1;
		end = strBook.find(',', start);
		pubCountry = strBook.substr(start, (end - start));

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
	}

	const std::string& Book::title() const { return bookTitle; }

	const std::string& Book::country() const { return pubCountry; }

	const size_t& Book::year() const { return pubYear; }

	double& Book::price() { return bookPrice; }


	std::ostream& operator<<(std::ostream& os, const Book& book) {
		os << std::left << std::setw(20) << book.author << " | "
			<< std::setw(22) << book.bookTitle << " | "
			<< std::setw(5) << book.pubCountry << " | "
			<< std::setw(4) << book.pubYear << " | "
			<< std::fixed << std::setprecision(2) << std::setw(6) << book.bookPrice << " | "
			<< book.desc;
		return os;
	}


}

/*
Book(const std::string& strBook): a constructor that receives a reference to an unmodifiable string that contains information about the book;
this constructor extracts the information about the book from the string by parsing it and stores the tokens in the object's attributes. 
The string always has the following format:

AUTHOR,TITLE,COUNTRY,PRICE,YEAR,DESCRIPTION

*/