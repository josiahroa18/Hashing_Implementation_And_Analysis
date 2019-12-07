#ifndef BSTHASHTABLE_H
#define BSTHASHTABLE_H

#include <iostream>
#include <cmath>
#include <queue>
using namespace std;

/**
 * This is a hash table implementation
 * - Collisions will be handled using chaining by Binary Search Tree 
 */

struct BSTNode{
    int key;
    BSTNode* left;
    BSTNode* right;
};

class BSTHashTable{
    private:
        BSTNode* *BSThashTable;
        int TABLE_SIZE;
        bool functionOne;
        int keyCount;
        float loadFactor;
    public:
        BSTHashTable(int tableSize, bool hashFunction);
        ~BSTHashTable();
        int hashFunctionOne(int key);
        int hashFunctionTwo(int key);
        void printHashTable();
        void printSearch(int key);
        BSTNode* searchTable(int key);
        void insertNode(int key);
        void deleteNode(int key);
        float getLoadFactor();
        int countAtIndex(int i);
        int getTableSize();
};

#endif