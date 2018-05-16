/*
 * Name        : Brice Burdick
 * Date Created: May 7th, 2018
 * Description : Function Definitions for bst_node.h
 */
#ifndef bst
#define bst

#include <string>
using std::string;

// Constructor
BSTNode::BSTNode(){
    contents_ = 0;
    left_child_ = NULL;
    right_child_ = NULL;
}

// setting content function
void BSTNode::set_contents(int contents){
    contents_ = contents;
    }
    
//Contents being returned
int BSTNode::contents(){
    return contents_;
    }
    
//Returning left child
BSTNode* BSTNode::left_child(){
    return left_child_;
}


//Returning right child
BSTNode* BSTNode::right_child(){
    return right_child_;
}
    
// Overload Constructor
BSTNode::BSTNode(int contents){
    contents_ = contents;
    left_child_ = NULL;
    right_child_ = NULL;
    
}

//set left child
void BSTNode::set_left_child(BSTNode* p_node){
    left_child_ = p_node;
}

//set right child
void BSTNode::set_right_child(BSTNode* node){
    right_child_ = node;
}



#endif