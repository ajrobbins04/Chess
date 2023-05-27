/*********************************************
 * Source file:
 *    Knight
 * Author:
 *    Martin Nkala, Amber Robbins
 * Summary:
 *
 **********************************************/

#include "knight.h"

 /******************************************************
  * KNIGHT :: KNIGHT
  * Defines Knight's non-default constructor.
  ******************************************************/
Knight::Knight(bool isWhite, Position position) {
	initialize(isWhite, position, "Knight");
}

/******************************************************
  * KNIGHT :: GET POSSIBLE MOVES
  * Get a vector of all the possible moves for this piece.
  ******************************************************/
vector<int> Knight::getPossibleMoves(Board *board) {
	vector<int> possibleMoves = {};

	Position moves[8] = {
			Position(-1,  2),
			Position(1,  2),
			Position(-2,  1),
			Position(2,  1),
			Position(-2, -1),
			Position(2, -1),
			Position(-1, -2),
			Position(1, -2)
	};

	int row = position.getRow();
	int col = position.getCol();
	int r;
	int c;

	for (auto & move : moves)
	{
		r = row + move.getRow();
		c = col + move.getCol();

		if (position.isValidPosition(r, c) &&
			(board->getPiece(position.calculateIndex(r, c)) == nullptr ||
			 board->getPiece(position.calculateIndex(r, c))->getIsWhite() != getIsWhite()))
			possibleMoves.push_back(r * 8 + c);
	}

	return possibleMoves;
}

/******************************************************
 * KNIGHT :: DRAW
 * Calls a method to draw this piece
 ******************************************************/
void Knight::draw(ogstream& gout) {

   gout.drawKnight(position.getIndex(), isWhite);

}

