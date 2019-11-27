#ifndef BSTHASHTABLE_H
#define BSTHASHTABLE_H

#include <iostream>
#include <cmath>
using namespace std;

/**
 * This is a hash table implementation
 * - Collisions will be handled using chaining by Binary Search Tree 
 */

struct BSTNode{
    int key;
    BSTNode* parent;
    BSTNode* left;
    BSTNode* right;
};

class BSTHashTable{
    private:
        BSTNode* *table;
        BSTNode* createBSTNode(int key);
        int TABLE_SIZE;
        bool functionOne;
    public:
        BSTHashTable(int tableSize, bool hashFunction);
        ~BSTHashTable();
        int hashFunctionOne(int key);
        int hashFunctionTwo(int key);
        void printHashTable();
        BSTNode* searchTable(int key);
        void insertNode(int key);
        void deleteNode(int key);
};

#endif