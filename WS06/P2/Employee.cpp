#include "Employee.h"
#include "Utilities.h"
#include <string>
#include <iostream>
#include <iomanip>


namespace seneca {



	Employee::Employee(std::istream& input) {
		std::string line;
		if (!std::getline(input, line)) throw std::invalid_argument("Failed to read input");

		size_t startPos = 0, endPos = line.find(',');

		// Tag 
		std::string tag = line.substr(startPos, endPos - startPos);
		startPos = endPos + 1;
		endPos = line.find(',', startPos);

		// Name
		std::string name = line.substr(startPos, endPos - startPos);
		startPos = endPos + 1;
		endPos = line.find(',', startPos);

		// Age
		std::string ageStr = line.substr(startPos, endPos - startPos);
		startPos = endPos + 1;

		// last part of the string as ID
		std::string id = line.substr(startPos);

       trim(name);
       trim(ageStr);
       (id);


		if ((tag != "e" && tag != "E") || id.empty() || id[0] != 'E') {
			throw std::invalid_argument(name + "++Invalid record!");
		}
		
		try {
			m_age = std::stoi(ageStr);
		}
		catch (std::exception&) {
			throw std::invalid_argument(name + "++Invalid record!");
		}
		m_name = name;
		m_id = id;

	}

	std::string Employee::status() const {
		return "Employee";
	}

	std::string Employee::name() const {
		return m_name;
	}

	std::string Employee::age() const {
		return std::to_string(m_age);
	}

	std::string Employee::id() const {
		return m_id;
	}

	void Employee::display(std::ostream& out) const { 
		out << std::left << "| " << std::setw(10) << "Employee" 
			<< "| " << std::setw(10) << m_id 
			<< "| " << std::setw(20) << m_name 
			<< " | " << std::setw(3) << m_age << " |" << std::endl; }


}

