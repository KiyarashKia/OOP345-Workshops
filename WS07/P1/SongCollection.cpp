/***************************************************************************
Full Name  : Kiarash Kia
Student ID#: 108688235
Email      : kkia2@myseneca.ca
Section    : NHH
Authenticity Declaration :
I have done all the coding by myself and only copied the code that my
professor provided to complete my workshops and assignments.
***************************************************************************/

#include "SongCollection.h"
#include <fstream>
#include <sstream>
#include <algorithm>
#include <iomanip>
#include <stdexcept>

namespace seneca {

    // Utility functions defined outside of any class
    void trim(std::string& str) {
        str.erase(0, str.find_first_not_of(' ')); // leading spaces
        str.erase(str.find_last_not_of(' ') + 1); // trailing spaces
    }

    void parseSong(const std::string& record, Song& song) {
        song.title = record.substr(0, 25);
        trim(song.title);
        song.artist = record.substr(25, 25);
        trim(song.artist);
        song.album = record.substr(50, 25);
        trim(song.album);
        try {
            song.releaseYear = std::stoi(record.substr(75, 5));
        }
        catch (...) {
            song.releaseYear = 0; // or a default value
        }
        song.length = std::stoi(record.substr(80, 5));
        song.price = std::stod(record.substr(85));
    }

    // Overloaded operator<< for Song struct
    std::ostream& operator<<(std::ostream& out, const Song& theSong) {
        out << "| " << std::left << std::setw(20) << theSong.title
            << " | " << std::setw(15) << theSong.artist
            << " | " << std::setw(20) << (theSong.album.empty() ? "[None]" : theSong.album)
            << " | " << std::right << std::setw(6) << (theSong.releaseYear ? std::to_string(theSong.releaseYear) : "")
            << " | " << theSong.length / 60 << ":" << std::setfill('0') << std::setw(2) << theSong.length % 60
            << " | " << std::setfill(' ') << std::fixed << std::setprecision(2) << theSong.price
            << " |";
        return out;
    }

    SongCollection::SongCollection(const std::string& filename) {
        std::ifstream file(filename);
        if (!file) {
            throw std::runtime_error("Could not open file " + filename);
        }
        std::string line;
        while (std::getline(file, line)) {
            if (line.size() > 85) { // Ensures there's enough data for a song
                Song song;
                parseSong(line, song);
                songs.push_back(song);
            }
        }
    }

    void SongCollection::display(std::ostream& out) const {
        std::for_each(songs.begin(), songs.end(), [&out](const Song& song) {
            out << song << std::endl;
            });
    }

} // namespace seneca