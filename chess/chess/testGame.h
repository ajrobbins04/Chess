/*********************************************
 * Header file:
 *    TEST GAME
 * Author:
 *    Martin Nkala, Amber Robbins
 * Summary:
 *    Unit Test for Game class
 **********************************************/

#ifndef testGame_h
#define testGame_h

#include <iostream>
#include <vector>
#include "game.h"

using namespace std;

class TestGame {
private:

public:
	void run() {
		cout << "Running Game class tests..." << endl;

		testMovePawn();
		testInvalidMove();
		testGetPossibleMoves();
		testPromotion(); // This tests both checkForPromotions() and promotePawn().

		cout << "Game class tests passed." << endl;
	}

	void testMovePawn() {
		// Test normal valid condition.
		// Setup.
		Game game;

		// Exercise.
		// Move a pawn.
		bool success = game.move(8, 16);

		// Verify.
		assert(success);
		assert(game.getBoard()->getPiece(8) == nullptr);
		assert(game.getBoard()->getPiece(16) != nullptr);

		// Teardown.
	}

	void testInvalidMove() {
		// Setup.
		Game game;

		// Test invalid condition.
		// Try to move a pawn to an invalid position.
		bool success = game.move(16, 8);

		// Verify.
		assert(!success);
		assert(game.getBoard()->getPiece(16) == nullptr);

		// Teardown.
	}

	void testGetPossibleMoves() {
		// Setup.
		Game game;

		// Exercise.
		// Get the possible moves for a pawn.
		Piece * piece = game.getBoard()->getPiece(8);

		vector<int> possibleMoves = piece->getPossibleMoves(game.getBoard());

		// Verify.
		// Assert that the possible moves vector contains the correct values.
		vector<int> expectedMoves = {16, 24};

		for (int expectedMove : expectedMoves) {
			if(find(possibleMoves.begin(), possibleMoves.end(), expectedMove) == possibleMoves.end())
				assert(false);
		}

		// Teardown.
	}

	void testPromotion() {
		// Setup.
		Game game;

		// Move a pawn to the other end of the board.
		game.getBoard()->setPiece(56, game.getBoard()->getPiece(8));
		game.getBoard()->setPiece(8, nullptr);

		// Exercise.
		// If a promotion is available, this method will call promotePawn().
		game.checkForPromotions();

		// Verify.
		Piece * parent = game.getBoard()->getPiece(56);
		assert(dynamic_cast<Queen*>(parent) != nullptr);

		// Teardown.
	}
};


#endif /* testGame_h */
