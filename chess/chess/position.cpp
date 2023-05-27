/***********************************************************************
 * Source File:
 *    Position
 * Author:
 *    Martin Nkala, Amber Robbins
 * Summary:
 *    Keeps track of the position of each piece on the board, which
 *    helps facilitate the movement of pieces.
 ************************************************************************/

#include "position.h"

/******************************************************
 * ASSERT POSITION
 *
 ******************************************************/
void Position::assertPosition() {
	//assert(index <= 63 && index >= 0);
	//assert(row <= 7 && row >= 0);
	//assert(col <= 7 && col >= 0);
}

/******************************************************
 * SET FROM INDEX
 * Uses a given index value to set a Position
 * object's index, row, and col attributes.
 ******************************************************/
void Position::setFromIndex(int i) {
	index = i;
	row = i / 8;
	col = i % 8;

	assertPosition();
}

/******************************************************
 * CALCULATE INDEX
 * Calculates the index value that corresponds to
 * a given row-column pair.
 ******************************************************/
int Position::calculateIndex(int r, int c) const {
	return r * 8 + c;
}

/******************************************************
 * IS VALID COLUMN
 * One column has 8 squares. 
 ******************************************************/
bool Position::isValidColumn(int c) const {
	return c >= 0 && c <= 7;
}

/******************************************************
 * IS VALID POSITION
 * Checks that the given row-column pair falls
 * within the chess board's boundaries.
 ******************************************************/
bool Position::isValidPosition(int row, int col) const {
	return row >= 0 && row < 8 && col >= 0 && col < 8;
}
