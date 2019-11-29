#include "BSTHashTable.hpp"
#include <iostream>
using namespace std;

BSTHashTable::BSTHashTable(int tableSize, bool hashFunction){
    TABLE_SIZE = tableSize;
    functionOne = hashFunction;
    BSThashTable = new BSTNode* [TABLE_SIZE];
    for(int i=0; i<TABLE_SIZE; i++){
        BSThashTable[i] = nullptr;
    }
}

BSTHashTable::~BSTHashTable(){
    cout << "Deconstructing" << endl;
    delete [] BSThashTable;
    BSThashTable = NULL;
}

/**
 * Create a new BST node helper function
 */
BSTNode* createBSTNode(int key){
    BSTNode* newNode = new BSTNode;
    newNode->key = key;
    newNode->parent = NULL;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

int BSTHashTable::hashFunctionOne(int key){
    return key % TABLE_SIZE;
}

int BSTHashTable::hashFunctionTwo(int key){
    return floor(key/TABLE_SIZE);
}

/**
 * printHashTable recusive helper function
 */
void inOrderTraversal(BSTNode* curr){
    if(curr == NULL){
        return;
    }
    inOrderTraversal(curr->left);
    cout << curr->key << " ";
    inOrderTraversal(curr->right);
}

/**
 * Will print out all the contents of each index with inorder traversal
 */
void BSTHashTable::printHashTable(){
    for(int i=0; i<TABLE_SIZE; i++){
        cout << i << " -> ";
        inOrderTraversal(BSThashTable[i]);
        cout << endl;
    }
}

/**
 * Searches for the given key in the hash table
 * - Returns node if the key is found
 * - Returns null if the key is not found
 */
BSTNode* BSTHashTable::searchTable(int key){
    int index;
    if(functionOne){
        index = hashFunctionOne(key);
    }else{
        index = hashFunctionTwo(key);
    }
    if(BSThashTable[index] != NULL){
        BSTNode* curr = BSThashTable[index];
        while(curr != NULL){
            if(curr->key == key){
                cout << "Found " << curr->key << endl; 
                return curr;
            }else{
                if(key < curr->key){
                    curr = curr->left;
                }else{
                    curr = curr->right;
                }
            }
        }
        cout << "Key doesn't exist" << endl;
    }
    return NULL;
}

/**
 * insertNode recursive helper function
 */
BSTNode* insert(BSTNode* curr, int key){
    if(curr == NULL){
        return createBSTNode(key);
    }
    if(key < curr->key){
        BSTNode* leftChild = insert(curr->left, key);
        curr->left = leftChild;
        leftChild->parent = curr;
    }else if(key > curr->key){
        BSTNode* rightChild = insert(curr->right, key);
        curr->right = rightChild;
        rightChild->parent = curr;
    }
    return curr;
}

/**
 * Handles the operation of adding a new key to the hash table
 * - If the index of the hash table given by the hash function is NULL
 *      directly insert
 * - If the index of the hash table given by the hash function is not NULL
 *      start chaining with a BST
 */
void BSTHashTable::insertNode(int key){
    int index;
    if(functionOne){
        index = hashFunctionOne(key);
    }else{
        index = hashFunctionTwo(key);
    }
    BSTNode* newNode = createBSTNode(key);
    if(BSThashTable[index] == NULL){
        BSThashTable[index] = newNode;
    }
    else{
        BSThashTable[index] = insert(BSThashTable[index], key);
    }
}