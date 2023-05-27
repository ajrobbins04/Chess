/*********************************************
 * Header file:
 *    Rook
 * Author:
 *    Martin Nkala, Amber Robbins
 * Summary:
 *    Represents the Rook piece on a Chess Game
 **********************************************/

#ifndef rook_h
#define rook_h

#include <iostream>
#include <vector>
#include "piece.h"
 
 /******************************************************
  * ROOK
  * A rook piece for Chess
  ******************************************************/
class Rook : public Piece {

private:

	bool hasMoved = false;

public:

	Rook(bool isWhite, Position position);

	bool getHasMoved() const { return this->hasMoved; }

	void toggleHasMoved() { this->hasMoved = true; }

	vector<int> getPossibleMoves(Board * board) override;

	void draw(ogstream& gout) override;
};


#endif /* rook_h */
