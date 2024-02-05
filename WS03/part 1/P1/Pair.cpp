#include <iostream>
#include <iomanip>
#include "Pair.h"


namespace seneca {


    Pair::Pair() : m_key(""), m_value("") {}

    bool Pair::operator==(const Pair& other) const {
        return m_key == other.m_key;
    }


    std::ostream& operator<<(std::ostream& os, const Pair& pair) {
        os << std::right << std::setw(20) << pair.m_key << ": " << pair.m_value;
        return os;
    }

}