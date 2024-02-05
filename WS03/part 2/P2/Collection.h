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
#ifndef SENECA_COLLECTION_H
#define SENECA_COLLECTION_H

#include <iostream>
#include "Pair.h"

namespace seneca {

	template<typename T, unsigned int CAPACITY>
	class Collection {
		T items[CAPACITY];
		size_t m_size{0};
		static T dummy;

	public:

		Collection() : m_size(0) {};
		unsigned int size() const {
			return m_size;
		}
		void display() {
			std::cout << "----------------------" << "\n";
			std::cout << "| Collection Content |" << "\n";
			std::cout << "----------------------" << "\n";
			for (unsigned int i = 0; i < m_size; i++) {
				std::cout << items[i] << "\n";
			}
			std::cout << "----------------------" << "\n";
		}
		void display(std::ostream& ostr) {
			ostr << "----------------------" << "\n";
			ostr << "| Collection Content |" << "\n";
			ostr << "----------------------" << "\n";
			for (unsigned int i = 0; i < m_size; i++) {
				ostr << items[i] << "\n";
			}
			ostr << "----------------------" << "\n";
		}

		virtual bool add(const T& item) {
			if (m_size < CAPACITY) {
				items[m_size] = item;
				m_size++;
				return true;
			}
			else
			{
				return false;
			}
		
		}

		T operator[](unsigned int index) const {
			if (index < m_size)
			{
				return items[index];
			}
			else
			{
				return dummy;
			}

		};

		virtual ~Collection() {};
	};
	template<typename T, unsigned int Capacity>
	T Collection<T, Capacity>::dummy{};
	template<>
	Pair Collection<Pair, 100>::dummy{ "No Key" ,"No Value" };
#endif // !SENECA_COLLECTION_H
}

