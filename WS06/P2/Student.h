#ifndef SENECA_STUDENT_H
#define SENECA_STUDENT_H
#include "Person.h"
#include <string>
#include <iostream>
namespace seneca
{

    class Student : public Person
    {
        std::string m_name;
        std::string m_id;
        size_t m_age;
        std::string* m_courses{};
        size_t m_count{};

    public:

        Student(std::istream& is);
        ~Student();

        std::string status() const;
        std::string name() const;
        std::string age() const;
        std::string id() const;

        void display(std::ostream& out) const;
    };

}

#endif // !SENECA_STUDENT_H