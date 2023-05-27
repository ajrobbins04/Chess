/*********************************************
 * Header file:
 *    Pawn
 * Author:
 *    Martin Nkala, Amber Robbins
 * Summary:
 *    Represents the Pawn piece on a Chess Game
 **********************************************/

#ifndef pawn_h
#define pawn_h

#include <iostream>
#include <vector>
#include "piece.h"

using namespace std;

/******************************************************
 * PAWN
 * A pawn piece for Chess
 ******************************************************/
class Pawn : public Piece {

private:
	bool hasMoved = false;
	int turnsSinceMoved = 0;
	int enemyIndex = -1;     // Set on checkEnpassant, index of enemy
	int enpassantIndex = -1; // Set on checkEnpassant, index of empty square for enpassant

public:
	Pawn(bool isWhite, Position position);

	bool getHasMoved() const { return hasMoved; }

	void toggleHasMoved() { this->hasMoved = true; }

	bool getJustMoved() const { return turnsSinceMoved == 1; }

	void incrementTurnsSinceMoved() { this->turnsSinceMoved++; }

	vector<int> getPossibleMoves(Board * board) override;

	void checkEnpassant(vector<int> * possibleMoves, Board * board);

	void draw(ogstream& gout) override;

	int getEnemyIndex() { return enemyIndex; }

	int getEnpassantIndex() { return enpassantIndex; }
};

#endif /* pawn_h */
