#include <iostream>
#include "RBT.hpp"
using namespace std;

#ifndef RBTHASHTABLE_H
#define RBTHASHTABLE_H

class RBTHashTable{
    private:
        int TABLE_SIZE;
        RBT RBThashTable;
    public:
        RBTHashTable();
        ~RBTHashTable();
        int hashFunctionOne(int key);
        int hashFunctionTwo(int key);
        void printHashTable();
        node* searchTable();
};

#endif