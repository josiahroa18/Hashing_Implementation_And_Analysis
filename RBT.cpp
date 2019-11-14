#include <iostream>
#include <queue>
#include "RBT.hpp"
using namespace std;

RBT::RBT(){
    root = NULL;
}

/**
 * A helper function that creates a new node
 * - Since this is a Red Black Tree, we initialize the new node
 *      with color red
 */
RBTnode* RBT::createRBTnode(int key){
    RBTnode* newNode = new RBTnode;
    newNode->key = key;
    newNode->left = NULL;
    newNode->right = NULL;
    newNode->parent = NULL;
    newNode->color = "Red";
    return newNode;
}

/**
 * Inserts a new node into the tree with basic BST insertion
 * - If root is null, newNode becomes root
 * - Otherwise, traverse down tree and update parent and children nodes
 */
RBTnode* insertHelper(RBTnode* curr, RBTnode* newNode){
    if(curr == NULL){
        return newNode;
    }
    if(newNode->key < curr->key){
        curr->left = insertHelper(curr->left, newNode);
        curr->left->parent = curr;
    }else if(newNode->key > curr->key){
        curr->right = insertHelper(curr->right, newNode);
        curr->right->parent = curr;
    }
    // Curr has not been updated and is therefore still the root node
    return curr;
}

/**
 * Inserts a new node into the tree
 * - Create a new node
 * - Insert by basic BST insertion method
 * - If newNode is root, change color to black
 */
void RBT::insert(int key){
    RBTnode* newNode = createRBTnode(key);
    root = insertHelper(root, newNode);
    // Fix any balancing issues
}

/**
 * Prints the keys of the tree with in-order traversal
 * - Used for testing BST insertion in tree
 */
void inOrderTraversal(RBTnode* curr){
    if(curr == NULL){
        return;
    }
    inOrderTraversal(curr->left);
    cout << curr->key << " ";
    inOrderTraversal(curr->right);
}

/**
 * Prints the keys of the tree with level-order traversal
 * - Used for testing balancing of RBT
 */
void levelOrderTraversal(RBTnode* curr){
    if(curr == NULL){
        return;
    }
    queue<RBTnode*> q;
    q.push(curr);
    while(!q.empty()){
        RBTnode* temp = q.front();
        cout << temp->key << " ";
        q.pop();
        if(temp->left != NULL){
            q.push(temp->left);
        }
        if(temp->right != NULL){
            q.push(temp->right);
        }
    }

}

/**
 * Prints the tree out using 
 */
void RBT::printRBT(){
    cout << "Inorder traversal: ";
    inOrderTraversal(root);
    cout << endl;
    cout << "Postorder traversal: ";
    levelOrderTraversal(root);
    cout << endl;
}
