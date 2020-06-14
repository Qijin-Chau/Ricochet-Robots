/********************************************
* Comp 15 - Fall 2019
* Project 1
* NAME: Qijin Chau
* DATE: 10/23/19
* 
* main.cpp
*
* Interactive main for running the Board & Tree
* classes using input files
*********************************************/

#include "Board.h"
#include "Tree.h"

#include <iostream>
#include <fstream>
#include <string>

using namespace std;

string robot_char();
int starting_row();
int starting_col();
string game_mode();
void run_interact_mode(istream &input_source,string symbol,int row, int col);
void interactiveHelper(Board &board, string command);
void run_auto_mode(istream &input_source, string symbol, int row, int col);

static const string NORTH = "w", SOUTH = "s", EAST = "d", 
                                 WEST = "a", QUIT = "q";

int main(int argc, char *argv[])
{
	ifstream infile;
	string robotSymbol, gameMode;
	int startingRow, startingCol;

	if (argc != 2) {
		cout << "Usage: ./gorobots [board input file]\n";
	} else if (argc == 2) {
		string filename = argv[1];
		infile.open(filename);
		if(!infile) {
			cout << "Error: could not open file " << filename << endl;
		} else {
			robotSymbol = robot_char();
			startingRow = starting_row();
			startingCol = starting_col();
			gameMode = game_mode();

			if(gameMode == "INTER") {
				cout << endl;
				run_interact_mode(infile, robotSymbol, 
					              startingRow, startingCol);
				infile.close();
			}

			if(gameMode == "AUTO") {
				run_auto_mode(infile, robotSymbol, startingRow, startingCol);
				infile.close();
			}
		}
	}
	
	return 0;
}

string robot_char()
{
	string robotSymbol;
	
	cout << "Welcome to Ricocheting Robots!\n";
	cout << "Enter Robot symbol (1 Char): ";
	cin  >> robotSymbol; 
	
	return robotSymbol;
}

int starting_row()
{
	int startingRow;
	bool validRow = false;
	
	while(validRow == false) {
		cout << "Enter starting row: ";
		cin  >> startingRow;
		
		if(startingRow < 1 || startingRow > 8) {
			cout << "Invalid row. Row must be in between (1-8)\n";
		} else {
			validRow = true;
		}
	}

	return startingRow;
}

int starting_col()
{
	int startingCol;
	bool validCol = false;
	
	while(validCol == false) {
		cout << "Enter starting col: ";
		cin  >> startingCol;
		
		if(startingCol < 1 || startingCol > 8) {
			cout << "Invalid col. Col must be in between (1-8)\n";
		} else {
			validCol = true;
		}
	}

	return startingCol;
}

string game_mode()
{
	string gameMode;

	cout << "Please enter AUTO for automatic solver and ";
	cout << "INTER for an interactive game mode!\n";
	cin  >> gameMode;

	return gameMode;
}

void run_interact_mode(istream &input_source, string symbol, int row, int col)
{
	bool flag = true;
	string command;

	Board goRobots;
	goRobots.readBoard(input_source);
	goRobots.startRobot(symbol, row, col);
	goRobots.printBoard();
	cout << endl;
	
	while (flag == true) {
		if(goRobots.reachedTarget()) {
			cout << "Congratulations!! You Win!!!!\n";
			return;
		}

		cin >> command;
		
		if (command == QUIT) {
			cout << "move: qQuitting...\n";
			flag = false;
		}
		
		interactiveHelper(goRobots, command);
	}
}

void run_auto_mode(istream &input_source, string symbol, int row, int col)
{
	Board goRobots;
	goRobots.readBoard(input_source);
	goRobots.startRobot(symbol, row, col);
	
	Tree goRobotsTree;
	
	bool solution = goRobotsTree.find(goRobots, row, col);
	if(!solution) {
		cout << "No solution\n";
	}
}

void interactiveHelper(Board &board, string command)
{
	if(command == NORTH) {
		board.moveRobotNorth();
		cout << "move: " << command << " -> moving north\n" << endl;
		board.printBoard();
		cout << endl;
	}
	else if(command == SOUTH) {
		board.moveRobotSouth();
		cout << "move: " << command << " -> moving south\n" << endl;
		board.printBoard();
		cout << endl;
	}
	else if(command == EAST) {
		board.moveRobotEast();
		cout << "move: " << command << " -> moving east\n" << endl;
		board.printBoard();
		cout << endl;
	}
	else if(command == WEST) {
		board.moveRobotWest();
		cout << "move: " << command << " -> moving west\n" << endl;
		board.printBoard();
		cout << endl;
	}
	else if(command != QUIT) {
		cout << "move: " << command << "INVALID MOVE\n";
	}
}