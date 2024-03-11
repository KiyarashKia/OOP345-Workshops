#include "Utilities.h"
#include <iostream>
#include <string>
#include <cctype>

namespace seneca {
    Person* buildInstance(std::istream& in) {
        char firstChar;
        std::string line;

        in >> std::ws >> firstChar;

        if (in.eof()) return nullptr;

        in.putback(firstChar);

        if (firstChar == 'e' || firstChar == 'E') {
            return new Employee(in);
        }
        else {
            std::getline(in, line);
            return nullptr;
        }
    }

}
