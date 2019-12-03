#ifndef CHHASHTABLE_H
#define CHHASHTABLE_H

#include <iostream>
#include <cmath>
#include <vector>
using namespace std;

/**
 * This is a hash table implementation
 * - Collisions will be handled using Cuckoo Hashing
 */

class CHHashTable{
    private:
        int TABLE_SIZE;
        int* tableOne;
        int* tableTwo;
        int reHashCount;
        int keyCount;
        float loadFactor;
        vector<int> deletedValues;
        
    public:
        CHHashTable(int tableSize);
        ~CHHashTable();
        int hashFunctionOne(int key);
        int hashFunctionTwo(int key);
        void insert(int key);
        void reHash();
        void printTable();
        void searchValue(int key);
        void deleteValue(int key);
        float getLoadFactor();
        int getreHashCount();
};

#endif