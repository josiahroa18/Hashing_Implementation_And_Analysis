#include <iostream>
#include "LPHashTable.hpp"
using namespace std;

LPHashTable::LPHashTable(int tableSize, bool hashFunction){
    TABLE_SIZE = tableSize;
    functionOne = hashFunction;
    hashTable = new LPNode* [TABLE_SIZE];
    for(int i=0; i<TABLE_SIZE; i++){
        hashTable[i] = nullptr;
    }
}

LPHashTable::~LPHashTable(){
    for(int i=0; i<TABLE_SIZE; i++){
        if(hashTable[i] != NULL){
            hashTable[i] = NULL;
            delete hashTable[i];
        }
    }
    delete [] hashTable;
    hashTable = NULL;
}

LPNode* LPHashTable::createNode(int key, int index){
    LPNode* newNode = new LPNode;
    newNode->key = key;
    newNode->index = index;
    return newNode;
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
        if(hashTable[i] != NULL){
            cout << hashTable[i]->key;
        }
        cout << endl;
    }
}

LPNode* LPHashTable::searchKey(int key){
    int index;
    int originIndex;
    if(functionOne){
        index = hashFunctionOne(key);
    }else{
        index = hashFunctionTwo(key);
    }
    originIndex = index;
    while(hashTable[index]->key != key){
        if(index == TABLE_SIZE){
            index = 0;
        }else{
            index ++;
        }
        if(index == originIndex){
            cout << "Key value not found" << endl;
            return NULL;
        }
    }
    return hashTable[index];
}

void LPHashTable::insertKey(int key){
    int index;
    LPNode* newNode;
    if(functionOne){
        index = hashFunctionOne(key);
    }else{
        index = hashFunctionTwo(key);
    }
    if(hashTable[index] == NULL){
        newNode = createNode(key, index);
        hashTable[index] = newNode;
    }else{
        while(hashTable[index] != NULL){
            if(index == TABLE_SIZE){
                index = 0;
            }else{
                index ++;
            }
        }
        newNode = createNode(key, index);
        hashTable[index] = newNode;
    }
}

void LPHashTable::deleteKey(int key){
    cout << "Attempting to delete " << key << endl;
    int index;
    if(functionOne){
        index = hashFunctionOne(key);
    }else{
        index = hashFunctionTwo(key);
    }
    if(hashTable[index]->key == key){
        hashTable[index] = NULL;
        delete hashTable[index];
    }else{
        LPNode* foundNode = searchKey(key);
        if(foundNode){
            hashTable[foundNode->index] = NULL;
            delete hashTable[foundNode->index];
        }else{
            cout << "Node not found" << endl;
        }
    }
}