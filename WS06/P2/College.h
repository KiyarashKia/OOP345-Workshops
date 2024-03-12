#ifndef SENECA_COLLEGE_H
#define SENECA_COLLEGE_H
#include <iostream>
#include <vector>
#include <list>
#include "Person.h"


namespace seneca {

	class College {
	private:
		std::vector<Person*> m_persons;

	public:
		College() = default;

		College(const College& other) = delete;
		College& operator=(const College& other) = delete;

		College(College&& other) noexcept = default;
		College& operator=(College&& other) noexcept = default;

		~College();

		College& operator+=(Person* PersontoAdd);

		void display(std::ostream& out) const;

		template<typename T>
		void select(const T& test, std::list<const Person*>& persons) const {
			for (const auto& person : m_persons) {
				if (test(person)) {
					persons.push_back(person);
				}
			}
		}

	};

}

#endif