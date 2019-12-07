#include <iostream>
#include <cmath>
using namespace std;

#ifndef LLHASHTABLE_H
#define LLHASHTABLE_H

/**
 * This is a hash table implementation
 * - Collisions will be handled using chaining by Linked Lists
 */

struct node{
    int key;
    node* next;
};

class LLHashTable{
    private:
        int TABLE_SIZE;
        node* *LLhashTable;
        node* createLLNode(int key);
        bool functionOne;
        int keyCount;
        float loadFactor;
    public:
        LLHashTable(int tableSize, bool hashFunction);
        ~LLHashTable();
        // Hashing functions
        int hashFunctionOne(int key);
        int hashFunctionTwo(int key);
        void printHashTable();
        node* searchTable(int key);
        void insertNode(int key);
        void deleteNode(int key);
        float getLoadFactor();
        int countAtIndex(int i);
        int getTableSize();
};

#endif