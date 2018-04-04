// Name: Brice Burdick
// Date Created: March 27
// Description: This the Node Class to help complete node test.cpp


#ifndef NODE_H
#define NODE_H

#include <string>
using std::string;

class Node {
    public:
    //Constructor
    Node(){
        contents_ = "";
        next_node_ = NULL;
    }
    
    
    // second constructor for overload constructor
    Node(string contents, Node* next){
        contents_ = contents;
        next_node_ = next;
    }
    
    // Constructor that sets contents to NULL
    Node(string contents){
        contents_ = contents;
        next_node_ = NULL;
    }
    
    // contents function returning contents
    string contents(){
        return contents_;
        
    }
    // next node function
    Node* next_node(){
        //string contents_;
        return next_node_;
    }
    
    // setting content function
    void set_contents(string input){
        contents_ = input;
        
    }
    
    // next node function Mutator
    void set_next_node(Node*p_node2){
        next_node_ = p_node2;
    }
    
    
    
    
    
    
    private:
    string contents_;
    Node* next_node_;
};

// Node::Node(string contents){
//     contents_ = contents;
//};

#endif