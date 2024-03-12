#include "Student.h"
#include "Utilities.h"
#include <sstream>
#include <vector>
#include <iomanip>

namespace seneca {

    Student::Student(std::istream& is) {
        std::string line;
        if (std::getline(is, line)) {
            std::istringstream record(line);
            std::string temp, courses;
            size_t num_courses = 0;


            std::getline(record, temp, ',');
            std::getline(record, m_name, ',');
            trim(m_name);

            std::getline(record, temp, ',');
            trim(temp);
            m_age = std::stoi(temp);

            std::getline(record, m_id, ',');
            trim(m_id);

            std::getline(record, temp, ',');
            trim(temp);
            num_courses = std::stoi(temp); 

            m_courses = new std::string[num_courses];
            m_count = num_courses;

            for (size_t i = 0; i < num_courses; ++i) {
                if (!std::getline(record, courses, ',')) break;
                trim(courses);
                m_courses[i] = courses;
            }
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

    void Student::display(std::ostream& out) const {
        out << "| " << std::left << std::setw(10) << "Student"
            << "| " << std::setw(10) << m_id
            << "| " << std::setw(20) << m_name
            << "| " << std::setw(3) << m_age
            << "| ";
        for (size_t i = 0; i < m_count; ++i) {
            out << m_courses[i];
            if (i < m_count - 1) out << ", ";
        }
        out << " |" << std::endl;
    }


}
