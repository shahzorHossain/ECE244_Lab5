
#include "TreeDB.h"


TreeDB::TreeDB(){
    root = NULL;
    
}

void TreeDB::insert(string name_,unsigned int IPaddress_,bool status){
    
    DBentry* newEntry = new DBentry(name_,IPaddress_,status);
    
    if(root == NULL){ //adding the root
        
        root = new TreeNode(newEntry);
        
        
    }
    else{//adding other nodes
        root->insertNode(newEntry);
        
    }
    return;
}

void TreeDB::printInOrder(){
    if(root!= NULL){
        root->printNodesInOrder();
    }
}

bool TreeDB::valueExists(string name_){
    if(root ==NULL){ // empty tree
        return false;
    }
    TreeNode* temp = root->search(name_);
    if(temp == NULL){ // node does not exist
        return false;
    }
    if(name_ ==temp->getEntry()->getName()){ //node exists, so checks if same
        return true;
    }
    else
        return false;
}

void TreeDB::deleteNodeInTree(string name_){
    if(root == NULL){
        return;
    }
    
    root->deleteNode(name_,root);
    return;
}

void TreeDB::printProbe(string name_){

    int counter = root->countNodes(name_,root);
    cout<<counter<<endl;
}

void TreeDB::countActiveInTree(){
    int counter = 0;
      
    counter = root->countActive(root);
    
    cout<<counter<<endl;
}

void TreeDB::updateStatusInTree(string name_,bool status){
    if(root == NULL){ //if there is no tree
        return;
    }
    else{
        root->updateStatus(name_,status);
    }
}

TreeNode* TreeDB::find(string name_){
    if(root == NULL){ //if there is no tree
        return NULL;
    }
    return root->search(name_);
}
void TreeDB::deleteAllInTree(){
    if(root == NULL){//if no tree is created
        return;
    }
    //if the root is the only node in tree
    else if(root->getLeft() == NULL && root->getRight() == NULL){
        
        delete root->getEntry();
        delete root;
        root = NULL;
        return;
    }
    //if tree has multiple nodes
    else{
        root->deleteAllNodes(root); //deletes the nodes first, then the root
        
        root = NULL;
        return;
    }
}

TreeDB::~TreeDB(){
    
}