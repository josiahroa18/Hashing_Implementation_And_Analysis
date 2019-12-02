#include <iostream>
#include "LPHashTable.hpp"
using namespace std;

LPHashTable::LPHashTable(int tableSize, bool hashFunction){
    TABLE_SIZE = tableSize;
    functionOne = hashFunction;
    keyCount = 0;
    loadFactor = 0.0;
    hashTable = new int [TABLE_SIZE];
    for(int i=0; i<TABLE_SIZE; i++){
        hashTable[i] = -1;
    }
}

LPHashTable::~LPHashTable(){
    for(int i=0; i<TABLE_SIZE; i++){
        if(hashTable[i] != -1){
            hashTable[i] = -1;
        }
    }
    delete [] hashTable;
    hashTable = NULL;
}

int LPHashTable::hashFunctionOne(int key){
    return key % TABLE_SIZE;
}

int LPHashTable::hashFunctionTwo(int key){
    return floor(key/TABLE_SIZE);
}

void LPHashTable::printTable(){
    for(int i=0; i<TABLE_SIZE; i++){
        cout << i << " -> ";
        if(hashTable[i] != -1){
            cout << hashTable[i];
        }
        cout << endl;
    }
}

int LPHashTable::searchKey(int key){
    int index;
    int originIndex;
    if(functionOne){
        index = hashFunctionOne(key);
    }else{
        index = hashFunctionTwo(key);
    }
    originIndex = index;
    while(hashTable[index] != key){
        if(index == TABLE_SIZE-1){
            index = 0;
        }else{
            index ++;
        }
        if(index == originIndex){
            cout << "Key value not found" << endl;
            return -1;
        }
    }
    return index;
}

void LPHashTable::insertKey(int key){
    int index;
    int originIndex;
    if(functionOne){
        index = hashFunctionOne(key);
    }else{
        index = hashFunctionTwo(key);
    }
    if(hashTable[index] == -1){
        hashTable[index] = key;
    }else{
        originIndex = index;
        while(hashTable[index] != -1){
            if(index == TABLE_SIZE){
                index = 0;
            }else{
                index ++;
            }
            if(index == originIndex){
                TABLE_SIZE++;
                hashTable[TABLE_SIZE-1] = key;
                return;
            }
        }
        hashTable[index] = key;
    }
    keyCount++;
}

void LPHashTable::deleteKey(int key){
    int index;
    int originIndex;
    if(functionOne){
        index = hashFunctionOne(key);
    }else{
        index = hashFunctionTwo(key);
    }
    if(hashTable[index]== key){
        hashTable[index] = -1;
    }else{
        originIndex = index;
        // Search for the index that the key corresponds to
        index = searchKey(key);
        if(index == -1){
            return;
        }
        hashTable[index] = -1;
    }
    keyCount--;
}

/**
 * Returns the load factor of the table
 */
float LPHashTable::getLoadFactor(){
    return (float)keyCount/(float)TABLE_SIZE;
}