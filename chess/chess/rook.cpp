/*********************************************
 * Source file:
 *    Rook
 * Author:
 *    Martin Nkala, Amber Robbins
 * Summary:
 *
 **********************************************/

#include "rook.h"

 /******************************************************
  * ROOK :: ROOK
  * Defines Rook's non-default constructor.
  ******************************************************/
Rook::Rook(bool isWhite, Position position) {
	this->initialize(isWhite, position, "Rook");
}

/******************************************************
  * ROOK :: GET POSSIBLE MOVES
  * Get a vector of all the possible moves for this piece.
  ******************************************************/
vector<int> Rook::getPossibleMoves(Board *board) {
	vector <int> possibleMoves;

	Position moves[4] ={
			Position( 0, 1),
			Position(-1, 0),
			Position( 1, 0),
			Position( 0,-1)
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
			   board->getPiece(position.calculateIndex(r,c)) == nullptr)
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
 * ROOK :: DRAW
 * Calls a method to draw this piece
 ******************************************************/
void Rook::draw(ogstream& gout) {

   gout.drawRook(position.getIndex(), isWhite);

}


