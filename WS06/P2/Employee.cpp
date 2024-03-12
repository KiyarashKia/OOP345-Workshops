#include "Employee.h"
#include "Utilities.h"
#include <iostream>
#include <iomanip>
#include <limits>

namespace seneca {



    Employee::Employee(std::istream& is)
    {
        std::getline(is, m_name, ',');
        trim(m_name);

        if (!(is >> m_age))
        {
            is.clear();
            is.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            throw std::invalid_argument(m_name + "++Invalid record!");
        }
        is.ignore(std::numeric_limits<std::streamsize>::max(), ',');

        char c = is.peek();
        while (c != ',' && c != '\n')
        {

            m_id += c;
            is.ignore();
            c = is.peek();
        }
        trim(m_id);
        if (m_id[0] != 'E')
        {
            is.clear();
            is.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            throw std::invalid_argument(m_name + "++Invalid record!");
        }
        is.ignore();
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

    void Employee::display(std::ostream& out) const
    {
        out << std::left << "| " << std::setw(10) << "Employee";
        out << "| " << std::setw(10) << m_id;
        out << "| " << std::setw(20) << m_name;
        out << " | " << std::setw(3) << m_age << " |";
    };

}

