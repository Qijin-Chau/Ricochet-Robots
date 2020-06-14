/********************************************
* Comp 15 - Fall 2019
* Project 1
* NAME: Qijin Chau
* DATE: 10/23/19
* 
* Tree implementation
* Class implementation for the Tree class
***********************************************/

#include "Tree.h"
#include "Board.h"

#include <stdio.h>
#include <iostream>

using namespace std; 

static const char NORTH = 'w', SOUTH = 's', EAST = 'd', WEST = 'a';

// Default constructor
Tree::Tree() 
{
    root = makeTree(0, "");
}

// Function makeTree
// Parameters: Takes in an integer and a string.
// Returns: Returns the root of the whole tree
// Does: Builds the whole tree with four pointers.
Tree::Node *Tree::makeTree(int currHeight, string currPath)
{
    if (currHeight == MAX_LENGTH+1) {
        return nullptr;
    }

    Node *curr = new Node;

    curr->path = currPath;

    // builds tree
    curr->North = makeTree(currHeight + 1, currPath + NORTH);
    curr->South = makeTree(currHeight + 1, currPath + SOUTH);
    curr->East  = makeTree(currHeight + 1, currPath + EAST);
    curr->West  = makeTree(currHeight + 1, currPath + WEST);

    return curr;
}

// Destructor 
// Destroys the object
Tree::~Tree() {
    destroy(root);
}

// Function destroy
// Parameters: Takes in a pointer to a node
// Returns: nothing
// Does: Destructor helper. Destroys the tree starting
//       from the bottom of the tree or the children/leaves.
void Tree::destroy(Node *curr)
{
    if(curr->North != nullptr) {
        destroy(curr->North);
    }
    if(curr->South != nullptr) {
        destroy(curr->South);
    }
    if(curr->East != nullptr) {
        destroy(curr->East);
    }
    if(curr->West != nullptr) {
        destroy(curr->West);
    }
    
    delete curr;
}

// Function find
// Parameters: Takes an address to a board and two integers.
// Returns: Returns a bool.
// Does: Returns true or false depending on whether the tree 
//       has a solution to the game.
bool Tree::find(Board &treeBoard, int row, int col) 
{
    return find(root, treeBoard, row, col);
}

// Function find
// Parameters: Takes a pointer to a node, an address to a board, 
//             and two integers.
// Returns: Returns a bool
// Does: Returns true or false depending on whether a node
//       in the tree has a solution to the game and prints
//       out the first solution.
bool Tree::find(Node *curr, Board &treeBoard, int row, int col) 
{
    if (curr == nullptr) {
        return false;
    }   
    
    for (unsigned long i = 0; i < curr->path.length(); ++i)
    {
        if(curr->path[i] == NORTH) 
            treeBoard.moveRobotNorth();
        if(curr->path[i] == SOUTH) 
            treeBoard.moveRobotSouth();
        if(curr->path[i] == EAST) 
            treeBoard.moveRobotEast();
        if(curr->path[i] == WEST) 
            treeBoard.moveRobotWest();
    }
    if (treeBoard.reachedTarget() == true) {
        for(unsigned long i=0;i<curr->path.length();++i) {
            if(curr->path[i] == NORTH)
                cout << " N -> ";
            if(curr->path[i] == SOUTH)
                cout << " S -> ";
            if(curr->path[i] == EAST)
                cout << " E -> ";
            if(curr->path[i] == WEST)
                cout << " W -> ";
        }
        cout <<  "Found the target!\n";
        treeBoard.returnToStart(row, col);
        return true;
    }
    treeBoard.returnToStart(row, col);

    bool isNorth = find(curr->North, treeBoard, row, col);
    if(isNorth) 
        return true;
    bool isSouth = find(curr->South, treeBoard, row, col);
    if(isSouth) 
        return true;
    bool isEast = find(curr->East, treeBoard, row, col);
    if(isEast) 
        return true;
    bool isWest = find(curr->West, treeBoard, row, col);
    if(isWest) 
        return true;

    return false;
}


