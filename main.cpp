#include <iostream>
#include "LLHashTable.hpp"
#include "BSTHashTable.hpp"
#include "LPHashTable.hpp"
using namespace std;

/**
 * Displays options for the user to select which type of collision
 * method they would like to use
 */
void displayMenu(){
    cout << "Please select a collision method (1-4)" << endl;
    cout << "(1) Linked List Chaining" << endl;
    cout << "(2) Binary Heap Chaining" << endl;
    cout << "(3) Linear Probing" << endl;
    cout << "(4) Cuckoo Hashing" << endl;
}

/**
 * Displays options for the user to select which hash function
 * they would like to use if necessary
 */
void displayHashFunctionChoice(){
    cout << "Please select which hash function to use (1-2)" << endl;
    cout << "(1) Hash Function One" << endl;
    cout << " -- key % tableSize" << endl;
    cout << "(2) Hash Function Two" << endl;
    cout << " -- floor(key/tableSize" << endl;
}

int main(){
    int values[6] = {3, 13, 19, 7, 5, 6};
    int size = 6;
    int collisionMethod;
    int hashFunctionChoice;
    // Get collision method
    displayMenu();
    cin >> collisionMethod;
    while(collisionMethod > 4 || collisionMethod < 1){
        cout << "Invalid input" << endl;
        displayMenu();
        cin >> collisionMethod;
    }
    // Get hash function choice if it applies (does not apply to cuckoo hashing)
    bool choice;
    if(collisionMethod <= 3 && collisionMethod >= 1){
        displayHashFunctionChoice();
        cin >> hashFunctionChoice;
        while(hashFunctionChoice > 2 || hashFunctionChoice < 1){
            cout << "Invalid input" << endl;
            displayHashFunctionChoice();
            cin >> hashFunctionChoice;
        }
        switch(hashFunctionChoice){
            case 1:
                choice = true;
                break;
            case 2:
                choice = false;
                break;
        }
    }
    // Operate on the desired hash table
    cout << "Initializing hash table" << endl;
    // Linked List Chaining
    if(collisionMethod == 1){
        cout << "Linked List Chaining" << endl;
        LLHashTable hashTable(size, choice);
        for(int i=0; i<size; i++){
            hashTable.insertNode(values[i]);
        }
        hashTable.printHashTable();
    }
    // Binary Search Tree Chaining
    else if(collisionMethod == 2){
        cout << "Binary Heap Chaining" << endl;
        return 0;
    }
    // Linear Probing
    else if(collisionMethod == 3){
        cout << "Linear Probing" << endl;
        LPHashTable hashTable(size, choice);
        for(int i=0; i<size; i++){
            hashTable.insertKey(values[i]);
        }
        hashTable.printTable();
        return 0;
    }
    // Cuckoo Hashing
    else{
        cout << "Cuckoo Hashing" << endl;
        return 0;
    }
}