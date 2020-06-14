/********************************************
* Comp 15 - Fall 2019
* Project 1
* NAME: Qijin Chau
* DATE: 10/23/19
* 
* Tree interface
* Class interface for the Tree class 
*****************************************/

#include <string>
#include "Board.h"

using namespace std;

#ifndef _TREE_H_
#define _TREE_H_

class Tree
{
    public:
        Tree();
        ~Tree();
        bool find(Board &treeBoard, int row, int col); 
    
    private:
    static const int MAX_LENGTH = 7;

    struct Node {
        string path;
        Node *North;
        Node *South;
        Node *East;
        Node *West;
    };
    
    Node *root;
    
    Node *makeTree(int currHeight, string currPath);
    void  destroy(Node *curr);
    bool find(Node *curr, Board &treeBoard, int row, int col);
};

#endif
