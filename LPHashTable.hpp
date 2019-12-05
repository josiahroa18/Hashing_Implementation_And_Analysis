#ifndef LPHASHTABLE_H
#define LPHASHTABLE_H

#include <iostream>
#include <cmath>
using namespace std;

/**
 * This is a hash table implementation
 * - Collisions will be handled using Linear Probing 
 */

class LPHashTable{
    private:
        int TABLE_SIZE;
        int *hashTable;
        bool functionOne;
        int keyCount;
        float loadFactor;
    public:
        LPHashTable(int tableSize, bool hashFunction);
        ~LPHashTable();
        int hashFunctionOne(int key);
        int hashFunctionTwo(int key);
        void printTable();
        void insertKey(int key);
        int searchKey(int key);
        void deleteKey(int key);
        float getLoadFactor();
};

#endif