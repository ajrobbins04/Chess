/*********************************************
 * Header file:
 *    King
 * Author:
 *    Martin Nkala, Amber Robbins
 * Summary:
 *    Represents the King piece on a Chess Game
 **********************************************/

#ifndef king_h
#define king_h

#include <iostream>
#include <vector>
#include "piece.h"
#include "rook.h"

using namespace std;

/******************************************************
 * KING
 * A king piece for Chess
 ******************************************************/
class King : public Piece
{
private:

	bool hasMoved = false;

public:

	King(bool isWhite, Position position);

	void toggleHasMoved() { this->hasMoved = true; }

	void checkCastle(vector<int>* possibleMoves, Board* board);

	void draw(ogstream& gout) override;

	bool getHasMoved() const { return hasMoved; }

	vector<int> getPossibleMoves(Board * board) override;
};



#endif /* king_h */
