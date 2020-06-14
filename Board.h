/******************************************
* Comp 15 - Fall 2019
* Project 1
* NAME: Qijin Chau
* DATE: 10/23/19
* 
* Board interface
* Class interface for the Board class 
*****************************************/

#include <string>

using namespace std;

#ifndef _BOARD_H_
#define _BOARD_H_

struct Robot
{
	string symbol;
	int row;
	int col;
	int rowInBoard;
	int colInBoard;
	bool win;
};

class Board
{
	public:
		Board();

		// board functions
		int heightOfBoard();
		int widthOfBoard();
		void readBoard(istream &input_source);
		void printBoard();

		// robot functions
		void startRobot(string symbol, int row, int col);
		void clearRobot();
		void returnToStart(int row, int col);
		bool reachedTarget();
		void moveRobotNorth();
		void moveRobotSouth();
		void moveRobotEast();
		void moveRobotWest();

	private:
		
		static const int board_height = 16;
		static const int board_width = 30;

		Robot robo;
		string board[board_height][board_width];
};

#endif