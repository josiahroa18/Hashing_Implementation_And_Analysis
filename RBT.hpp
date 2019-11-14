#include <iostream>
#include <queue>
using namespace std;

#ifndef RBT_H
#define RBT_H

struct RBTnode{
    int key;
    string color; //true for red, false for black
    RBTnode *left, *right, *parent;
};

class RBT{
    private:
        RBTnode* root;
    public:
        RBT();
        RBTnode* createRBTnode(int key);
        void insert(int key);
        void printRBT();
};

#endif