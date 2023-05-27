/*********************************************
 * Header file:
 *    Queen
 * Author:
 *    Martin Nkala, Amber Robbins
 * Summary:
 *   Represents the Queen piece on a Chess Game
 **********************************************/

#ifndef queen_h
#define queen_h

#include <iostream>
#include <vector>
#include "piece.h"
#include "uiDraw.h"

 /******************************************************
  * QUEEN
  * A queen piece for Chess
  ******************************************************/
class Queen : public Piece  {

public:

	Queen(bool isWhite, Position position);

	vector<int> getPossibleMoves(Board * board) override;

	void draw(ogstream& gout) override;
};



#endif /* queen_h */
