/**
 * a0-skeleton.cpp
 *
 * Copyright 2018 Andrew Hughes (ahughes6@buffalo.edu)
 *
 * This work is licensed under the Creative Commons 
 * Attribution-NonCommercial-ShareAlike 4.0 International License.
 * To view a copy of this license, visit
 * http://creativecommons.org/licenses/by-nc-sa/4.0/.
 *
 */

#include "time_pair.hpp"
#include <fstream>
#include <string>
#include <vector>

cse250::time_pair parseString(std::string line) {

    cse250::time_pair temp;
    temp.time = stoi(line.substr(0, line.find(',')));
    temp.value = stoi(line.substr(line.find(',') + 1, line.length() - 1));
    return temp;
}

std::vector<cse250::time_pair> readFile(std::vector<cse250::time_pair> &hold) {
    std::string line;
    cse250::time_pair temp;
    std::ifstream file;
    file.open("data.csv");
    if (file.is_open()) {
        while (std::getline(file, line)) {
            temp = parseString(line);
            hold.push_back(temp);
        }
    }
    file.close();
    return hold;
}

int64_t findGap(std::vector<cse250::time_pair> &hold) {
    if (hold.size() < 3) {
        return 0;
    }
    int64_t gap = (hold.at(1).time - hold.at(0).time);
    int64_t temp = 0;
    for (int i = 0; i < hold.size() - 1; ++i) {
        temp = hold.at(i + 1).time - hold.at(i).time;
        if (temp < gap) {
            gap = temp;
        }
    }
    return gap;
}

cse250::time_pair computeGap(cse250::time_pair current, cse250::time_pair next, int minGap) {
    cse250::time_pair result;
    // x //
    int x = current.time;
    result.time = x + minGap; // x value for gap
    // y //
    int y = current.value;
    int changeX = next.time - current.time;
    int changeY = next.value - current.value;
    double slope = (1.00 * changeY) / (1.00 * changeX);
    int distance = slope * minGap;
    // complete pair
    result.value = current.value + distance;
    // return pair
    return result;

}

std::vector<cse250::time_pair> findGaps(std::vector<cse250::time_pair> &old, int min_gap) {

    cse250::time_pair current;
    cse250::time_pair next;
    std::vector<cse250::time_pair> completed;

    if (min_gap == 0) {
        return old;
    } else {
        completed.push_back(old.at(0));
        for (int i = 0; i < old.size() - 1; ++i) {
            current = old.at(i);
            next = old.at(i + 1);
            if ((next.time - current.time) <= min_gap) {
                if (completed.back().time != old.at(i).time) {
                    completed.push_back(old.at(i));
                }
            } else {
                if (current.time != completed.back().time) {
                    completed.push_back(current);
                }
                completed.push_back(computeGap(current, next, min_gap));
                if (completed.back().time + min_gap < next.time) {
                    completed.push_back(computeGap(completed.back(), next, min_gap));
                    while (completed.back().time + min_gap < next.time) {
                        completed.push_back(computeGap(completed.back(), next, min_gap));
                    }

                }
            }
        }
        completed.push_back(old.back());
    }
    return completed;
}

void writeFile(std::vector<cse250::time_pair> &final) {

    std::ofstream outfile;
    outfile.open("data-updated.csv");
    if (outfile.is_open()) {
        for (int i = 0; i < final.size(); ++i) {
            outfile << final.at(i).time << "," << final.at(i).value;
            outfile << '\n';
        }
        outfile.close();
    }

}

int main() {
    std::vector<cse250::time_pair> hold;
    readFile(hold);
    int64_t gap = findGap(hold);
    std::vector<cse250::time_pair> check = (findGaps(hold, gap));
    writeFile(check);


}