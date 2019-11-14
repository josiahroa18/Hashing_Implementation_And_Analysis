#include <iostream>
#include "LLHashTable.hpp"
#include "RBT.hpp"
using namespace std;

// TODO: add a boolean parameter for which hash function to use
// TODO : https://www.geeksforgeeks.org/red-black-tree-set-1-introduction-2/ implement red-black tree chaining

int main(){
    int values[6] = {3, 13, 19, 7, 5, 6};

    // LL Hash Table Collision Resolution Implementation
    // LLHashTable hashTable;
    // for(int i=0; i<6; i++){
    //     cout << "Inserting: " << values[i] << endl;
    //     hashTable.insertNode(values[i]);
    // }
    // hashTable.printHashTable();
    // hashTable.deleteNode(1);
    // hashTable.deleteNode(6);
    // hashTable.deleteNode(19);
    // hashTable.printHashTable();

    // RBT Test Cases
    RBT tree;
    tree.insert(7);
    tree.insert(6);
    tree.insert(2);
    tree.insert(4);
    tree.insert(3);
    tree.insert(5);
    tree.insert(1);
    tree.printRBT();

}