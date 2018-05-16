/*
 * Name        : Brice Burdick
 * Date Created: May 9th 2018
 * Description : function defintions for bs_tree.h
 */
 
 #ifndef bs
 #define bs
 
 #include <string>
using std::string;

//Constructor
BSTree::BSTree(){
    size_ = 0;
    m_root = NULL;
    
}

//Returning size
int BSTree::size(){
    return size_;
}

//Returning InOrder()
string BSTree::InOrder(){
    if (m_root){
        return BSTree::InOrder(m_root);
    }
    return "";
}

// build_string is string that is built upon itself
string BSTree::InOrder(BSTNode* curr_node){
    string build_string = "";
    
    if(curr_node->left_child()){
        build_string += InOrder(curr_node->left_child());
    }
    
    build_string += std::to_string(curr_node->contents()) + " ";
    
    if(curr_node->right_child()){
        build_string += BSTree::InOrder(curr_node->right_child());
    }
    
    return build_string;
}

//Clearing tree
BSTree* BSTree::Clear(){
    size_ = 0;
    m_root = NULL;
    
    
    return 0;
}

//inserting value
bool BSTree::Insert(int number){
    
    if(!m_root){
        m_root = new BSTNode();
        m_root->set_contents(number);
        size_ += 1;
        return true;
    }
    return BSTree::Insert(number, m_root);
}

bool BSTree::Insert(int number, BSTNode* node){
        BSTNode* nav = node; //nav represents navigation
        
        if(nav->contents() < number){
            if(nav->right_child()){
                //nav = nav->right_child();
                return BSTree::Insert(number, nav->right_child());
            }
            else{
                nav->set_right_child(new BSTNode());
                nav->right_child()->set_contents(number);
                size_ += 1;
                return true;
            }
        }
        else if(nav->contents() > number){
            if(nav->left_child()){
                //nav = nav->left_child();
                return BSTree::Insert(number, nav->left_child());
            }
            else{
                nav->set_left_child(new BSTNode());
                nav->left_child()->set_contents(number);
                size_ += 1;
                return true;
            }
        } 
        else if(nav->contents() == number){
            return false;
        }
}






#endif