/***********************************************************************
// Workshop 9 Part 2
// Version 1.0
// Author
// Description
//	Name      : Kiarash Kia
//	Student ID: 108688235
//	Email     : kkia2@myseneca.ca
//
//
//	I have done all the coding by myself and only copied the code
//	 that my professor provided to complete my workshops and
//	 assignments.
// Revision History
// -----------------------------------------------------------
// Name                 Date            Reason
***********************************************************************/
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <thread>
#include <future>
#include <functional>
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


        // TODO: For part 2, comment this "for" loop and write the multihreaded version.
        //for (size_t i = 0; i < rows; ++i){
        //    count += digForTreasure(map[i], mark);
        //}

    size_t TreasureMap::findTreasure(char mark) {
        const size_t numThreads = 4;
        std::vector<std::future<size_t>> futures;
        size_t partitionSize = rows / numThreads;
        size_t extraRows = rows % numThreads;

        for (size_t i = 0; i < numThreads; ++i) {
            size_t start = i * partitionSize + std::min(i, extraRows);
            size_t end = start + partitionSize + (i < extraRows ? 1 : 0);

            std::string mapSegment;
            for (size_t j = start; j < end; ++j) {
                mapSegment += map[j];
            }

            auto boundTask = std::bind(digForTreasure, mapSegment, mark);
            std::packaged_task<size_t()> task(std::move(boundTask));
            futures.push_back(task.get_future());

            std::thread th(std::move(task));
            th.detach();
        }

        size_t totalTreasure = 0;
        for (auto& fut : futures) {
            totalTreasure += fut.get();
        }

        return totalTreasure;
    }

}