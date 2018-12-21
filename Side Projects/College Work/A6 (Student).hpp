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

#ifndef A6_STRINGSTORE_HPP
#define A6_STRINGSTORE_HPP

#include <string>
#include <vector>
#include <map>

class StringStore {

public:

    std::map<std::string, int> compMap;

    std::vector<std::pair<int, std::string>> compVector;

    void insert(const std::string&);

    size_t getFrequency(const std::string&) const;

    bool removeString(const std::string&);

    std::vector<std::pair<int, std::string>> pushtoVector();

    std::pair<std::string, size_t> getMaxFrequency() ;

    std::vector<std::pair<std::string, size_t>> getTopKFrequency(size_t k);
};


#endif //A6_STRINGSTORE_HPP
