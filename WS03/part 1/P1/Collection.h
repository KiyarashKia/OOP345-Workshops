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

		void display(std::ostream& os = std::cout) const { // setting os to std::cout by default for more comfort of use.
			os << "----------------------\n| Collection Content |\n----------------------\n";
			for (auto i = 0; i < m_size ; ++i) {
				os << items[i] << std::endl;
			}
			os << "----------------------\n";
		}

		virtual bool add(const T& item) {
			if (m_size < CAPACITY) {
				items[m_size++] = item;
				return true;
			}
			return false;
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
	};
	template<typename T, unsigned int Capacity>
	T Collection<T, Capacity>::dummy{};
	template<>
	Pair Collection<Pair, 100>::dummy = Pair("No Key", "No Value");
#endif // !SENECA_COLLECTION_H
}