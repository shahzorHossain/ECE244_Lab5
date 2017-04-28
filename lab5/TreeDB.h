/* 
 * File:   TreeDB.h
 * Author: hossa172
 *
 * Created on November 19, 2016, 4:45 PM
 */

#ifndef TREEDB_H
#define	TREEDB_H


#include "TreeNode.h"
#include "DBentry.h"
#include <iostream>

using namespace std;

class TreeDB {
private:
    TreeNode* root;
    int probesCount;
public:
    TreeDB();
    ~TreeDB();
    void insert(string name_,unsigned int IPaddress_,bool status);
    void printInOrder();
    bool valueExists(string name_);
    void deleteNodeInTree(string name_);
    void printProbe(string name_);
    void countActiveInTree();
    void updateStatusInTree(string name_, bool status);
    TreeNode* find(string name_);
    void deleteAllInTree();
   
    
};


#endif	/* TREEDB_H */

