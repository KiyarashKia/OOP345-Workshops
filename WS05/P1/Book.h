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

		friend std::ostream& operator <<(std::ostream& os, const Book& book);
	};



}

#endif // !SENECA_BOOK_H
