/**
 * DataStore.cpp
 *
 * Copyright 2018 Andrew Hughes (ahughes6@buffalo.edu)
 *
 * This work is licensed under the Creative Commons 
 * Attribution-NonCommercial-ShareAlike 4.0 International License.
 * To view a copy of this license, visit
 * http://creativecommons.org/licenses/by-nc-sa/4.0/.
 *
 * Submission by
 * UBIT: 
 * Person#: 
 */

#include <algorithm>
#include <sstream>
#include <fstream>
#include "DataStore.hpp"

/**
 * Construct an empty DataStore.
 */



DataStore::DataStore() {

//    for (int i = 0; i < 2001; i++) {
//        storageArr[i] = 0;
//    }
}

/**
 * Construct a DataStore that was saved to a file.
 * @param filename - name of file containing data to load.
 */
//void DataStore::parse(std::string line) {
//
//    int comma, value, count;
//    comma = line.find(',');
//    value = std::stoi(line.substr(0, comma));
//    count = std::stoi(line.substr(comma + 1, line.length()));
//    mapper[value];
//    while (count > 1) {
//        mapper[value]++;
//        count--;
//    }
//}

DataStore::DataStore(std::string filename) {

    std::ifstream readFile;
    std::string line;
    int value;
    readFile.open(filename);
    if (readFile.is_open()) {
        while (std::getline(readFile, line)) {
            if (line.length() > 0) {
                value = std::stoi(line);
//                mapper[value]++;
                storageArr[value + thousand]++;
            } else {
                break;
            }
        }
    }
    readFile.close();
}

DataStore::~DataStore() {}

void DataStore::add_value(const int &value) {
    storageArr[value + thousand]++;
//    mapper[value]++;
}

bool DataStore::remove_value(const int &value) {

    if (storageArr[value + thousand] > 0) {
        storageArr[value + thousand] = 0;
        return true;
    } else {
        return false;
    }

//    _iter = mapper.find(value);
//    if (_iter != mapper.end()) {
//        mapper.erase(_iter);
//        return true;
//    }
//    return false;
}

int DataStore::get_count(const int &value) {

    return storageArr[value + thousand];
//    _iter = mapper.find(value);
//    return (*_iter).second;
}

std::string DataStore::to_string() {
    std::string result = "";
    int current = 0;
    int counter = 1;

    for (int i = 0; i < 2001; ++i) {
        if (storageArr[i] > 0) {
            current = i - thousand;
            result += std::to_string(current) + " ";
            while (counter < storageArr[i]) {
                result += std::to_string(current) + " ";
                counter++;
            }
            counter = 1;
        }
    }

//    for (_iter = mapper.begin(); _iter != mapper.end(); ++_iter) {
//        int a = (*_iter).first;
//        result += std::to_string((*_iter).first) + " ";
//        if ((*_iter).second > 1) {
//            while (counter < (*_iter).second) {
//                result += std::to_string((*_iter).first) + " ";
//                counter++;
//            }
//            counter = 1;
//        }
//    }
    return result;
}

void DataStore::write_out(std::string filename) {

    std::ofstream outfile;
    outfile.open(filename);
    int count = 1;
    if (outfile.is_open()) {
        for (int i = 0; i < 2001; ++i) {
            if (storageArr[i] > 0) {
                outfile << i - thousand << std::endl;
                if (storageArr[i] > count) {
                    while (count < storageArr[i]) {
                        outfile << i - thousand << std::endl;
                        count++;
                    }
                }
                count = 1;
            }

//        for (_iter = mapper.begin(); _iter != mapper.end(); ++_iter) {
//            outfile << (*_iter).first << std::endl;
//            if ((*_iter).second > count) {
//                while ((*_iter).second > count) {
//                    outfile << (*_iter).first << std::endl;
//                    count++;
//                }
//                count = 1;
//            }
//        }

        }
        outfile.close();
    }
}






