/*********************************************
 * Source file:
 *    Bishop
 * Author:
 *    Martin Nkala, Amber Robbins
 * Summary:
 *    Represents the Bishop piece on a Chess Game
 **********************************************/

#include "bishop.h"

/******************************************************
 * BISHOP :: BISHOP
 * Defines Bishop's non-default constructor.
 ******************************************************/
Bishop::Bishop(bool isWhite, Position position) {
	initialize(isWhite, position, "Bishop");
}

/******************************************************
 * BISHOP :: GET POSSIBLE MOVES
 * Get a vector of all the possible moves for this piece.
 ******************************************************/
vector<int> Bishop::getPossibleMoves(Board *board) {

	vector<int> possibleMoves;

	Position moves[4] = {
			Position(-1,  1),
			Position(1,  1),
			Position(-1, -1),
			Position(1, -1)
	};

	int row = position.getRow();
	int col = position.getCol();
	int r;
	int c;

	for (auto & move : moves)
	{
		r = row + move.getRow();
		c = col + move.getCol();
		while (r >= 0 && r < 8 && c >= 0 && c < 8 &&
			   board->getPiece(move.calculateIndex(r, c)) == nullptr)
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
 * BISHOP :: DRAW
 * Calls a method from ogstream to draw this piece
 ******************************************************/
void Bishop::draw(ogstream& gout) {

   gout.drawBishop(position.getIndex(), isWhite);

}


