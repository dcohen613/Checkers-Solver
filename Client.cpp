/*
 * Client.cpp
 *
 *  Created on: Dec 7, 2014
 *      Author: David
 */

#include "Client.h"

using namespace std;

int main() {
	Board g1 = Board();
	string input = "";
	do {
		cout << g1.toString() << endl;
		cout << "What's your move? [RED] ex: row,column to row,column" <<endl;
		getline(cin,input,'\n');
		for (int i = 0; i < input.length()-1; i++) {
			if (input[i] == 't' || input[i] == 'o' || input[i] == ' ') {
				input.erase(i,i-1);
				i=0;
			}
		}
		if (input.length() != 6) {
			cout << "Invalid Entry." << endl;

		} else {
			int row1, row2, column1, column2;
			row1 = input.at(0) - '0';
			column1 = input.at(2) - '0';
			row2 = input.at(3) - '0';
			column2 = input.at(5) - '0';
			row1--;column1--;row2--;column2--;

			if (g1.isValidMove(row1, column1, row2, column2, false)) {
				int c = g1.getPiece(row1, column1).getColor();
				g1.getPiece(row1, column1).setColor(-1);
				g1.getPiece(row2, column2).setColor(c);
				cout << g1.toString() << endl;
				g1.computer();

			} else {
				cout << "Invalid Move." << endl;

				//g1.getPiece(row2,column2).setColor(10);
				//System.out.println(g1.getPiece(row2,column2).getColor() + "\n row1: " + row1 + " column1: " + column1 + " row2: " + row2 + " column2: " + column2);
			}
		}
	} while (input.compare("-1") != 0);


	return 0;
}



