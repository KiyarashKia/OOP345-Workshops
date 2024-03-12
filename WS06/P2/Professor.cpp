#include "Professor.h"
#include "Utilities.h"
#include <iostream>
namespace seneca
{
    Professor::Professor(std::istream& in) : Employee(in)
    {
        std::getline(in, m_department);
        trim(m_department);
    }
    void Professor::display(std::ostream& out) const
    {
        Employee::display(out);
        out << m_department << "| Professor";
    }
    std::string Professor::status() const
    {
        return "Professor";
    }
    std::string Professor::department() const
    {
        return m_department;
    }
}