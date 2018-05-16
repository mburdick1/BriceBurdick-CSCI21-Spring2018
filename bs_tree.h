/*
 * Name        : Brice Burdick
 * Date Created: May 9th, 2018
 * Description : header file to test Lab #24 Functionality in practice week 11. This is a tree class where a tree is created to be able to complete
 following tasks of inserting nodes, clearing a tree, and printing InOrder.
 */
#ifndef BS_TREE_H
#define BS_TREE_H

#include <string>
using std::string;

class BSTree {
    private:
    int size_;
    string InOrder_;
    BSTNode* m_root;
    bool return_bool_;
    bool Insert_;
    
    public:
    //constructor
    BSTree();
    
    //size being returned
    int size();
    
    //InOrder being returned
    string InOrder();
    
    // Recursion
    string InOrder(BSTNode* node);
    
    //clearing tree
    BSTree* Clear();
    
    // inserting value
    bool Insert(int number);
    bool Insert(int number, BSTNode* node);
    
};

#endif