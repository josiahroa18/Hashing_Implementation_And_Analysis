#include "LLHashTable.hpp"
#include <iostream>
using namespace std;

// TODO: add a boolean parameter for which hash function to use

LLHashTable::LLHashTable(){
    TABLE_SIZE = 6; //1019
    LLhashTable  = new node* [TABLE_SIZE];
    for(int i=0; i<TABLE_SIZE; i++){
        LLhashTable[i] = nullptr;
    }
}

LLHashTable::~LLHashTable(){
    cout << "Deconstructing" << endl;
}

node* LLHashTable::createLLNode(int key){
    node* newNode = new node;
    newNode->key = key;
    newNode->next = NULL;
    return newNode;
}

int LLHashTable::hashFunction(int key){
    return key % TABLE_SIZE;
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
    int index = hashFunction(key);
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
        int index = hashFunction(key);
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
    }else{
        cout << key << " is a duplicate entry" << endl;
    }
}

/**
 * Deletes a node from the hash table
 * - handles head LL node deletion
 * - handles middle LL node deletion
 * - handles end LL node deletion
 */
void LLHashTable::deleteNode(int key){
    cout << "Attempting to delete " << key << endl;
    if(searchTable(key)){
        int index = hashFunction(key);
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
        cout << "Deleted " << key << " from the table" << endl;
    }else{
        cout << key << " is not in the table" << endl;
    }
}

