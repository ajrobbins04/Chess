/*********************************************
 * Source file:
 *     Queen
 * Author:
 *    Martin Nkala, Amber Robbins
 * Summary:
 *
 **********************************************/

#include "queen.h"

 /******************************************************
  * QUEEN :: QUEEN
  * Defines Queens's non-default constructor.
  ******************************************************/
Queen::Queen(bool isWhite, Position position) {
	initialize(isWhite, position, "Queen");
}

/******************************************************
  * QUEEN :: GET POSSIBLE MOVES
  * Get a vector of all the possible moves for this piece.
  ******************************************************/
vector<int> Queen::getPossibleMoves(Board *board) {
	vector<int> possibleMoves;

	Position moves[8] = {
			Position(-1, 1),
			Position( 0, 1),
			Position( 1, 1),
			Position(-1, 0),
			Position( 1, 0),
			Position(-1,-1),
			Position( 0,-1),
			Position( 1,-1)
	};

	int row = position.getRow();
	int col = position.getCol();
	int r;
	int c;

	for (auto & move : moves) {
		r = row + move.getRow();
		c = col + move.getCol();
		while (r >= 0 && r < 8 && c >= 0 && c < 8 &&
			   board->getPiece(position.calculateIndex(r, c)) == nullptr)
		{
			possibleMoves.push_back(r * 8 + c);
			r += move.getRow();
			c += move.getCol();
		}

		if (position.isValidPosition(r, c) &&
			(board->getPiece(position.calculateIndex(r, c))->getIsWhite() != getIsWhite() ||
			 board->getPiece(position.calculateIndex(r, c)) == nullptr))
			possibleMoves.push_back(r * 8 + c);
	}

	return possibleMoves;
}

/******************************************************
 * QUEEN :: DRAW
 * Calls a method to draw this piece
 ******************************************************/
void Queen::draw(ogstream& gout) {

   gout.drawQueen(position.getIndex(), isWhite);

}

