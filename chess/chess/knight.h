/*********************************************
 * Header file:
 *    Knight
 * Author:
 *    Martin Nkala, Amber Robbins
 * Summary:
 *   Represents the Knight piece on a Chess Game
 **********************************************/

#ifndef knight_h
#define knight_h

#include <iostream>
#include <vector>
#include "piece.h"

using namespace std;

/******************************************************
 * KNIGHT
 * A bishop piece for Chess
 ******************************************************/
class Knight : public Piece {

public:

	Knight(bool isWhite, Position position);

	vector<int> getPossibleMoves(Board * board) override;

	void draw(ogstream& gout) override;
};




#endif /* knight_h */
