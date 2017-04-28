/* 
 * File:   Main.cpp
 * Author: hossa172
 *
 * Created on November 19, 2016, 4:47 PM
 */

#include <cstdlib>
#include "TreeDB.h"
#include <string>
#include<sstream>

using namespace std;

void insert(stringstream& lineStream, string name_, unsigned int IPaddress_, string status_, TreeDB& tree) {

    //Parsing things
    
    lineStream >> name_;
    lineStream >> IPaddress_;
    lineStream >> status_;
    
    
    if (tree.valueExists(name_)) {
        cout << "Error: entry already exists" << endl;
        return;
    }

    if (status_ == "active") {
        tree.insert(name_, IPaddress_, true);


    } else if (status_ == "inactive") {
        tree.insert(name_, IPaddress_, false);

    }
    cout << "Success" << endl;

}

void find(stringstream& lineStream, string name_, TreeDB& tree) {

    lineStream >> name_;

    TreeNode* temp = tree.find(name_);
    if (temp == NULL) {
        cout << "Error: entry does not exist" << endl;
    } else { //prints out the entry
        
        cout << temp->getEntry()->getName() << " : " << 
                temp->getEntry()->getIPaddress() << " : ";
        
        if (temp->getEntry()->getActive() == true) {
            cout << "active" << endl;
        } else if (temp->getEntry()->getActive() == false) {
            cout << "inactive" << endl;
        }
    }

}

void remove(stringstream& lineStream, string name_, TreeDB& tree) {
    lineStream >> name_;
    if (!tree.valueExists(name_)) {
        cout << "Error: entry does not exist" << endl;
        return;
    }
    tree.deleteNodeInTree(name_);
    cout << "Success" << endl;
}

void printall(stringstream& lineStream, TreeDB& tree) {
    tree.printInOrder();
}

void printprobes(stringstream& lineStream, string name_, TreeDB& tree) {
    lineStream >> name_;
    if (!tree.valueExists(name_)) {
        cout << "Error: entry does not exist" << endl;
        return;
    }
    tree.printProbe(name_);
}

void removeall(stringstream& lineStream, TreeDB& tree) {
    tree.deleteAllInTree();
    cout << "Success" << endl;
}

void countactive(stringstream& lineStream, TreeDB& tree) {
    tree.countActiveInTree();
}

void updatestatus(stringstream& lineStream, string name_, string status_,
        TreeDB& tree) {
    lineStream >> name_;
    lineStream >> status_;
    if (!tree.valueExists(name_)) {
        cout << "Error: entry does not exist" << endl;
        return;
    }
    if (status_ == "active") {
        tree.updateStatusInTree(name_, true);
    } else if (status_ == "inactive") {
        tree.updateStatusInTree(name_, false);
    }
    cout << "Success" << endl;
}

/*
 *
 */
int main(int argc, char** argv) {

    TreeDB tree;
    string line;
    string name_;
    unsigned int IPaddress_;
    string status_;




    cout << "> ";

    getline(cin, line); //Get a line from standard input

    while (!cin.eof()) {
        //Put the line in a stringstream for parsing
        //Making a new stringstream for each line so flags
        //etc etc are in a known state

        string command;
        stringstream lineStream(line);


        lineStream >> command;



        if (command == "insert") {

            insert(lineStream, name_, IPaddress_, status_, tree);

        } else if (command == "find") {

            find(lineStream, name_, tree);

        } else if (command == "remove") {

            remove(lineStream, name_, tree);



        } else if (command == "printall") {

            printall(lineStream, tree);

        } else if (command == "printprobes") {

            printprobes(lineStream, name_, tree);

        } else if (command == "removeall") {

            removeall(lineStream, tree);

        } else if (command == "countactive") {

            countactive(lineStream, tree);

        } else if (command == "updatestatus") {

            updatestatus(lineStream, name_, status_, tree);
        }

        else {

            cout << "Error: invalid command" << endl;
        }

        cout << "> ";

        getline(cin, line); //gets the next line and loops it
        // puts that line into lineStream in the loop

    }

    tree.deleteAllInTree();

    return 0;
}

