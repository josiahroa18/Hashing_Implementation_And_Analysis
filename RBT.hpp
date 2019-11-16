#include <iostream>
#include <queue>
using namespace std;

#ifndef RBT_H
#define RBT_H

//Sources for help: https://www.geeksforgeeks.org/c-program-red-black-tree-insertion/

struct RBTnode{
    int key;
    string color; //true for red, false for black
    RBTnode *left, *right, *parent;
};

class RBT{
    private:
        RBTnode* root;
    protected:
        void rotateLeft(RBTnode* &root, RBTnode* &newNode);
        void rotateRight(RBTnode* &root, RBTnode* &newNode);
        void reBalance(RBTnode* &root, RBTnode* &newNode);
    public:
        RBT();
        RBTnode* createRBTnode(int key);
        void insert(const int &key);
        void printRBT();
};

#endif