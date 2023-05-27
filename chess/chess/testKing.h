 /*********************************************
 * Header file:
 *    TEST KING
 * Author:
 *    Martin Nkala, Amber Robbins
 * Summary:
 *    Unit Test for King class
 **********************************************/

#ifndef testKing_h
#define testKing_h

#include <iostream>
#include <vector>
#include "board.h"
#include "king.h"

using namespace std;

class TestKing {
private:

public:
	void run() {
		testInitialize();
		testGetPossibleMoves();
		testCheckCastle();

		cout << "King tests passed!" << endl;
	}

	void testInitialize() {
		// Setup.
		King kingWhite;
		kingWhite.initialize(true, 4); // White.

		King kingBlack;
		kingBlack.initialize(false, 60); // Black.

		// Exercise and Verify.
		assert(kingWhite.getIndex() == 4);
		assert(kingBlack.getIndex() == 60);

		// Teardown.
	}

	void testGetPossibleMoves() {
		// Setup
		Game game;

		// Exercise and Verify.
		// Assert that upon board initialization, the king has no possible moves.
		bool moved = game.move(4, 12);
		assert(!moved);

		// No teardown needed here.

		// Setup
		// Remove pieces directly surrounding the king.
		game.getBoard()->setPiece(12, nullptr);

		bool moved2 = game.move(4, 12);

		// Exercise and Verify.
		// Assert that the kings possible moves are the same as the possible moves vector.
		assert(board.getPiece(3)->getPossibleMoves(&board) == possibleMoves);

		// Teardown.
	}

	void testCheckCastle() {
		// Setup.
		Board board = Board();
		board.setPiece(1, nullptr);
		board.setPiece(2, nullptr);
		board.setPiece(3, nullptr);
		board.setPiece(5, nullptr);
		board.setPiece(6, nullptr);

		// Exercise.
		vector<int> possibleMoves;
		possibleMoves = board.getPiece(4)->getPossibleMoves(&board);

		// Verify.
		assert(find(possibleMoves.begin(), possibleMoves.end(), 2) != possibleMoves.end());
		assert(find(possibleMoves.begin(), possibleMoves.end(), 6) != possibleMoves.end());

		// Teardown.
	}
};


#endif /* testKing_h */
