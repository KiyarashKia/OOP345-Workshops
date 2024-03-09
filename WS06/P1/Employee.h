#ifndef SENECA_EMPLOYEE_H
#define SENECA_EMPLOYEE_H
#include <iostream>
#include <string>
#include "Person.h"

namespace seneca {

	class Employee : public Person {
	private:
		std::string m_name;
		int m_age;
		std::string m_id;

		//Trimmer function
		static std::string trim(const std::string& str);


	public:
		Employee(std::istream& in);

		std::string status() const override;
		std::string name() const override;
		std::string age() const override;
		std::string id() const override;

		void display(std::ostream& out) const override;



	};

}

#endif