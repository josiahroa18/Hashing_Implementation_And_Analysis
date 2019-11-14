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
    public:
        LLHashTable();
        ~LLHashTable();
        // Hashing functions
        int hashFunction(int key);
        void printHashTable();
        node* searchTable(int key);
        void insertNode(int key);
        void deleteNode(int key);
};

#endif