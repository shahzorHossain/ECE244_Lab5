/* 
 * File:   TreeNode.h
 * Author: hossa172
 *
 * Created on November 19, 2016, 4:44 PM
 */

#ifndef TREENODE_H
#define	TREENODE_H

#include "DBentry.h"


class TreeNode{
private:
    DBentry* entry;
    TreeNode* left;
    TreeNode* right;

public:
    TreeNode();
    TreeNode(DBentry* newEntry);
    void insertNode (DBentry* newEntry);
    void printNodesInOrder();
    TreeNode* maximum();
    void deleteNode(string name_,TreeNode*& pp);
    TreeNode* search(string name_);
    TreeNode* getRight();
    TreeNode* getLeft();
    DBentry* getEntry();
    int countNodes(string name_,TreeNode* pp);
    int countActive(TreeNode* pp);
    void updateStatus(string name_,bool status);
    void deleteAllNodes(TreeNode*& root);
    ~TreeNode();
    
};

#endif	/* TREENODE_H */

