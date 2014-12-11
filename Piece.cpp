/*
 * Piece.cpp
 *
 *  Created on: Dec 7, 2014
 *      Author: David
 */

#include "Piece.h"

using namespace std;

Piece::Piece(int c) {
	king = false;
	setColor(c);
}

Piece::Piece(void) {
	king = false;
	setColor(0);
}

int Piece::getColor(void) {
	return color;
}

bool Piece::isKing(void){
	return king;
}

void Piece::setColor(int c){
	color = c;
}

void Piece::setKing(void){
	king = !king;
}

string Piece::toString(void){
	if (color == 10)
		return "X";
	if (color == 1) {
		if (king)
			return "B";
		return "b";
	} else if (color == 2){
		if (king)
			return "R";
		return "r";
	} else {
		if (color == -1)
			return " ";
		return "-";
	}
}

bool Piece::isEmpty(void) {
	return (color == -1);
}

/* Piece::~Piece() {
	// TODO Auto-generated destructor stub
} */

