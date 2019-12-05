#include "CHHashTable.hpp"
#include <iostream>
using namespace std;

/**
 * Constructor
 */
CHHashTable::CHHashTable(int tableSize){
    TABLE_SIZE = tableSize;
    tableOne = new int [TABLE_SIZE];
    tableTwo = new int [TABLE_SIZE];
    keyCount = 0;
    loadFactor = 0.0;
    reHashCount = 0;
    for(int i=0; i<TABLE_SIZE; i++){
        tableOne[i] = -1;
        tableTwo[i] = -1;
    }
}

/**
 * De-constructor
 */
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
    while(true){
        indexOne = hashFunctionOne(newKey);
        indexTwo = hashFunctionTwo(newKey);
        if(tableOne[indexOne] == -1){
            tableOne[indexOne] = newKey;
            keyCount++;
            return;
        }
        tempKey = tableOne[indexOne];
        tableOne[indexOne] = newKey;
        if(tableTwo[indexTwo] == -1){
            tableTwo[indexTwo] = tempKey;
            keyCount++;
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
        return;
    }
    int indexTwo = hashFunctionTwo(key);
    if(tableTwo[indexTwo] == key){
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
        tableOne[indexOne] = -1;
        keyCount--;
        return;
    }
    int indexTwo = hashFunctionTwo(key);
    if(tableTwo[indexTwo] == key){
        tableTwo[indexTwo] = -1;
        keyCount--;
        return;
    }
    cout << key << " not in hash table" << endl;
}

/**
 * Returns the load factor of the table
 */
float CHHashTable::getLoadFactor(){
    return (float)keyCount/(float)TABLE_SIZE;
}

/**
 * Returns the amount of times the table re-hashed
 */
int CHHashTable::getreHashCount(){
    return reHashCount;
}