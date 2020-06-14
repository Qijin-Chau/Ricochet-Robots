/********************************************
* Comp 15 - Fall 2019
* Unit Tests for Project 1 Part 2
* Purpose:  Running and testing the Board class
* Name: Qijin Chau
* Assignment: Project 1
* Date: 10/23/19
*********************************************/

#include "Board.h"

#include <iostream>
#include <fstream>

using namespace std;


void heightOfBoard()
{
	cout << "*** heightOfBoard ***\n";

	Board myBoard;
	cout << "Height of board should be: 16\n"; 
	cout << "Height of board: " << myBoard.heightOfBoard() << endl;
	cout << endl;
}

void widthOfBoard()
{
	cout << "*** widthOfBoard ***\n";

	Board myBoard;
	cout << "Width of board should be: 30\n"; 
	cout << "Width of board: " << myBoard.widthOfBoard() << endl;
	cout << endl;
}

void readingInBoard(string filename)
{
	cout << "*** readingInBoard ***\n";
	cout << "Board file: " << filename << "\n\n";

	ifstream infile;
	infile.open(filename);

	Board myBoard;
	myBoard.readBoard(infile);
	myBoard.printBoard();
	cout << endl;
}

void placingRobot(string filename)
{
	cout << "*** placingRobot ***\n";

	ifstream infile;
	infile.open(filename);

	Board myBoard;
	myBoard.readBoard(infile);
	cout << "*** Before ***\n";
	myBoard.printBoard();
	cout << endl;
	myBoard.startRobot("&", 6, 3);
	cout << "*** After ***\n";
	myBoard.printBoard();
	cout << endl;
}

void movingRobotNorth(string filename)
{
	cout << "*** movingRobotNorth ***\n";

	ifstream infile;
	infile.open(filename);

	Board myBoard;
	myBoard.readBoard(infile);
	myBoard.startRobot("&", 8, 5);
	cout << "*** 1st Position ***\n";
	myBoard.printBoard();
	cout << endl;
	myBoard.moveRobotNorth();
	cout << "*** Move North ***\n";
	myBoard.printBoard();
	cout << endl;
	myBoard.clearRobot();
	myBoard.startRobot("&", 8, 1);
	cout << "*** 2nd Position ***\n";
	myBoard.printBoard();
	cout << endl;
	myBoard.moveRobotNorth();
	cout << "*** Move North ***\n";
	myBoard.printBoard();
	cout << endl;
}

void movingRobotSouth(string filename)
{
	cout << "*** movingRobotSouth ***\n";

	ifstream infile;
	infile.open(filename);

	Board myBoard;
	myBoard.readBoard(infile);
	myBoard.startRobot("&", 1, 4);
	cout << "*** 1st Position ***\n";
	myBoard.printBoard();
	cout << endl;
	myBoard.moveRobotSouth();
	cout << "*** Move South ***\n";
	myBoard.printBoard();
	cout << endl;
	myBoard.clearRobot();
	myBoard.startRobot("&", 1, 1);
	cout << "*** 2nd Position ***\n";
	myBoard.printBoard();
	cout << endl;
	myBoard.moveRobotSouth();
	cout << "*** Move South ***\n";
	myBoard.printBoard();
	cout << endl;
}

void movingRobotEast(string filename)
{
	cout << "*** movingRobotEast ***\n";

	ifstream infile;
	infile.open(filename);

	Board myBoard;
	myBoard.readBoard(infile);
	myBoard.startRobot("&", 4, 1);
	cout << "*** 1st Position ***\n";
	myBoard.printBoard();
	cout << endl;
	myBoard.moveRobotEast();
	cout << "*** Move East ***\n";
	myBoard.printBoard();
	cout << endl;
	myBoard.clearRobot();
	myBoard.startRobot("&", 3, 1);
	cout << "*** 2nd Position ***\n";
	myBoard.printBoard();
	cout << endl;
	myBoard.moveRobotEast();
	cout << "*** Move East ***\n";
	myBoard.printBoard();
	cout << endl;
}

void movingRobotWest(string filename)
{
	cout << "*** movingRobotWest ***\n";

	ifstream infile;
	infile.open(filename);

	Board myBoard;
	myBoard.readBoard(infile);
	myBoard.startRobot("&", 4, 8);
	cout << "*** 1st Position ***\n";
	myBoard.printBoard();
	cout << endl;
	myBoard.moveRobotWest();
	cout << "*** Move West ***\n";
	myBoard.printBoard();
	cout << endl;
	myBoard.clearRobot();
	myBoard.startRobot("&", 6, 8);
	cout << "*** 2nd Position ***\n";
	myBoard.printBoard();
	cout << endl;
	myBoard.moveRobotWest();
	cout << "*** Move West ***\n";
	myBoard.printBoard();
	cout << endl;
}

int main() 
{
	heightOfBoard();
	widthOfBoard();
	readingInBoard("TrappedBoard.txt");
	readingInBoard("nowalls.txt");
	readingInBoard("fourStepSol.txt");
	readingInBoard("line_of_horizontal_pieces.txt");
	readingInBoard("Line_of_vertical_pieces.txt");
	placingRobot("TrappedBoard.txt");
	movingRobotNorth("TrappedBoard.txt");
	movingRobotSouth("TrappedBoard.txt");
	movingRobotEast("TrappedBoard.txt");
	movingRobotWest("TrappedBoard.txt");

	return 0;
}
