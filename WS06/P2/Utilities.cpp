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

    void trim(std::string& str) {
        if (str.empty()) return;

        // Left trim
        size_t firstNotOf = str.find_first_not_of(' ');
        if (firstNotOf != std::string::npos) {
            str.erase(0, firstNotOf);
        }
        else {
            str.clear();
            return;
        }

        // Right trim
        size_t lastNotOf = str.find_last_not_of(' ');
        if (lastNotOf != std::string::npos) {
            str.erase(lastNotOf + 1);
        }
    }

}
