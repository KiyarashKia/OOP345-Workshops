#include "College.h"
#include <iostream>
#include <iomanip>

namespace seneca {

    College::~College() {
        for (auto& person : m_persons) {
            delete person;
        }
        m_persons.clear();
    }

    College& College::operator+=(Person* thePerson) {
        m_persons.push_back(thePerson);
        return *this;
    }

    void College::display(std::ostream& out) const
    {
        out << "------------------------------------------------------------------------------------------------------------------------" << std::endl;
        out
            << "|                                        Test #1 Persons in the college!                                               |" << std::endl;
        out << "------------------------------------------------------------------------------------------------------------------------" << std::endl;

        for (auto person = m_persons.begin(); person != m_persons.end(); person++)
        {
            (*person)->display(out);
            out << std::endl;
        }
        out << "------------------------------------------------------------------------------------------------------------------------" << std::endl;
        out
            << "|                                        Test #2 Persons in the college!                                               |" << std::endl;
        out << "------------------------------------------------------------------------------------------------------------------------" << std::endl;

        for (auto person = m_persons.begin(); person != m_persons.end(); person++)
        {
            out << std::left << "| " << std::setw(10) << (*person)->status();
            out << "| " << std::setw(10) << (*person)->id();
            out << "| " << std::setw(20) << (*person)->name();
            out << " | " << std::setw(3) << (*person)->age() << " |" << std::endl;
        }
        out << "------------------------------------------------------------------------------------------------------------------------" << std::endl;
    }


}
