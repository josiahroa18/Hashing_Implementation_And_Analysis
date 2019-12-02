#include <iostream>
#include <fstream>
#include <ctime>
#include <iomanip>
#include "LLHashTable.hpp"
#include "BSTHashTable.hpp"
#include "LPHashTable.hpp"
#include "CHHashTable.hpp"
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

/**
 * Displays configuration for performance evaluation
 */
void displayConfiguration(bool choice, int collisionMethod){
    cout << "--- Configuration ---" << endl;
    cout << "Collision Method: ";
    switch(collisionMethod){
        case 1:
            cout << "Linked List Chaining" << endl;
            break;
        case 2:
            cout << "Binary Search Tree Chaining" << endl;
            break;
        case 3:
            cout << "Linear Probing" << endl;
            break;
        case 4:
            cout << "Cuckoo Hashing" << endl;
    }
    cout << "Hash Function: ";
    if(choice){
        cout << "One - key % TABLE_SIZE" << endl;
    }else{
        cout << "Two - floor(key/TABLE_SIZE)" << endl;
    }
}

int main(){
    // Read in values from dataSet and store into array
    cout << "Reading in data set" << endl;
    int size = 10009;
    int values[40000];
    string valueS;
    int value;
    ifstream myFile;
    myFile.open("dataSetA.csv");
    int i=0;
    while(getline(myFile, valueS, ',')){
        value = stoi(valueS);
        values[i] = value;
        i++;
    }
    cout << "Data set loaded" << endl;

    // Used for timing methods at different load factors
    float loadFactors[6] = {0.1, 0.2, 0.5, 0.7, 0.9, 1.0};
    int loadFactorsCount = 6;
    int startTime, endTime;
    double execTime, insertTime, lookUpTime, deleteTime;

    // Get collision method
    int collisionMethod;
    int hashFunctionChoice;
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
        //Insert values until we reach a desired load factor
        int i=0;
        int loadFactorSelection;
        for(int j=0; j<loadFactorsCount; j++){
            cout.precision(1);
            cout << fixed;
            while(hashTable.getLoadFactor() < loadFactors[loadFactorSelection]){
                hashTable.insertNode(values[i]);
                i++;
            }
            cout << "---" << hashTable.getLoadFactor() << "---" << endl;
            // Insert 100 values
            cout.precision(7);
            cout << fixed;
            startTime = clock();
            for(int k=0; k<100; k++){
                hashTable.insertNode(values[i]);
                i++;
            }
            endTime = clock();
            execTime = (double)(endTime-startTime)/CLOCKS_PER_SEC;
            cout << "execution time for insertion: " << execTime << endl;
            insertTime = execTime;
            // Lookup 100 values
            startTime = clock();
            i -= 100;
            for(int k=0; k<100; k++){
                hashTable.searchTable(values[i]);
                i++;
            }
            endTime = clock();
            execTime = (double)(endTime-startTime)/CLOCKS_PER_SEC;
            cout << "execution time for lookup: " << execTime << endl;
            lookUpTime = execTime;
            // Delete 100 values
            startTime = clock();
            i -= 100;
            for(int k=0; k<100; k++){
                hashTable.deleteNode(values[i]);
                i++;
            }
            i -= 100;
            endTime = clock();
            execTime = (double)(endTime-startTime)/CLOCKS_PER_SEC;
            cout << "execution time for deletion: " << execTime << endl;
            deleteTime = execTime;
            loadFactorSelection++;
            cout << "Average time: " << (float)(insertTime + lookUpTime + deleteTime)/3.0 << endl;
        }
        displayConfiguration(choice, collisionMethod);
        return 0;
    }
    // Binary Search Tree Chaining
    else if(collisionMethod == 2){
        cout << "Binary Heap Chaining" << endl;
        BSTHashTable hashTable(size, choice);
        int i=0;
        int loadFactorSelection;
        for(int j=0; j<loadFactorsCount; j++){
            cout.precision(1);
            cout << fixed;
            while(hashTable.getLoadFactor() < loadFactors[loadFactorSelection]){
                hashTable.insertNode(values[i]);
                i++;
            }
            cout << "---" << hashTable.getLoadFactor() << "---" << endl;
            // Insert 100 values
            cout.precision(7);
            cout << fixed;
            startTime = clock();
            for(int k=0; k<100; k++){
                hashTable.insertNode(values[i]);
                i++;
            }
            endTime = clock();
            execTime = (double)(endTime-startTime)/CLOCKS_PER_SEC;
            cout << "execution time for insertion: " << execTime << endl;
            insertTime = execTime;
            // Lookup 100 values
            startTime = clock();
            i -= 100;
            for(int k=0; k<100; k++){
                hashTable.searchTable(values[i]);
                i++;
            }
            endTime = clock();
            execTime = (double)(endTime-startTime)/CLOCKS_PER_SEC;
            cout << "execution time for lookup: " << execTime << endl;
            lookUpTime = execTime;
            // Delete 100 values
            startTime = clock();
            i -= 100;
            for(int k=0; k<100; k++){
                hashTable.deleteNode(values[i]);
                i++;
            }
            i -= 100;
            endTime = clock();
            execTime = (double)(endTime-startTime)/CLOCKS_PER_SEC;
            cout << "execution time for deletion: " << execTime << endl;
            deleteTime = execTime;
            cout << "Average time: " << (float)(insertTime + lookUpTime + deleteTime)/3.0 << endl;
            loadFactorSelection++;
        }
        displayConfiguration(choice, collisionMethod);
        return 0;
    }
    // Linear Probing
    else if(collisionMethod == 3){
        cout << "Linear Probing" << endl;
        LPHashTable hashTable(size, choice);
        int i=0;
        int loadFactorSelection;
        for(int j=0; j<loadFactorsCount; j++){
            cout.precision(1);
            cout << fixed;
            while(hashTable.getLoadFactor() < loadFactors[loadFactorSelection]){
                hashTable.insertKey(values[i]);
                i++;
            }
            cout << "---" << hashTable.getLoadFactor() << "---" << endl;
            // Insert 100 values
            cout.precision(7);
            cout << fixed;
            startTime = clock();
            for(int k=0; k<100; k++){
                hashTable.insertKey(values[i]);
                i++;
            }
            endTime = clock();
            execTime = (double)(endTime-startTime)/CLOCKS_PER_SEC;
            cout << "execution time for insertion: " << execTime << endl;
            insertTime = execTime;
            // Lookup 100 values
            startTime = clock();
            i -= 100;
            for(int k=0; k<100; k++){
                hashTable.searchKey(values[i]);
                i++;
            }
            endTime = clock();
            execTime = (double)(endTime-startTime)/CLOCKS_PER_SEC;
            cout << "execution time for lookup: " << execTime << endl;
            lookUpTime = execTime;
            // Delete 100 values
            startTime = clock();
            i -= 100;
            for(int k=0; k<100; k++){
                hashTable.deleteKey(values[i]);
                i++;
            }
            i -= 100;
            endTime = clock();
            execTime = (double)(endTime-startTime)/CLOCKS_PER_SEC;
            cout << "execution time for deletion: " << execTime << endl;
            deleteTime = execTime;
            cout << "Average time: " << (float)(insertTime + lookUpTime + deleteTime)/3.0 << endl;
            loadFactorSelection++;
        }
        displayConfiguration(choice, collisionMethod);
        return 0;
    }
    // Cuckoo Hashing
    else{
        cout << "Cuckoo Hashing" << endl;
        CHHashTable hashTable(size);
        return 0;
    }
}