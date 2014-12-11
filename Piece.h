
/*
 * Piece.h
 *
 *  Created on: Dec 7, 2014
 *      Author: David
 */

#ifndef PIECE_H_
#define PIECE_H_

#include <string>

using namespace std;

class Piece {
public:
	Piece();
	Piece(int c);
	int getColor(void);
	bool isKing(void);
	void setColor(int);
	void setKing(void);
	string toString(void);
	bool isEmpty(void);



	int color;
	bool king;
};

#endif /* PIECE_H_ */
