/*
 * Name        : Brice Burdick
 * Date Created: May 7th, 2018
 * Description : BST Node class to use for testing lab 23 unit test. This sets up a tree that has contents being pointed to
 branching children and also contents pointing to NULL.
 */
#ifndef BST_NODE_H
#define BST_NODE_H

#include <string>
using std::string;

class BSTNode {
    
    private:
    int contents_;
    BSTNode* left_child_;
    BSTNode* right_child_;
    
    
    public:
    //Constructor
    BSTNode();
        
        
    // setting content function
    void set_contents(int contents);
    
    //Contents being returned
    int contents();
    
    //Returning left child function
    BSTNode* left_child();
    
    //Set left child
    void set_left_child(BSTNode* p_node);
    
    //Returning right child function
    BSTNode* right_child();
    
    //Set right child
    void set_right_child(BSTNode* node);
    
    // Overload Constructor
    BSTNode(int contents);
    
};

#endif