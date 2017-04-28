

#include "TreeDB.h"



TreeNode::TreeNode(){
    entry = NULL;
    left = NULL;
    right = NULL;
    
}

TreeNode::TreeNode(DBentry* newEntry){
    entry = newEntry;
    left = NULL;
    right = NULL;
}

TreeNode::~TreeNode(){
    
}
TreeNode* TreeNode::getLeft(){
    return left;
}

TreeNode* TreeNode::getRight(){
    return right;
}

DBentry* TreeNode::getEntry(){
    return entry;
}

void TreeNode::insertNode(DBentry* newEntry){
    
    if(newEntry->getName() == entry->getName())
        return;
    if(newEntry->getName() < entry->getName()){
        //insert to the left
        if(left == NULL){
            left = new TreeNode(newEntry);
        }
        else
            left->insertNode(newEntry); //recursion
    }
    else {
        //insert to the right
        if(newEntry->getName() > entry->getName()){
            if(right == NULL){
                right = new TreeNode(newEntry);
                
            }
            else{
                right->insertNode(newEntry); //recursion
            }
        }
    }
    return;
    
}

void TreeNode::deleteNode(string name_, TreeNode*& pp){
    //if name is less than pp name
    if(name_ < pp -> entry->getName() && name_ != pp->entry->getName()){
        if(pp->left!= NULL){
            pp->left->deleteNode(name_,pp->left); //recursion
        }
        return;
    }
    //if name is more than pp name
   
    if(name_ > pp->entry->getName() && name_ !=pp->entry->getName()){
        if(pp->right != NULL){
            pp->right->deleteNode(name_,pp->right); //recursion
        }
        return;
    }
        //found the node
    
    //case 1: No child
    if(pp->left == NULL && pp->right == NULL){
      
        delete pp->getEntry();
        pp= NULL;
        delete this;
        
    }
    //case 2: One child
    else if(pp->left == NULL && pp->right != NULL){
        delete pp->getEntry();
        
        pp = pp->right;
        right = NULL;
        
        
        delete this;
    }
    else if(pp->left!= NULL && pp->right == NULL){
       
        delete pp->getEntry();
        pp = pp->left;
        
        left = NULL;
        delete this;
    }
    //case 3: Two children
    
    else{
        TreeNode* max = pp->left->maximum();
        entry->setName(max->entry->getName());
        entry->setActive(max->entry->getActive());
        entry->setIPaddress(max->entry->getIPaddress());
        
        //deletes the max node in the left subtree
        pp->left->deleteNode(max->entry->getName(),pp->left);
        
        
    }
    return;
    
}

TreeNode* TreeNode::maximum(){
    
    //find the maximum node in the left subtree
    
    if(right == NULL){
        return this;
    }
    TreeNode* max = right->maximum();
    return max;
}
void TreeNode::printNodesInOrder(){
    //prints out alphabetically using recursion
    
    if(left != NULL){
        left->printNodesInOrder(); //recursion
         
    }
    cout<<entry->getName()<<" : "<<entry->getIPaddress()<<" : ";
        if(entry->getActive() == true){
            cout<<"active"<<endl;
        }
        else if(entry->getActive() == false){
            cout<<"inactive"<<endl;
        }
    if(right!= NULL){
        right->printNodesInOrder(); //recursion
    }
    return;
    
}


TreeNode* TreeNode::search(string name_){
    
    if(name_== entry->getName()){
        return this;
    }
    if(name_< entry->getName()){
        if(left != NULL){
            TreeNode* temp = left->search(name_); //recursion
            return temp;
        }
        
    }
    else {
        if(right != NULL){
            TreeNode* temp = right->search(name_); //recursion
            return temp;
        }
    }
    return NULL; //no entry of that name exists
}

int TreeNode::countNodes(string name_,TreeNode* pp){
    int count = 1; //counts the root first
    if(pp == NULL){//if there is no root, count will be 0
        return 0;
    }
    if(name_ == pp->entry->getName()){ //if root is name_
        
        return count;
    }
    //traversing through the tree if root is not name_
   
       while(pp != NULL && name_ != pp->entry->getName()){
            if(name_ < pp->entry->getName()){
                count++;
                
                pp = pp->left;
                
            }
            else{
                count++;
                pp = pp->right;
            }
                   
        }
    
    return count;
    
}
int TreeNode::countActive(TreeNode* pp){
        
    if(pp == NULL){
        return 0;
        
    }
    else if(pp->entry->getActive() == true){
        //uses recursion if the entry is active and adds one
        return 1+countActive(pp->left)+countActive(pp->right);
    }
    else{//uses recursion but does not add one
        return countActive(pp->left)+countActive(pp->right);
        
    }
      
}

void TreeNode::updateStatus(string name_,bool status){
    
    TreeNode* temp = search(name_);
    if(temp == NULL){
        return;
    }
    else{
        temp->entry->setActive(status);
        return;
    }
    
}

void TreeNode::deleteAllNodes(TreeNode*& root){
    //finds the nodes without any children
     if(left != NULL){
        left->deleteAllNodes(root);
        
        
    }
    
    if(right!= NULL){
        right->deleteAllNodes(root);
        
        
    }
    
         //deletes the current node, and the DBentry
         delete this->entry;
         delete this;
         
         return;
    
}