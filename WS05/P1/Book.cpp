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
		os << std::right << std::setw(20) << book.author << " | "
			<< std::setw(22) << book.bookTitle << " | "
			<< std::setw(5) << std::right<< book.pubCountry << " | "
			<< std::setw(4) << book.pubYear << " | "
			<< std::fixed << std::setprecision(2) << std::setw(6) << book.bookPrice << " | "
			<< book.desc;
		return os;
	}


}
