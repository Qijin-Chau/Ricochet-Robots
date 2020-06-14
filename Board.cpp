/********************************************
* Comp 15 - Fall 2019
* Project 1
* NAME: Qijin Chau
* DATE: 10/23/19
* 
* Board implementation
* Class implementation for the Board class
***********************************************/

#include "Board.h"

#include <iostream>
#include <fstream>

using namespace std; 

static const string vert_wall = "|";
static const string hori_wall = "-";
static const string open_cell = "X";
static const string place_hold = "O";
static const string target = "*";
static const string empty = " ";

// default constructor
Board::Board()
{
	robo.row = 0;
	robo.col = 0;
	robo.rowInBoard = 0;
	robo.colInBoard = 0;
	robo.symbol = "?";
	robo.win = false;
	// Board indices are 1-index so 0 would be invalid.
	// This is just initializing the Robot with values.
}

// Function heightOfBoard
// Parameters: none
// Returns: An integer
// Does: Returns the height of the board
int Board::heightOfBoard()
{
	return board_height;
}

// Function widthOfBoard
// Parameters: none
// Returns: An integer
// Does: Returns the width of the board
int Board::widthOfBoard()
{
	return board_width;
}

// Function startRObot
// Parameters: A string and two integers
// Returns: Nothing
// Does: Sets the data members of the robot
void Board::startRobot(string symbol, int row, int col)
{
	robo.symbol = symbol;
	robo.row = row;
	robo.col = col;
	
	robo.rowInBoard = (row * 2) - 1;
	
	if(col == 1) {
		robo.colInBoard = col;
	} else {
		robo.colInBoard = 1 + ((col-1)*4);
	}

	if (board[robo.rowInBoard][robo.colInBoard] == target)
	{
		robo.win = true;
	}
	
	board[robo.rowInBoard][robo.colInBoard] = robo.symbol;
}

// Function clearRobot
// Parameters: none
// Returns: nothing
// Does: Clears all the data members of the robot by
//       setting all the integers to zero and win to false.
//       The robot is also cleared from the board.
void Board::clearRobot()
{
	robo.row = 0;
	robo.col = 0;
	board[robo.rowInBoard][robo.colInBoard] = open_cell;
	robo.rowInBoard = 0;
	robo.colInBoard = 0;
	robo.win = false;
}

// Function returnToStart
// Parameters: Two integers
// Returns: Nothing
// Does: Returns robot to its starting position
void Board::returnToStart(int row, int col)
{
	if(!robo.win) { 
		board[robo.rowInBoard][robo.colInBoard] = open_cell;
	}
	if(robo.win) {
		board[robo.rowInBoard][robo.colInBoard] = target;
	}
	robo.win = false;
	robo.row = row;
	robo.col = col;
	
	robo.rowInBoard = (row * 2) - 1;
	
	if(col == 1) {
		robo.colInBoard = col;
	} else {
		robo.colInBoard = 1 + ((col-1)*4);
	}

	board[robo.rowInBoard][robo.colInBoard] = robo.symbol;
}

// Function reachedTarget
// Parameters: none
// Returns: A bool
// Does: Returns true if the robot reached the target,
//       false otherwise.
bool Board::reachedTarget()
{
	return robo.win;
}

// Function moveRobotNorth
// Parameters: none
// Returns: nothing
// Does: Moves the robot north until it runs into a wall or the
//       edge of the board. If the robot reaches the target, 
//       the win bool in the robot is changed to true. The robot's
//       position data elements are also updated. 
void Board::moveRobotNorth()
{
	board[robo.rowInBoard][robo.colInBoard] = open_cell;

	int newRow = robo.rowInBoard;
	int closestCell;
	
	while(newRow > 0 && board[newRow][robo.colInBoard] != hori_wall) {
		if (board[newRow][robo.colInBoard] == open_cell ||
			board[newRow][robo.colInBoard] == target) {
			
			closestCell = newRow;
		}
		newRow--;
	}

	if(board[closestCell][robo.colInBoard] == target) {
		robo.win = true;
	}

	board[closestCell][robo.colInBoard] = robo.symbol;
	
	robo.rowInBoard = closestCell;
	robo.row = (closestCell+1)/2;
}

// Function moveRobotSouth
// Parameters: none
// Returns: nothing
// Does: Moves the robot south until it runs into a wall or the
//       edge of the board. If the robot reaches the target, 
//       the win bool in the robot is changed to true. The robot's
//       position data elements are also updated. 
void Board::moveRobotSouth()
{
	board[robo.rowInBoard][robo.colInBoard] = open_cell;

	int newRow = robo.rowInBoard;
	int closestCell;
	
	while(newRow<board_height && board[newRow][robo.colInBoard]!=hori_wall) {
		if (board[newRow][robo.colInBoard] == open_cell ||
			board[newRow][robo.colInBoard] == target) {
			
			closestCell = newRow;
		}
		newRow++;
	}

	if(board[closestCell][robo.colInBoard] == target) {
		robo.win = true;
	}

	board[closestCell][robo.colInBoard] = robo.symbol;
	
	robo.rowInBoard = closestCell;
	robo.row = (closestCell+1)/2;
}

// Function moveRobotEast
// Parameters: none
// Returns: nothing
// Does: Moves the robot east until it runs into a wall or the
//       edge of the board. If the robot reaches the target, 
//       the win bool in the robot is changed to true. The robot's
//       position data elements are also updated. 
void Board::moveRobotEast()
{
	board[robo.rowInBoard][robo.colInBoard] = open_cell;

	int newCol = robo.colInBoard;
	int closestCell;
	
	while(newCol<board_width && board[robo.rowInBoard][newCol]!=vert_wall) {
		if (board[robo.rowInBoard][newCol] == open_cell ||
			board[robo.rowInBoard][newCol] == target) {
			
			closestCell = newCol;
		}
		newCol++;
	}

	if(board[robo.rowInBoard][closestCell] == target) {
		robo.win = true;
	}

	board[robo.rowInBoard][closestCell] = robo.symbol;
	
	robo.colInBoard = closestCell;
	robo.col = ((closestCell-1)/4) + 1;
}

// Function moveRobotWest
// Parameters: none
// Returns: nothing
// Does: Moves the robot west until it runs into a wall or the
//       edge of the board. If the robot reaches the target, 
//       the win bool in the robot is changed to true. The robot's
//       position data elements are also updated. 
void Board::moveRobotWest()
{
	board[robo.rowInBoard][robo.colInBoard] = open_cell;

	int newCol = robo.colInBoard;
	int closestCell;
	
	while(newCol > 0 && board[robo.rowInBoard][newCol] != vert_wall) {
		if (board[robo.rowInBoard][newCol] == open_cell ||
			board[robo.rowInBoard][newCol] == target) {
			closestCell = newCol;
		}
		newCol--;
	}

	if(board[robo.rowInBoard][closestCell] == target) {
		robo.win = true;
	}

	board[robo.rowInBoard][closestCell] = robo.symbol;
	
	robo.colInBoard = closestCell;
	robo.col = ((closestCell-1)/4) + 1;
}

// Function readBoard
// Parameters: An istream input
// Returns: nothing
// Does: Reads in a file and updates the board instance created
//       to match the board input file.
void Board::readBoard(istream &input_source)
{
	string line;
    int boardRow = 1;

	while(not getline(input_source, line).fail()) {	
		int index = 0;
		
		for(size_t i=1; i<line.length()+1; i++) {
			board[boardRow][i] = line[index];
			index++;
		}
		boardRow++;
	}
}

// Function printBoard
// Parameters: none
// Returns: nothing
// Does: Prints out the board to standard cout without the 
//      spaces in the columns. The "O"'s will be represented 
//      as spaces.
void Board::printBoard()
{
	for(int i=1; i<board_height; i++) {
		for(int j=1; j<board_width; j++) {
			if(board[i][j] == place_hold) {
				cout << empty;
			}
			
			if(board[i][j] != place_hold && board[i][j] != empty) {
				cout << board[i][j];
			}
		}
		cout << endl;
	}
}