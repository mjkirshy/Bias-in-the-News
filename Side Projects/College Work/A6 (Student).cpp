/**
 * a6.cpp
 * Name: Ryan Smith
 * Person number: 50067030
 *
 * All definitions of functions required for A6 are contained in here.
 * Feel free to add more function definitions to this, but you must
 * include at least the required functions.
 *
 * You may only use the following headers:
 *  <algorithm>, <cstring>, <array>, <deque>, <forward_list>,
 *  <list>, <map>, <queue>, <set>, <stack>, <unordered_map>,
 *  <unordered_set>, <vector>, "A6.hpp"
 */

#include "a6.hpp"
#include <algorithm>
#include <cstring>
#include <array>
#include <map>
#include <vector>

//#include <iostream>


//std::map<int, std::string> StringStore::swapPair(std::map<std::string, int>) {
//
//    std::pair<int, std::string> holder;
//    auto iter = compMap.begin();
//    while (iter != compMap.end()) {
//        holder = std::make_pair((*iter).second, (*iter).first);
//        reverseMap[holder.first] = holder.second;
////        reverseMap[(*iter).second] = (*iter).first;
//        iter++;
//    }
//    auto rCheck = reverseMap.rbegin();
//    std::cout << "rCheck: " << (*rCheck).first << " --- " << (*rCheck).second << std::endl;
//    return reverseMap;
//}

void StringStore::insert(const std::string& doc) {

    // create the iterator //
    std::map<std::string, int>::iterator iter;
    iter = compMap.find(doc);
    // conduct a find on the map to see if the value exists
    if (iter == compMap.end()) {
        // if it doesn't exist, add it with a value of 1 //
        compMap[doc] = 1;
    }
    else {
        // if it exists, ++ //
        (*iter).second += 1;
    }
}

size_t StringStore::getFrequency(const std::string& doc) const {

    // create the iterator //
    std::map<std::string, int>::iterator iter;
    std::map<std::string, int> getFreqMap = this->compMap;
    iter = getFreqMap.find(doc);
    if (iter == getFreqMap.end()) {
        return 0;
    }
    else {
        return (*iter).second;
    }
}

bool StringStore::removeString(const std::string& doc) {

    // create the iterator //
    std::map<std::string, int>::iterator iter;
    iter = compMap.find(doc);
    if (iter == compMap.end()) {
        return false;
    }
    else {
        compMap.erase((iter));
        return true;
    }
}

std::vector<std::pair<int, std::string>> StringStore::pushtoVector() {

    std::vector<std::pair<int, std::string>> ans;
    std::pair<int, std::string> temp;
    for (std::map<std::string, int>::iterator it = compMap.begin(); it != compMap.end(); ++it) {
        temp = std::make_pair((*it).second, (*it).first);
        ans.push_back(temp);
    }
    std::sort(ans.rbegin(), ans.rend());

//    for (auto iter = ans.begin(); iter != ans.end(); ++iter) {
//        std::cout << (*iter).first << "-";
//    }

    return ans;
}

std::pair<std::string, size_t> StringStore::getMaxFrequency() {

    compVector = pushtoVector();
    std::pair<std::string, size_t> ans = std::make_pair("", 0);
    if (compMap.empty() == true) {
        return std::pair<std::string, size_t>("", 0);
    }
    else {
        return std::make_pair(compVector.at(0).second, compVector.at(0).first);
    }
}

std::vector<std::pair<std::string, size_t>> StringStore::getTopKFrequency(size_t k) {

    compVector = pushtoVector();
    std::vector<std::pair<std::string, size_t>> ans;
    std::pair<std::string, size_t> temp = std::make_pair("", 0);
    size_t count = 0;
    if (compMap.empty() == true) {
        return ans;
    }
    else {
        while (count < k) {
            temp = std::make_pair(compVector.at(count).second, compVector.at(count).first);
            ans.push_back(temp);
            count++;
        }

//        std::cout << "topK size (should be = to k) : " << ans.size() << std::endl;
//        for (auto iter = ans.begin(); iter != ans.end(); ++iter) {
//            std::cout << (*iter).second << " ";
//        }
        return ans;
    }
}