/***************************************************************************
Full Name  : Kiarash Kia
Student ID#: 108688235
Email      : kkia2@myseneca.ca
Section    : NHH
Authenticity Declaration :
I have done all the coding by myself and only copied the code that my
professor provided to complete my workshops and assignments.
***************************************************************************/
#ifndef SENECA_SONGCOLLECTION_H
#define SENECA_SONGCOLLECTION_H

#include "Song.h"
#include <vector>
#include <iostream>

namespace seneca {

    class SongCollection {
        std::vector<Song> songs;

    public:
        SongCollection(const std::string& filename);
        void display(std::ostream& out) const;
    };

}

#endif // SENECA_SONGCOLLECTION_H
