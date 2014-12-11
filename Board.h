
/*
 * Board.h
 *
 *  Created on: Dec 7, 2014
 *      Author: David
 */

#ifndef BOARD_H_
#define BOARD_H_

#include "Piece.h"
#include "Move.h"
#include <stdio.h>
#include <iostream>
#include <stdlib.h>
#include <cmath>
#include <string>
#include <sstream>
#include <windows.h> //comment this out and line 90 from board.cpp on linux/unix


using namespace std;

class Board {
public:
	Board();
	Piece &getPiece(int x, int y);
	string convertInt(int number);
	string toString();
	bool isValidMove(int row1, int column1, int row2, int column2, bool computer);
	void computer();


	Piece gameBoard[8][8];
};

#endif /* BOARD_H_ */
