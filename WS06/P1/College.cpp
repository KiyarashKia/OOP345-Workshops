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

    void College::display(std::ostream& out) const {
        out << "------------------------------------------------------------------------------------------------------------------------\n";
        out << "|                                        Test #1 Persons in the college!                                               |\n";
        out << "------------------------------------------------------------------------------------------------------------------------\n";
        for (const auto& person : m_persons) {
            person->display(out);
        }


        out << "------------------------------------------------------------------------------------------------------------------------\n";
        out << "|                                        Test #2 Persons in the college!                                               |\n";
        out << "------------------------------------------------------------------------------------------------------------------------\n";
        for (const auto& person : m_persons) {
            person->display(out);
        }
        out << "------------------------------------------------------------------------------------------------------------------------\n";
    }


}
