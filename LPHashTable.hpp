#ifndef LPHASHTABLE_H
#define LPHASHTABLE_H

#include <iostream>
#include <cmath>
using namespace std;

struct LPNode{
    int key;
    int index;
};

class LPHashTable{
    private:
        int TABLE_SIZE;
        LPNode* *hashTable;
        bool functionOne;
    public:
        LPHashTable(int tableSize, bool hashFunction);
        ~LPHashTable();
        int hashFunctionOne(int key);
        int hashFunctionTwo(int key);
        LPNode* createNode(int key, int index);
        void printTable();
        void insertKey(int key);
        LPNode* searchKey(int key);
        void deleteKey(int key);
};

#endif