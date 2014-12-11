
/*
 * Board.cpp
 *
 *  Created on: Dec 7, 2014
 *      Author: David
 */

#include "Board.h"

using namespace std;

Board::Board() {
	//set black pieces
	for (int i = 0; i < 3; i++) {
		for (int j = 0 + (i % 2); j < 8; j+=2) {
			gameBoard[i][j] = Piece(1);
		}
	}

	//set red pieces
	for (int i = 5; i < 8; i++) {
		for (int j = 0 + (i % 2); j < 8; j+=2) {
			gameBoard[i][j] =  Piece(2);
		}
	}

	//set red squares (unusable)
	for (int i = 0; i < 8; i++) {
		for (int j = 1 + (i % 2); j < 8; j+=2) {
			if (j == 2) {
				gameBoard[i][0] =  Piece(0);
			}
			gameBoard[i][j] =  Piece(0);
		}
	}

	//set center black squares (usable)
	for (int i = 3; i < 5; i++) {
		for (int j = 0 + (i % 2); j < 8; j+=2) {
			if (j == 2) {
				gameBoard[i][0] =  Piece(-1);
			}
			gameBoard[i][j] =  Piece(-1);
		}
	}
};


Piece &Board::getPiece(int x, int y) {
	return gameBoard[x][y];
}

void Board::computer(void) {
    Move validMoves[8][8]; //make an array of valid moves, each with a weight.
    for(int i = 8; i > 0; i--) {
        for(int j = 8; j > 0; j--) {
            if (gameBoard[i][j].getColor() == 1) {
                if (!gameBoard[i][j].isKing()) {
                    for(int k = i+2; k > i; k--) {
                        for(int l = j-2; l <= j+2; l++) {
                            if (isValidMove(i,j,k,l,true)) {
                                //cout << toString() << endl;

                                if (k == i+2) { //found a jump
                                    validMoves[k][l].setAll(i,j,k,l,2);
                                } else {
                                    validMoves[k][l].setAll(i,j,k,l,1);
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    int newRow = 0;
    int newColumn = 0;
    int weight = 0;
    for (int m = 0; m < 8; m++) {
        for (int n = 0; n < 8; n++) {
            if (validMoves[m][n].getweight() >= weight) { //find the highest weight and do it
                    newRow = m;
                    newColumn = n;
                    weight = validMoves[m][n].getweight();
            }
        }
    }
    cout << "Computer's Move: ";
    Sleep(3000); //this gives the player a chance to review the move. also simulates computer taking time to calculate.
    if (weight = 0) {
        cout << "No Valid Moves!" << endl;
    } else { //this gobbletygoop is just convoluted because of getters. It's just getting from and to rows and columns.
        cout << convertInt(validMoves[newRow][newColumn].getrowF()+1) << "," << convertInt(validMoves[newRow][newColumn].getcolumnF()+1) << " to " << convertInt(validMoves[newRow][newColumn].getrowT()+1) << "," << convertInt(validMoves[newRow][newColumn].getcolumnT()+1) << endl;
        int c = gameBoard[validMoves[newRow][newColumn].getrowF()][validMoves[newRow][newColumn].getcolumnF()].getColor();
        gameBoard[validMoves[newRow][newColumn].getrowF()][validMoves[newRow][newColumn].getcolumnF()].setColor(-1);
        gameBoard[validMoves[newRow][newColumn].getrowT()][validMoves[newRow][newColumn].getcolumnT()].setColor(c);
    }
    return;
}

string Board::convertInt(int number)
{
   stringstream ss;//create a stringstream
   ss << number;//add number to the stream
   return ss.str();//return a string with the contents of the stream
}

string Board::toString(void) {
	string s;
	s = "    1   2   3   4   5   6   7   8 \n";
	s += "   --------------------------------\n";
	for (int i = 0; i < 8; i++) {
		s+= convertInt((i+1)) + " ";
		for (int j = 0; j < 8; j++) {
			s += "| " + gameBoard[i][j].toString() + " ";
		}
		s += "|\n   --------------------------------\n";
	}

	return s;
}

bool Board::isValidMove(int row1, int column1, int row2, int column2, bool computer) {
	if (gameBoard[row1][column1].getColor() == 1 && !computer) {
		//return false;
	}

	//single space move
	if (gameBoard[row2][column2].isEmpty() && (abs(((row2 - row1) % 2)) == 1 &&
			abs((column2 - column1) % 2) == 1 && abs(row2 - row1) == 1 &&
			abs(column2 - column1) == 1)) {
		return true;
	}

	//jump move
	int c;
	if (gameBoard[row2][column2].isEmpty() &&  (abs(((row2 - row1) % 2)) == 0 && abs((column2 - column1) % 2) == 0
			&& abs(row2 - row1) == 2 && abs(column2 - column1) == 2)) {
		if (gameBoard[row1][column1].isKing()) {
			if (abs(row2 - row1) == 1 && abs(column2 - column1) == 1) {
				return true;
			}
		} else {
			//cout << gameBoard[row1][column1].getColor() << endl;
			int c = 2;
			if (computer) {
			    c = 1;
                    if (((row1 - row2) == 2 || ((row1 - row2) == -2))) {
                        if (column1 < column2) { //moving Left on the board
                            if ((gameBoard[row2 - 1][column2 - 1].getColor() != c) && (gameBoard[row2 - 1][column2 - 1].getColor() != -1)) {
                                gameBoard[row2 -1][column2-1].setColor(-1);
                                return true;
                            }
                        } else {
                            if ((gameBoard[row2 - 1][column2 + 1].getColor() != c) && (gameBoard[row2 - 1][column2 + 1].getColor() != -1)) {
                                gameBoard[row2 - 1][column2 + 1].setColor(-1);
                                return true;
                            }
                        }
                    }
            } else if ((row1 - row2) == 2 || ((row1 - row2) == -2 && gameBoard[row1][column1].getColor() != c)) {
				if (column1 > column2) { //moving left
					if ((gameBoard[row2 + 1][column2 + 1].getColor() != c) && (gameBoard[row2 + 1][column2 + 1].getColor() != -1)) {
						gameBoard[row1 -1][column1 -1].setColor(-1);
						//gameBoard.toString();
						return true;
					}
				} else {
					if ((gameBoard[row2 + 1][column2 - 1].getColor() != c) && (gameBoard[row2 + 1][column2 - 1].getColor() != -1))
						gameBoard[row2 + 1][column2 - 1].setColor(-1);
						return true;
				}
				//gameBoard[row2 + (row2-row1)][column2 + (column2-column1)].setColor(10);
			}
		}
	}

	return false;
}

/* Board::~Board() {
	// TODO Auto-generated destructor stub
} */

