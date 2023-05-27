/*********************************************
 * Source file:
 *    Pawn
 * Author:
 *    Martin Nkala, Amber Robbins
 * Summary:
 *    Represents the Pawn piece on a Chess Game
 **********************************************/
#include "pawn.h"

using namespace std;

/******************************************************
 * PAWN :: PAWN
 * Defines Pawn's non-default constructor.
 ******************************************************/
Pawn::Pawn(bool isWhite, Position position) {
	initialize(isWhite, position, "Pawn");
}

/******************************************************
 * PAWN :: GET POSSIBLE MOVES
 * Get a vector of all the possible moves for this piece.
 ******************************************************/
vector<int> Pawn::getPossibleMoves(Board *board) {
	vector<int> possibleMoves = {};

	int row = position.getRow();
	int col = position.getCol();
	int r;
	int c;
	int i;

	if (!getIsWhite())
	{
		c = col;

		// Forward two blank spaces.
		r = row - 2;
		i = position.calculateIndex(r, c);
		Piece* piece = board->getPiece(i);
		if (row == 6 && piece == nullptr)
			possibleMoves.push_back(i);

		// Forward one black space.
		r = row - 1;
		i = position.calculateIndex(r, c);
		piece = board->getPiece(i);
		if (r >= 0 && piece == nullptr)
			possibleMoves.push_back(i);

		// Attack left.
		c = col - 1;
		i = position.calculateIndex(r, c);
		piece = board->getPiece(i);
		if (position.isValidPosition(r, c) &&
		   piece != nullptr &&
		   piece->getIsWhite() != getIsWhite())
			possibleMoves.push_back(i);

		// Attack right.
		c = col + 1;
		i = position.calculateIndex(r, c);
		piece = board->getPiece(i);
		if (position.isValidPosition(r, c) &&
		   piece != nullptr &&
		   piece->getIsWhite() != getIsWhite())
			possibleMoves.push_back(i);
	}
	else
	{
		c = col;

		// Forward two blank spaces.
		r = row + 2;
		i = position.calculateIndex(r, c);
		Piece* piece = board->getPiece(i);
		if (row == 1 && piece == nullptr)
			possibleMoves.push_back(i);

		// Forward one blank space.
		r = row + 1;
		i = position.calculateIndex(r, c);
		piece = board->getPiece(i);
		if (r < 8 && piece == nullptr)
			possibleMoves.push_back(i);

		// Attack left.
		c = col - 1;
		i = position.calculateIndex(r, c);
		piece = board->getPiece(i);
		if (position.isValidPosition(r, c) &&
		   piece != nullptr &&
		   piece->getIsWhite() != getIsWhite())
			possibleMoves.push_back(i);

		// Attack right.
		c = col + 1;
		i = position.calculateIndex(r, c);
		piece = board->getPiece(i);
		if (position.isValidPosition(r, c) &&
		   piece != nullptr &&
		   piece->getIsWhite() != getIsWhite())
			possibleMoves.push_back(i);
	}

	checkEnpassant(&possibleMoves, board);
	return possibleMoves;
}

/******************************************************
 * PAWN :: CHECK ENPASSANT
 * Adds a possible move if pawn can do enpassant
 ******************************************************/
void Pawn::checkEnpassant(vector<int>* possibleMoves, Board* board) {
   int r = position.getRow();
   int c = position.getCol();
   bool amWhite = getIsWhite();

   // Check white pawns enpassant.
   if (amWhite) {
	  
	  if (r == 4) {

		 // Check enpassant to the left.
		 if (position.isValidColumn(c - 1) &&
			board->getPiece(position.calculateIndex(r, c - 1)) != nullptr &&
			board->getPiece(position.calculateIndex(r, c - 1))->getType() == "Pawn") {
			Pawn* enemyPawn = (Pawn*)board->getPiece(position.calculateIndex(r, c - 1));
			if (enemyPawn->getJustMoved()) {
			   enemyIndex = enemyPawn->getPosition()->getIndex();
			   int enemRow = position.getRow() + 1;
			   int enemCol = position.getCol() - 1;
			   enpassantIndex = position.calculateIndex(enemRow, enemCol);
			   possibleMoves->push_back(enpassantIndex);
			}
		 }

		 // Check enpassant to the right.
		 if (position.isValidColumn(c + 1) &&
			board->getPiece(position.calculateIndex(r, c + 1)) != nullptr &&
			board->getPiece(position.calculateIndex(r, c + 1))->getType() == "Pawn") {
			Pawn* enemyPawn = (Pawn*)board->getPiece(position.calculateIndex(r, c + 1));
			if (enemyPawn->getJustMoved()) {
			   enemyIndex = enemyPawn->getPosition()->getIndex();
			   int enemRow = position.getRow() + 1;
			   int enemCol = position.getCol() + 1;
			   enpassantIndex = position.calculateIndex(enemRow, enemCol);
			   possibleMoves->push_back(enpassantIndex);
			}
		 }
	  }
   }

   // Check black pawns enpassant.
   else {
	  if (r == 3) {

		 // Check enpassant to the left.
		 if (position.isValidColumn(c - 1) &&
			   board->getPiece(position.calculateIndex(r, c - 1)) != nullptr &&
			   board->getPiece(position.calculateIndex(r, c - 1))->getType() == "Pawn") {
			   Pawn * enemyPawn = (Pawn *)board->getPiece(position.calculateIndex(r, c - 1));
			   if (enemyPawn->getJustMoved()) {
				  enemyIndex = enemyPawn->getPosition()->getIndex();
				  int enemRow = position.getRow() - 1;
				  int enemCol = position.getCol() - 1;
				  enpassantIndex = position.calculateIndex(enemRow, enemCol);
				  possibleMoves->push_back(enpassantIndex);
			   }
		 }

		 // Check enpassant to the right.
		 if (position.isValidColumn(c + 1) &&
			   board->getPiece(position.calculateIndex(r, c + 1)) != nullptr &&
			   board->getPiece(position.calculateIndex(r, c + 1))->getType() == "Pawn") {
			   Pawn * enemyPawn = (Pawn *)board->getPiece(position.calculateIndex(r, c + 1));
			   if (enemyPawn->getJustMoved()) {
				  enemyIndex = enemyPawn->getPosition()->getIndex();
				  int enemRow = position.getRow() - 1;
				  int enemCol = position.getCol() + 1;
				  enpassantIndex = position.calculateIndex(enemRow, enemCol);
				  possibleMoves->push_back(enpassantIndex);
			   }
		 }
	  }
   }
}

/******************************************************
 * PAWN :: DRAW
 * Calls a method to draw this piece
 ******************************************************/
void Pawn::draw(ogstream& gout) {

   gout.drawPawn(position.getIndex(), isWhite);

}

