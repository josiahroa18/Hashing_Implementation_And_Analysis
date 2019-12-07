#include "BSTHashTable.hpp"
#include <iostream>
using namespace std;

/**
 * Constructor
 */
BSTHashTable::BSTHashTable(int tableSize, bool hashFunction){
    TABLE_SIZE = tableSize;
    functionOne = hashFunction;
    keyCount = 0;
    loadFactor = 0.0;
    BSThashTable = new BSTNode* [TABLE_SIZE];
    for(int i=0; i<TABLE_SIZE; i++){
        BSThashTable[i] = nullptr;
    }
}

/**
 * De-constructor
 */
BSTHashTable::~BSTHashTable(){
    for(int i=0; i<TABLE_SIZE; i++){
        if(BSThashTable[i] != NULL){
            while(BSThashTable[i] != NULL){
                deleteNode(BSThashTable[i]->key);
            }
        }
    }
    delete [] BSThashTable;
    BSThashTable = NULL;
}

/**
 * Create a new BST node helper function
 */
BSTNode* createBSTNode(int key){
    BSTNode* newNode = new BSTNode;
    newNode->key = key;
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
 * Will run the searchTable function, use this function for lookup tests
 * - If the node does not exist, output that the node does not exist
 * - If the node exists, output the found key from the table
 */
void BSTHashTable::printSearch(int key){
    BSTNode* foundNode = searchTable(key);
    if(foundNode == NULL){
        cout << key << " is not in the table" << endl;
    }else{
        cout << "Found " << foundNode->key << endl;
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
                return curr;
            }else{
                if(key < curr->key){
                    curr = curr->left;
                }else{
                    curr = curr->right;
                }
            }
        }
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
    }else if(key > curr->key){
        BSTNode* rightChild = insert(curr->right, key);
        curr->right = rightChild;
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
    keyCount++;
}

/**
 * Finds the min node starting from a specified node in the tree
 */
BSTNode* findMinNode(BSTNode* curr){
    while(curr && curr->left != NULL){
        curr = curr->left;
    }
    return curr;
}

/**
 * Standard BST deletion implementation which handles multiple cases
 *  for node deletion
 */
BSTNode* delNode(BSTNode* curr, int key){
    if(curr->key == key){
        // Case 1: Deleting node with no children
        if(curr->left == NULL && curr->right == NULL){
            delete curr;
            curr = NULL;
            return NULL;
        }
        // Case 2: Deleting node with no right child
        if(curr->right == NULL){
            BSTNode* temp = curr->left;
            delete curr;
            curr = NULL;
            return temp;
        }
        // Case 3: Deleting node with no left child
        if(curr->left == NULL){
            BSTNode* temp = curr->right;
            delete curr;
            curr = NULL;
            return temp;
        }
        // Case 4: Deleting node with two children
        BSTNode* temp = findMinNode(curr->right);
        curr->key = temp->key;
        curr->right = delNode(curr->right, temp->key);
        return curr;
    }
    if(key < curr->key){
        curr->left = delNode(curr->left, key);
    }
    if(key > curr->key){
        curr->right = delNode(curr->right, key);
    }
    return curr;
}

/**
 * Locates the node in the table if it exists
 * If there is no BST chaining at specified index, simpley delete
 * If there is BST chaining at specified index, run delNode helper function
 */
void BSTHashTable::deleteNode(int key){
    int index;
    if(functionOne){
        index = hashFunctionOne(key);
    }else{
        index = hashFunctionTwo(key);
    }
    // Search the Table to confirm the key exists
    BSTNode* foundNode = searchTable(key);
    if(foundNode == NULL){
        cout << key << " does not exist in the table" << endl;
        return;
    }
    // Handle case where the node at the index has no children
    if(BSThashTable[index]->left == NULL && BSThashTable[index]->right == NULL){
        delete BSThashTable[index];
        BSThashTable[index] = NULL;
    }else{
        BSThashTable[index] = delNode(BSThashTable[index], key);
    }
    keyCount--;
}

/**
 * Returns the load factor of the table
 */
float BSTHashTable::getLoadFactor(){
    return (float)keyCount/(float)TABLE_SIZE;
}

/**
 * countAtIndex recursive helper function
 */
int countRecursive(BSTNode* curr){
    int count = 1;
    if(curr->left != NULL){
        count += countRecursive(curr->left);
    }
    if(curr->right != NULL){
        count += countRecursive(curr->right);
    }
    return count;
}

/**
 * Returns the count for how many values are at a specific index
 */
int BSTHashTable::countAtIndex(int i){
    BSTNode* curr = BSThashTable[i];
    int count = 0;
    if(curr != NULL){
        count = countRecursive(curr);
    }
    return count;
}

/**
 * returns the size of the table
 */
int BSTHashTable::getTableSize(){
    return TABLE_SIZE;
}