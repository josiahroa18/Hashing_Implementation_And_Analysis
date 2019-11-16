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
 * Rotates the tree to the left
 */
void RBT::rotateLeft(RBTnode* &root, RBTnode* &newNode){
    RBTnode* tempRight = newNode->right;
    newNode->right = tempRight->left;
    if(newNode->right != NULL){
        newNode->right->parent = newNode;
    }
    tempRight->parent = newNode->parent;
    if(newNode->parent == NULL){
        root = tempRight;
    }else if(newNode == newNode->parent->left){
        newNode->parent->left = tempRight;
    }else{
        newNode->parent->right = tempRight;
    }
    tempRight->left = newNode;
    newNode->parent = tempRight;
}

/**
 * Rotates the tree to the right
 */
void RBT::rotateRight(RBTnode* &root, RBTnode* &newNode){
    RBTnode* tempLeft = newNode->left;
    newNode->left = tempLeft->right;
    if(newNode->left != NULL){
        newNode->left->parent = newNode;
    }
    tempLeft->parent = newNode->parent;
    if(newNode->parent == NULL){
        root = tempLeft;
    }else if(newNode == newNode->parent->left){
        newNode->parent->left = tempLeft;
    }else{
        newNode->parent->right = tempLeft;
    }
    tempLeft->right = newNode;
    newNode->parent = tempLeft;
}

/**
 * Re-balances the tree after insertion
 * - Passing in the newNode by reference
 */
void RBT::reBalance(RBTnode* &root, RBTnode* &newNode){
    RBTnode* parentPtr = NULL;
    RBTnode* grandParentPtr = NULL;
    RBTnode* unclePtr = NULL;
    string tempColor = "";
    while((newNode != root) && (newNode->color != "Black") && (newNode->parent->color == "Red")){
        parentPtr = newNode->parent;
        grandParentPtr = newNode->parent->parent;
        // Case A: Parent of newNode is the left child of Grandparent of newNode
        if(parentPtr == grandParentPtr->left){
            unclePtr = grandParentPtr->right;
            // Case 1: Uncle of newNode is red => re-color tree
            if(unclePtr != NULL && unclePtr->color == "Red"){
                grandParentPtr->color = "Red";
                parentPtr->color = "Black";
                unclePtr->color = "Black";
                newNode = grandParentPtr;
            }else{
                // Case 2: uncle of newNode is black and newNode is right child of its parent (rotateLeft)
                if(newNode == parentPtr->right){
                    rotateLeft(root, parentPtr);
                    newNode = parentPtr;
                    parentPtr = newNode->parent;
                }
                // Case 3: uncle of newNode is black and newNode is left child of its parent (rotateRight)
                rotateRight(root, grandParentPtr);
                tempColor = parentPtr->color;
                parentPtr->color = grandParentPtr->color;
                grandParentPtr->color = tempColor;
                newNode = parentPtr;
            }
        }
        // Case B: Parent of newNode is the right child of the Grandparent of newNode
        else{
            unclePtr = grandParentPtr->left;
            // Case 1: Uncle of newNode is red => re-color tree
            if(unclePtr != NULL && unclePtr->color == "Red"){
                grandParentPtr->color = "Red";
                parentPtr->color = "Black";
                unclePtr->color = "Black";
                newNode = grandParentPtr;
            }else{
                // Case 2: uncle of newNode is black and newNode is left child of its parent (rotateRight)
                if(newNode == parentPtr->left){
                    rotateRight(root, parentPtr);
                    newNode = parentPtr;
                    parentPtr = newNode->parent;
                }
                // Case 3: uncle of newNode is black and newNode is right child of its parent (rotateLeft)
                rotateLeft(root, grandParentPtr);
                tempColor = parentPtr->color;
                parentPtr->color = grandParentPtr->color;
                grandParentPtr->color = tempColor;
                newNode = parentPtr;
            }
        }
    }
    root->color = "Black";
}

/**
 * Inserts a new node into the tree with basic BST insertion
 * - If root is null, newNode becomes root
 * - Otherwise, traverse down tree and update parent and children nodes
 */
RBTnode* insertHelper(RBTnode* curr, RBTnode* newNode){
    if(curr == NULL){
        newNode->color = "Black";
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
void RBT::insert(const int &key){
    RBTnode* newNode = createRBTnode(key);
    root = insertHelper(root, newNode);
    reBalance(root, newNode);
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
 * Prints the tree out using inOrderTraversal and levelOrderTraversal
 */
void RBT::printRBT(){
    cout << "Inorder traversal: ";
    inOrderTraversal(root);
    cout << endl;
    cout << "Postorder traversal: ";
    levelOrderTraversal(root);
    cout << endl;
}
