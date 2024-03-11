#ifndef SENECA_COLLEGE_H
#define SENECA_COLLEGE_H
#include <iostream>
#include <vector>
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

	};

}

#endif