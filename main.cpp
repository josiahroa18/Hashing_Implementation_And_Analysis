#include <iostream>
#include "LLHashTable.hpp"
using namespace std;

// TODO: add a boolean parameter for which hash function to use
// TODO : https://www.geeksforgeeks.org/red-black-tree-set-1-introduction-2/ implement red-black tree chaining

int main(){
    int values[6] = {3, 13, 19, 7, 5, 6};
    LLHashTable hashTable;
    for(int i=0; i<6; i++){
        cout << "Inserting: " << values[i] << endl;
        hashTable.insertNode(values[i]);
    }
    hashTable.printHashTable();
    hashTable.deleteNode(1);
    hashTable.deleteNode(6);
    hashTable.deleteNode(19);
    hashTable.printHashTable();
}