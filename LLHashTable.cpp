#include "LLHashTable.hpp"
#include <iostream>
using namespace std;

/**
 * Constructs the table with table
 * - given tableSize
 * - given which hashFunction to use
 *      true - function one
 *      false - function two
 */
LLHashTable::LLHashTable(int tableSize, bool hashFunction){
    TABLE_SIZE = tableSize;
    functionOne = hashFunction;
    keyCount = 0;
    loadFactor = 0.0;
    LLhashTable = new node* [TABLE_SIZE];
    for(int i=0; i<TABLE_SIZE; i++){
        LLhashTable[i] = nullptr;
    }
}

/**
 * De-allocate all the memory used by the hashtable
 */
LLHashTable::~LLHashTable(){
    for(int i=0; i<TABLE_SIZE; i++){
        while (LLhashTable[i] != NULL){
            deleteNode(LLhashTable[i]->key);
        }
    }
    delete [] LLhashTable;
    LLhashTable = NULL;
}

/**
 * Creates a LL node with given key and returns it
 */
node* LLHashTable::createLLNode(int key){
    node* newNode = new node;
    newNode->key = key;
    newNode->next = NULL;
    return newNode;
}

int LLHashTable::hashFunctionOne(int key){
    return key % TABLE_SIZE;
}

int LLHashTable::hashFunctionTwo(int key){
    return floor(key/TABLE_SIZE);
}

// Used for testing to view the table
void LLHashTable::printHashTable(){
    for(int i=0; i<TABLE_SIZE; i++){
        node* curr = LLhashTable[i];
        cout << i << " -> ";
        while(curr){
            cout << curr->key << " ";
            curr = curr->next;
        }
        cout << endl;
    }
}

/**
 * Searches the hash table to see if this key already exists
 * - returns the node if it exists
 * - return NULL if it does not exist
 */
node* LLHashTable::searchTable(int key){
    int index;
    if(functionOne){
        index = hashFunctionOne(key);
    }else{
        index = hashFunctionTwo(key);
    }
    node* curr = LLhashTable[index];
    while(curr){
        if(curr->key == key){
            return curr;
        }else{
            curr = curr->next;
        }
    }
    return NULL;
}

/**
 * Handles the operation of adding a new key to the hash table
 * - If the index of the hash table given by the hash function is NULL
 *      directly insert
 * - If the index of the hash table given by the hash function is not NULL
 *      start chaining with LL
 */
void LLHashTable::insertNode(int key){
    if(!searchTable(key)){
        int index;
        if(functionOne){
            index = hashFunctionOne(key);
        }else{
            index = hashFunctionTwo(key);
        }
        node* newNode = createLLNode(key);
        if(LLhashTable[index] == NULL){
            LLhashTable[index] = newNode;
        }else{
            node* curr = LLhashTable[index];
            while(curr->next){
                curr = curr->next;
            }
            curr->next = newNode;
        }
    }
    keyCount++;
}

/**
 * Deletes a node from the hash table
 * - handles head LL node deletion
 * - handles middle LL node deletion
 * - handles end LL node deletion
 */
void LLHashTable::deleteNode(int key){
    if(searchTable(key)){
        int index;
        if(functionOne){
            index = hashFunctionOne(key);
        }else{
            index = hashFunctionTwo(key);
        }
        node* curr = LLhashTable[index];
        node* prev = NULL;
        if(curr->key == key){
            if(curr->next){
                LLhashTable[index] = curr->next;
                curr = nullptr;
                delete curr;
            }else{
                LLhashTable[index] = nullptr;
                delete LLhashTable[index];
            }
        }else{
            while(curr->key != key){
                prev = curr;
                curr = curr->next;
            }
            if(curr->next){
                node* temp = curr;
                prev->next = curr->next;
                temp = NULL;
                delete temp;
            }else{
                curr = NULL;
                delete curr;
                prev->next = NULL;
            }
        }
    }
    keyCount--;
}

/**
 * Returns the load factor of the table
 */
float LLHashTable::getLoadFactor(){
    return (float)keyCount/(float)TABLE_SIZE;
}

/**
 * Counts how many values are at a specific index
 */
int LLHashTable::countAtIndex(int i){
    int count = 0;
    node* curr = LLhashTable[i];
    while(curr != NULL){
        count ++;
        curr = curr->next;
    }
    return count;
}

/**
 * Returns the size of the table
 */
int LLHashTable::getTableSize(){
    return TABLE_SIZE;
}
