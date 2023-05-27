/*********************************************
 * Source file:
 *    King
 * Author:
 *    Martin Nkala, Amber Robbins
 * Summary:
 *    Represents the King piece on a Chess Game
 **********************************************/

#include "king.h"

/******************************************************
* KING :: KING
* Defines King's non-default constructor
******************************************************/
King::King(bool isWhite, Position position) {
	initialize(isWhite, position, "King");
}

/******************************************************
 * KING :: GET POSSIBLE MOVES
 * Get a vector of all the possible moves for this piece
 ******************************************************/
vector<int> King::getPossibleMoves(Board *board) {
	cout << "Getting possible moves for King" << endl;

	vector<int> possibleMoves = {};

	Position moves[8] = {
			Position(-1,  1), Position(0,  1), Position(1,  1),
			Position(-1,  0),                  Position(1,  0),
			Position(-1, -1), Position(0, -1), Position(1, -1)
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
		((board->getPiece(position.calculateIndex(r, c)) == nullptr) ||
		board->getPiece(position.calculateIndex(r, c))->getIsWhite() != getIsWhite())) {
			possibleMoves.push_back(r * 8 + c);
		}
	}

	checkCastle(&possibleMoves, board);

	return possibleMoves;
}

/******************************************************
 * KING :: CHECK CASTLE
 * Adds move to the possible moves if King can castle
 ******************************************************/
void King::checkCastle(vector<int> *possibleMoves, Board *board) {

	if (this->hasMoved) return;

	// Check white.
	if (getIsWhite()) {
		// Check left rook.
		if (board->getPiece(0) != nullptr &&
			!dynamic_cast<Rook *>(board->getPiece(0))->getHasMoved()) {
			if (board->getPiece(1) == nullptr &&
				board->getPiece(2) == nullptr &&
				board->getPiece(3) == nullptr) {
				possibleMoves->push_back(2);
			}
		}

		// Check right rook.
		if (board->getPiece(7) != nullptr &&
			!dynamic_cast<Rook *>(board->getPiece(7))->getHasMoved()) {
			if (board->getPiece(5) == nullptr &&
				board->getPiece(6) == nullptr) {
				possibleMoves->push_back(6);
			}
		}
	} else {
		// Check left rook.
		if (board->getPiece(56) != nullptr &&
			!dynamic_cast<Rook *>(board->getPiece(56))->getHasMoved()) {
			if (board->getPiece(57) == nullptr &&
				board->getPiece(58) == nullptr &&
				board->getPiece(59) == nullptr) {
				possibleMoves->push_back(58);
			}
		}

		// Check right rook.
		if (board->getPiece(63) != nullptr &&
			!dynamic_cast<Rook *>(board->getPiece(63))->getHasMoved()) {
			if (board->getPiece(61) == nullptr &&
				board->getPiece(62) == nullptr) {
				possibleMoves->push_back(62);
			}
		}
	}
}

/************************************************************************
 * KING :: DRAW
 * Calls a method to draw this piece
*************************************************************************/
void King::draw(ogstream& gout) {

   gout.drawKing(position.getIndex(), isWhite);
  
}


