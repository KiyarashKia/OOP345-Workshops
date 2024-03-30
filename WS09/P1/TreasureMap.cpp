#include <iostream>
#include <fstream>
#include <string>
#include "TreasureMap.h"

namespace seneca{

    size_t digForTreasure(const std::string& str, char mark){
        size_t cnt = 0;
        for (auto& x : str){
            if (x == mark){
                cnt++;
            }
        }
        return cnt;
    }

    TreasureMap::TreasureMap(const char* filename){
        std::fstream fin(filename);
        if (fin){
            fin >> rows;
            fin.ignore();
            map = new std::string[rows];
            size_t idx = 0;
            while(fin){
                getline(fin, map[idx]);
                idx++;
            }
            colSize = map[0].length();
        }
        else {
            throw std::string(filename) + " cannot be opened";
        }
    }

    TreasureMap::~TreasureMap(){
        delete [] map;
    }

    std::ostream& TreasureMap::display(std::ostream& os) const{
        if (map){
            for (size_t i = 0; i < rows; ++i){
                os << map[i] << std::endl;
            }
        }
        else 
            os << "The map is empty!" << std::endl;
        return os;
    }

    void TreasureMap::enscribe(const char* filename){
        // Binary write

        std::ofstream outFile(filename, std::ios::binary);
        if (!outFile) throw std::string(filename) + " cannot be opened";

        if (map){ 
          outFile.write(reinterpret_cast<const char*>(&rows), sizeof(rows));
          outFile.write(reinterpret_cast<const char*>(&colSize), sizeof(colSize));
            for (size_t i = 0; i < rows; ++i)
            {
                outFile.write(map[i].c_str(), map[i].length());

            }
        }
        else{
            throw std::string("Treasure map is empty!");
        }

    }

    void TreasureMap::recall(const char* filename){ clear();
        std::ifstream inFile(filename, std::ios::binary);
        if (!inFile) throw std::string(filename) + " cannot be opened";

        clear();

        inFile.read(reinterpret_cast<char*>(&rows), sizeof(rows));
        inFile.read(reinterpret_cast<char*>(&colSize), sizeof(colSize));
    
        map = new std::string[rows];
        char* buffer = new char[colSize + 1];
        buffer[colSize] = '\0';
        for (size_t i = 0; i < rows; ++i) {
            inFile.read(buffer, colSize);
            map[i] = std::string(buffer, colSize);
        }

        delete[] buffer;

    }

    void TreasureMap::clear(){
        delete [] map;
        map = nullptr;
        rows = 0;
        colSize = 0;
    }

    size_t TreasureMap::findTreasure(char mark){
        size_t count = 0;

        // TODO: For part 2, comment this "for" loop and write the multihreaded version.
        for (size_t i = 0; i < rows; ++i){
            count += digForTreasure(map[i], mark);
        }

        return count;
    }
}