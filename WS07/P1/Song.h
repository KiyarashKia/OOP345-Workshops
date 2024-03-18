/***************************************************************************
Full Name  : Kiarash Kia
Student ID#: 108688235
Email      : kkia2@myseneca.ca
Section    : NHH
Authenticity Declaration :
I have done all the coding by myself and only copied the code that my
professor provided to complete my workshops and assignments.
***************************************************************************/
#ifndef SDDS_SONG_H
#define SDDS_SONG_H

#include <iostream>
#include <string>

namespace seneca {

    struct Song {
        std::string artist;
        std::string title;
        std::string album;
        float price;
        size_t releaseYear;
        size_t length; // in seconds
    };

    // ostream Helper
    std::ostream& operator<<(std::ostream& out, const Song& theSong);

}

#endif // SDDS_SONG_H