/**
 * DataStore.hpp
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

#ifndef _DATA_STORE_HPP_
#define _DATA_STORE_HPP_

#include <string>
#include <map>
#include <vector>

class DataStore {

    int storageArr[2001] = {0};
    int thousand = 1000;
    std::map<int, int> mapper;
    std::map<int, int>::iterator _iter;


public:
    /**
     * Construct an empty DataStore.
     */
    DataStore();

    /**
     * Construct a DataStore that was saved to a file.
     * @param filename - name of file containing data to load.
     */
    DataStore(std::string filename);

    /**
     * Destructor: cleanup any allocated memory.
     */
    ~DataStore();

    /**
     * (disabled) Copy constructor -- create a new object as a copy of another.
     */
    DataStore(const DataStore &other) = delete;

    /**
     * (disabled) Copy assignment -- copy another object into this object.
     */
    DataStore &operator=(const DataStore &rhs) = delete;

    /**
     * (disabled) Move constructor -- create a new object with the data of another.
     */
    DataStore(DataStore &&other) = delete;

    /**
     * (disabled) Move assignment -- move data from other object to this object.
     */
    DataStore &operator=(DataStore &&rhs) = delete;

    /**
     * Add a value to our storage.
     * @param value - The value to add.
     */
    void add_value(const int &value);

    /**
     * Remove a value from storage, if it exists.
     * @param value - The value to remove.
     * @return true if the value was successfully removed and
     *         false otherwise.
     */
    bool remove_value(const int &value);

    /**
     * Get the number of entries for a particular value.
     * @param value - The value to count occurrences of.
     * @return The number of times the value was entered.
     */
    int get_count(const int &value);

    /**
     * Create a space separated string of stored data as a single line.
     */
    std::string to_string();

    /**
     * Write out the data stored to a file.
     * @param filename - The name of the file to write to.
     */
    void write_out(std::string filename);

//    void parse(std::string);

};//DataStore
#endif


/////