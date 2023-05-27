/***********************************************************************
 * Header File:
 *    Position
 * Author:
 *    Martin Nkala, Amber Robbins
 * Summary:
 *    Keeps track of the position of each piece on the board, which
 *    helps facilitate the movement of pieces.
 ************************************************************************/

#ifndef position_h
#define position_h

#include <iostream>

class TestBoard; // forward declaration

using namespace std;

/******************************************************
 * POSITION
 * Represents a set of coordinates in the space of a 8x8 board
 ******************************************************/
class Position {

private:

	int index;
	int row;
	int col;

	void assertPosition();

public:

	// Default constructor.
	Position() : index(0), row(0), col(0) {}

	// Non-default constructor.
	Position(int i);

	// Non-default constructor.
	Position(int r, int c);

	void setFromIndex(int i);
	int calculateIndex(int r, int c) const;
	
	int getRow()   const { return row;   }
	int getCol()   const { return col;   }
	int getIndex() const { return index; }

	bool isValidColumn(int c) const;
	bool isValidPosition(int row, int col) const;

};


#endif /* position_h */
