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
 * TODO: Implement a values vs index output
 * TODO: Finish commenting code
 */

/**
 * Displays options for the user to select which type of collision
 * method they would like to use
 */
void displayMenu(){
    cout << "Please select a collision method (1-4)" << endl;
    cout << "(1) Linked List Chaining" << endl;
    cout << "(2) Binary Search Tree Chaining" << endl;
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

/**
 * Displays the data in terminal to make it easier for copying data over to graph
 */
void displayData(float insertData[], float lookUpData[], float deleteData[], int size){
    cout << "--- Data ---" << endl;
    cout << "Insert Data: [";
    for(int i=0; i<size; i++){
        cout << insertData[i];
        if(i != size-1){
            cout << ", ";
        }
    }
    cout << "]" <<  endl;
    cout << "Look Up Data: [";
    for(int i=0; i<size; i++){
        cout << lookUpData[i];
        if(i != size-1){
            cout << ", ";
        }
    }
    cout << "]" << endl;
    cout << "Delete Data: [";
    for(int i=0; i<size; i++){
        cout << deleteData[i];
        if(i != size-1){
            cout << ", ";
        }
    }
    cout << "]" <<  endl;
}

int main(int argc, char* argv[]){
    // Read in values from dataSet and store into array
    cout << "Reading in data set" << endl;
    int size = 10009;
    int values[40000];
    int valueSize = 40000;
    string valueS;
    int value;
    ifstream myFile;
    myFile.open(argv[1]);
    int i=0;
    while(getline(myFile, valueS, ',')){
        value = stoi(valueS);
        values[i] = value;
        i++;
    }
    myFile.close();
    cout << "Data set loaded" << endl;

    // Used for timing methods at different load factors
    float loadFactors[6] = {0.1, 0.2, 0.5, 0.7, 0.9, 1.0};
    float CHloadFactors[6] = {0.1, 0.2, 0.3, 0.4, 0.5, 0.7};
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

    float insertData[6];
    float lookUpData[6];
    float deleteData[6];

    // Operate on the desired hash table
    cout << "Initializing hash table" << endl;
    // Linked List Chaining
    if(collisionMethod == 1){
        cout << "Linked List Chaining" << endl;
        LLHashTable hashTable(size, choice);
        //Insert values until we reach a desired load factor
        int i=0;
        int loadFactorSelection = 0;
        int append = 0;
        for(int j=0; j<loadFactorsCount; j++){
            cout.precision(1);
            cout << fixed;
            while(hashTable.getLoadFactor() < loadFactors[loadFactorSelection]){
                hashTable.insertNode(values[i]);
                i++;
            }
            cout << "---" << hashTable.getLoadFactor() << "---" << endl;
            // Insert 100 values
            cout.precision(6);
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
            insertData[append] = insertTime;
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
            lookUpData[append] = lookUpTime;
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
            deleteData[append] = deleteTime;
            loadFactorSelection++;
            cout << "Average time: " << (float)(insertTime + lookUpTime + deleteTime)/3.0 << endl;
            append++;
        }
        displayConfiguration(choice, collisionMethod);
        displayData(insertData, lookUpData, deleteData, 6);
        // Collect data for data set evaluation
        cout << "--- Inserting all values into new table for data set evaluation ---" << endl;
        LLHashTable dataTable(size, choice);
        for(int i=0; i<valueSize; i++){
            dataTable.insertNode(values[i]);
        }
        // Check how many values are in each index and write to file
        ofstream dataFile;
        dataFile.open("LLdataFile.txt");
        for(int i=0; i<100; i++){
            dataFile << dataTable.countAtIndex(i) << endl;
        }
        dataFile.close();
        return 0;
    }
    // Binary Search Tree Chaining
    else if(collisionMethod == 2){
        cout << "Binary Heap Chaining" << endl;
        BSTHashTable hashTable(size, choice);
        int i=0;
        int loadFactorSelection = 0;
        int append = 0;
        for(int j=0; j<loadFactorsCount; j++){
            cout.precision(1);
            cout << fixed;
            while(hashTable.getLoadFactor() < loadFactors[loadFactorSelection]){
                hashTable.insertNode(values[i]);
                i++;
            }
            cout << "---" << hashTable.getLoadFactor() << "---" << endl;
            // Insert 100 values
            cout.precision(6);
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
            insertData[append] = insertTime;
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
            lookUpData[append] = lookUpTime;
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
            deleteData[append] = deleteTime;
            cout << "Average time: " << (float)(insertTime + lookUpTime + deleteTime)/3.0 << endl;
            loadFactorSelection++;
            append++;
        }
        displayConfiguration(choice, collisionMethod);
        displayData(insertData, lookUpData, deleteData, 6);
        cout << "--- Inserting all values into new table for data set evaluation ---" << endl;
        BSTHashTable dataTable(size, choice);
        for(int i=0; i<valueSize; i++){
            dataTable.insertNode(values[i]);
        }
        //Check how many values are in each index and write to file
        ofstream dataFile;
        dataFile.open("BSTdataFile.txt");
        for(int i=0; i<100; i++){
            dataFile << dataTable.countAtIndex(i) << endl;
        }
        dataFile.close();
        return 0;
    }
    // Linear Probing
    else if(collisionMethod == 3){
        cout << "Linear Probing" << endl;
        LPHashTable hashTable(size, choice);
        int i=0;
        int loadFactorSelection = 0;
        int append = 0;
        for(int j=0; j<loadFactorsCount; j++){
            cout.precision(1);
            cout << fixed;
            while(hashTable.getLoadFactor() < loadFactors[loadFactorSelection]){
                hashTable.insertKey(values[i]);
                i++;
            }
            cout << "---" << hashTable.getLoadFactor() << "---" << endl;
            // Insert 100 values
            cout.precision(6);
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
            insertData[append] = insertTime;
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
            lookUpData[append] = lookUpTime;
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
            deleteData[append] = deleteTime;
            cout << "Average time: " << (float)(insertTime + lookUpTime + deleteTime)/3.0 << endl;
            loadFactorSelection++;
            append++;
        }
        displayConfiguration(choice, collisionMethod);
        displayData(insertData, lookUpData, deleteData, 6);
        return 0;
    }
    // Cuckoo Hashing
    else{
        cout << "Cuckoo Hashing" << endl;
        CHHashTable hashTable(size);
        int i=0;
        int loadFactorSelection = 0;
        int append = 0;
        for(int j=0; j<loadFactorsCount; j++){
            cout.precision(1);
            cout << fixed;
            while(hashTable.getLoadFactor() < CHloadFactors[loadFactorSelection]){
                hashTable.insert(values[i]);
                i++;
            }
            cout << "---" << hashTable.getLoadFactor() << "---" << endl;
            // Insert 100 values
            cout.precision(6);
            cout << fixed;
            startTime = clock();
            for(int k=0; k<100; k++){
                hashTable.insert(values[i]);
                i++;
            }
            endTime = clock();
            execTime = (double)(endTime-startTime)/CLOCKS_PER_SEC;
            cout << "execution time for insertion: " << execTime << endl;
            insertTime = execTime;
            insertData[append] = insertTime;
            // Lookup 100 values
            startTime = clock();
            i -= 100;
            for(int k=0; k<100; k++){
                hashTable.searchValue(values[i]);
                i++;
            }
            endTime = clock();
            execTime = (double)(endTime-startTime)/CLOCKS_PER_SEC;
            cout << "execution time for lookup: " << execTime << endl;
            lookUpTime = execTime;
            lookUpData[append] = lookUpTime;
            // Delete 100 values
            startTime = clock();
            i -= 100;
            for(int k=0; k<100; k++){
                hashTable.deleteValue(values[i]);
                i++;
            }
            i -= 100;
            endTime = clock();
            execTime = (double)(endTime-startTime)/CLOCKS_PER_SEC;
            cout << "execution time for deletion: " << execTime << endl;
            deleteTime = execTime;
            deleteData[append] = deleteTime;
            cout << "Average time: " << (float)(insertTime + lookUpTime + deleteTime)/3.0 << endl;
            loadFactorSelection++;
            append ++;
        }
        displayConfiguration(choice, collisionMethod);
        displayData(insertData, lookUpData, deleteData, 6);
        return 0;
    }
}