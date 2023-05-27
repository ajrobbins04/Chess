/***********************************************************************
 * Header File:
 *    Piece
 * Author:
 *    Martin Nkala, Amber Robbins
 * Summary:
 *    Defines the structure of a Chess Piece, which is an
 *    abstract base class.
 ************************************************************************/

#ifndef piece_h
#define piece_h

#include <iostream>
#include <vector>
#include "board.h"
#include "position.h"
#include "uiDraw.h"

using namespace std;

/******************************************************
 * PIECE
 * Base class for a set of Chess Pieces
 ******************************************************/
class Piece {

protected:

	Position position;
	bool isWhite;
	string type;

public:

	virtual ~Piece() = default;

	void initialize(bool isWhite, Position position, string type);

	virtual vector<int> getPossibleMoves(Board * board) = 0;

	virtual void draw(ogstream& gout) = 0;

	Position * getPosition() { return &position; }

	bool getIsWhite() const  { return isWhite; }

	string getType() { return type; }
};



#endif /* piece_h */
