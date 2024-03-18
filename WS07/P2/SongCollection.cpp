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
#include <numeric>

namespace seneca {


    void trim(std::string& str) {
        str.erase(0, str.find_first_not_of(' '));
        str.erase(str.find_last_not_of(' ') + 1);
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
            song.releaseYear = 0;
        }
        song.length = std::stoi(record.substr(80, 5));
        song.m_price = static_cast<float>(std::stod(record.substr(85)));
    }

  
    std::ostream& operator<<(std::ostream& out, const Song& theSong) {
        int min = theSong.length / 60;
        int sec = theSong.length % 60;
        out << "| " << std::left << std::setw(20) << theSong.title
            << " | " << std::setw(15) << theSong.artist
            << " | " << std::setw(20) << (theSong.album.empty() ? "[None]" : theSong.album)
            << " | " << std::right << std::setw(6) << (theSong.releaseYear ? std::to_string(theSong.releaseYear) : "")
            << " | " << min << ":" << std::setfill('0') << std::setw(2) << sec
            << " | " << std::setfill(' ') << std::fixed << std::setprecision(2) << theSong.m_price
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
            if (line.size() > 85) {
                Song song;
                parseSong(line, song);
                songs.push_back(song);
            }
        }
    }

    // Need adjustment as descriptionnn of ws
    void SongCollection::display(std::ostream& out) const {
        std::for_each(songs.begin(), songs.end(), [&out](const Song& song) {
            out << song << '\n';
            });
        auto totalLength = std::accumulate(songs.begin(), songs.end(), static_cast<size_t>(0),
            [](size_t sum, const Song& song) { return sum + song.length; });
        int hour = totalLength / 3600;
        int min = (totalLength % 3600) / 60;
        int sec = totalLength % 60;
        out << "----------------------------------------------------------------------------------------\n";
        out << "|                                                        Total Listening Time:"
            << std::setw(2) << std::setfill(' ') << hour << ":"
            << std::setw(2) << std::setfill('0') << min << ":"
            << std::setw(2) << std::setfill('0') << sec << " |\n";
        out << "----------------------------------------------------------------------------------------\n";
    }

    void SongCollection::sort(const std::string& field) {
        if (field == "title")
            std::sort(songs.begin(), songs.end(), [](const Song& a, const Song& b) { return a.title < b.title; });
        else if (field == "album")
            std::sort(songs.begin(), songs.end(), [](const Song& a, const Song& b) { return a.album < b.album; });
        else if (field == "length")
            std::sort(songs.begin(), songs.end(), [](const Song& a, const Song& b) { return a.length < b.length; });
    }


    void SongCollection::cleanAlbum() {
        std::for_each(songs.begin(), songs.end(), [](Song& song) {
            if (song.album == "[None]") song.album = "";
            });
    }

    bool SongCollection::inCollection(const std::string& artist) const {
        return std::any_of(songs.begin(), songs.end(), [&artist](const Song& song) {
            return song.artist == artist;
            });
    }

    std::list<Song> SongCollection::getSongsForArtist(const std::string& artist) const {
        std::list<Song> artistSongs;
        std::copy_if(songs.begin(), songs.end(), std::back_inserter(artistSongs), [&artist](const Song& song) {
            return song.artist == artist;
            });
        return artistSongs;
    }
} // namespace seneca