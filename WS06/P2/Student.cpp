#include "Student.h"
#include "Utilities.h"
#include <iomanip>
#include <limits>

namespace seneca {

    Student::Student(std::istream& is) : m_age(0), m_courses(nullptr), m_count(0)
    {
        std::getline(is, m_name, ',');
        trim(m_name);

        if (!(is >> m_age))
        {
            is.clear();
            is.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            throw std::invalid_argument(m_name + "++Invalid record!");
        }
        is.ignore(256, ',');

        char c = is.peek();
        while (c != ',' && c != '\n')
        {
            m_id += c;
            is.ignore();
            c = is.peek();
        }

        trim(m_id);
        if (m_id[0] != 'S')
        {
            is.clear();
            is.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            throw std::invalid_argument(m_name + "++Invalid record!");
        }
        is.ignore(std::numeric_limits<std::streamsize>::max(), ',');

        if (!(is >> m_count))
        {
            is.clear();
            is.ignore(256, '\n');
            throw std::invalid_argument(m_name + "++Invalid record!");
        }
        is.ignore(std::numeric_limits<std::streamsize>::max(), ',');

        m_courses = new std::string[m_count];

        for (size_t i = 0; i < m_count; i++)
        {
            std::string course;
            if (i == m_count - 1)
            {
                std::getline(is, course);
            }
            else
            {
                std::getline(is, course, ',');
            }

            trim(course);
            m_courses[i] = course;
        }
    }
    

    Student::~Student() {
        delete[] m_courses;
    }

    std::string Student::status() const {
        return "Student";
    }

    std::string Student::name() const {
        return m_name;
    }

    std::string Student::age() const {
        return std::to_string(m_age);
    }

    std::string Student::id() const {
        return m_id;
    }

    void Student::display(std::ostream& out) const
    {
        out << std::left << "| " << std::setw(10) << "Student";
        out << "| " << std::setw(10) << m_id;
        out << "| " << std::setw(20) << m_name;
        out << " | " << std::setw(3) << m_age << " |";
        for (size_t i = 0; i < m_count; i++)
        {
            out << m_courses[i];
            if (i != m_count - 1)
                out << ", ";
        }
    }


}
