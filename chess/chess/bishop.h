/*********************************************
 * Header file:
 *    Bishop
 * Author:
 *    Martin Nkala, Amber Robbins
 * Summary:
 *    Represents the Bishop piece on a Chess Game
 **********************************************/

#ifndef bishop_h
#define bishop_h

#include <iostream>
#include <vector>
#include "piece.h"

 /******************************************************
  * BISHOP
  * A bishop piece for Chess
  ******************************************************/
class Bishop : public Piece {

public:

	Bishop(bool isWhite, Position position);

	vector<int> getPossibleMoves(Board * board) override;

	void draw(ogstream& gout) override;
};


#endif /* bishop_h */
