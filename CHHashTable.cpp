#include "CHHashTable.hpp"
#include <iostream>
using namespace std;

CHHashTable::CHHashTable(int tableSize){
    TABLE_SIZE = tableSize;
    tableOne = new int [TABLE_SIZE];
    tableTwo = new int [TABLE_SIZE];
    valuesStored = 0;
    loadFactor = 0;
    for(int i=0; i<TABLE_SIZE; i++){
        tableOne[i] = -1;
        tableTwo[i] = -1;
    }
}

CHHashTable::~CHHashTable(){
    delete [] tableOne;
    tableOne = NULL;
    delete [] tableTwo;
    tableTwo = NULL;
}

int CHHashTable::hashFunctionOne(int key){
    return key % TABLE_SIZE;
}

int CHHashTable::hashFunctionTwo(int key){
    return floor(key/TABLE_SIZE);
}

/**
 * Inserts a new key into the hash table
 * If tableOne[i] is empty, place there. Otherwise place key in tableOne[i]
 * and move old value to tableTwo[i]. If tableTwo[i] is occupied, repeat the
 * process until all values have a unique index
 */
void CHHashTable::insert(int key){
    int indexOne;
    int indexTwo;
    int tempKey;
    int originKey = key;
    int newKey = key;
    cout << "Inserting " << key << endl;
    while(true){
        indexOne = hashFunctionOne(newKey);
        indexTwo = hashFunctionTwo(newKey);
        if(tableOne[indexOne] == -1){
            tableOne[indexOne] = newKey;
            valuesStored++;
            return;
        }
        tempKey = tableOne[indexOne];
        tableOne[indexOne] = newKey;
        if(tableTwo[indexTwo] == -1){
            tableTwo[indexTwo] = tempKey;
            valuesStored++;
            return;
        }else{
            // Take what was in tableTwo and insert into Table One (loop)
            newKey = tableTwo[indexTwo];
            tableTwo[indexTwo] = tempKey;
        }
        if(newKey == originKey){
            cout << "Cycle present. Rehash" << endl;
            reHash();
        }
    }
}

/**
 * To re-hash the table, we must delete all the values in the table and
 * re-insert all the values
 */
void CHHashTable::reHash(){
    reHashCount++;
    // Delete all values and save them in a vector
    for(int i=0; i<TABLE_SIZE; i++){
        if(tableOne[i] != -1){
            deletedValues.push_back(tableOne[i]);
            tableOne[i] = -1;
        }
    }
    for(int i=0; i<TABLE_SIZE; i++){
        if(tableTwo[i] != -1){
            deletedValues.push_back(tableTwo[i]);
            tableTwo[i] = -1;
        }
    }
    // Increase table size for new hash functions
    TABLE_SIZE++;
    // Initializa new index values to empty
    tableOne[TABLE_SIZE-1] = -1;
    tableTwo[TABLE_SIZE-1] = -1;
    // Re-insert previous values
    int lastValue;
    for(unsigned int i=0; i<deletedValues.size(); i++){
        lastValue = deletedValues.at(i);
        insert(lastValue);
    }
}

/**
 * Displays a table for testing
 */
void CHHashTable::printTable(){
    // Table One
    for(int i=0; i<TABLE_SIZE; i++){
        if(tableOne[i] == -1){
            cout << "-";
        }else{
            cout << tableOne[i];
        }
        cout << ",";
    }
    cout << endl;
    // Table Two
    for(int i=0; i<TABLE_SIZE; i++){
        if(tableTwo[i] == -1){
            cout << "-";
        }else{
            cout << tableTwo[i];
        }
        cout << ",";
    }
    cout << endl;
}

/**
 * To look for a value, simply pass the key through the hash functions
 * and check both tables 
 */
void CHHashTable::searchValue(int key){
    int indexOne = hashFunctionOne(key);
    if(tableOne[indexOne] == key){
        cout << "Found " << tableOne[indexOne] << endl;
        return;
    }
    int indexTwo = hashFunctionTwo(key);
    if(tableTwo[indexTwo] == key){
        cout << "Found " << tableTwo[indexTwo] << endl;
        return;
    }
    cout << key << " not in hash table" << endl;
}

/**
 * Locates the value using the hash functions and check both tables
 * - Deletes if it exists
 * - States that it is not in the hash table if it does not exist
 */
void CHHashTable::deleteValue(int key){
    int indexOne = hashFunctionOne(key);
    if(tableOne[indexOne] == key){
        cout << "Deleted " << tableOne[indexOne] << endl;
        tableOne[indexOne] = -1;
        valuesStored--;
        return;
    }
    int indexTwo = hashFunctionTwo(key);
    if(tableTwo[indexTwo] == key){
        cout << "Deleted " << tableTwo[indexTwo] << endl;
        tableTwo[indexTwo] = -1;
        valuesStored--;
        return;
    }
    cout << key << " not in hash table" << endl;
}

void CHHashTable::getLoadFactor(){
    cout << "Load Factor: " << valuesStored/TABLE_SIZE << endl;
}

void CHHashTable::getreHashCount(){
    cout << "Table re-hashed " << reHashCount << " times" << endl;
}