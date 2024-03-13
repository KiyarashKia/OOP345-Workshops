/***********************************************************************
// Workshop 6 Part 2
// Version 1.0
// Author
// Description
//	Name      : Kiarash Kia
//	Student ID: 108688235
//	Email     : kkia2@myseneca.ca
//	Submitted 1 day late referred to the accommodation letter
//
//	I have done all the coding by myself and only copied the code
//	 that my professor provided to complete my workshops and
//	 assignments.
// Revision History
// -----------------------------------------------------------
// Name                 Date            Reason
***********************************************************************/
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
        size_t m_age{};
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
    
    // Disabling Copy operations
        Student(const Student& other) = delete;
        Student& operator=(const Student& other) = delete;
    };

}

#endif // !SENECA_STUDENT_H