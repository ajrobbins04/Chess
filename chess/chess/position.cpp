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

void Position::assertPosition() {
	assert(index <= 63 && index >= 0);
	assert(row <= 7 && row >= 0);
	assert(col <= 7 && col >= 0);
}

Position::Position(int i) {
	index = i;
	row = i / 8;
	col = i % 8;

	assertPosition();
}

Position::Position(int r, int c) {
	row = r;
	col = c;
	index = calculateIndex(r, c);

	assertPosition();
}

int Position::calculateIndex(int r, int c) {
	return r * 8 + c;
}

bool Position::isValidPosition(int row, int col) {
	return row >= 0 && row < 8 && col >= 0 && col < 8;
}

bool Position::isValidColumn(int c) {
	return c >= 0 && c <= 7;
}

void Position::setFromIndex(int i) {
	index = i;
	row = i / 8;
	col = i % 8;

	assertPosition();
}

