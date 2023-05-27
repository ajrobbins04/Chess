/*********************************************
 * Header file:
 *    TEST BOARD
 * Author:
 *    Martin Nkala, Amber Robbins
 * Summary:
 *    Unit Test for Board class
 **********************************************/

#ifndef testBoard_h
#define testBoard_h

#include <cassert>
#include "board.h"
#include "uiDraw.h"

class TestBoard
{
public:
   void run()
   {
	   cout << "Running board tests..." << endl;
		void testGetWhiteTurn();
		void testToggleWhiteTurn();
		void testGetPiece();
		void testSetPiece();
		cout << "Board tests passed!" << endl;
   }

private:
	void testGetWhiteTurn() {
	   // Setup.
	   // Exercise.
	   Board board;

	   // Verify.
	   assert(board.getWhiteTurn() == true);

	   // Teardown.
   }

   void testToggleWhiteTurn() {
		 // Setup.
		 // Exercise.
		 Board board;

		 // Verify.
		 assert(board.getWhiteTurn() == true);
		 board.toggleTurn();
		 assert(board.getWhiteTurn() == false);
		 board.toggleTurn();
		 assert(board.getWhiteTurn() == true);

		 // Teardown.
   }

   void testGetPiece() {
		// Setup.
		Game game;

		// Exercise.
		Piece * piece = game.getBoard()->getPiece(0);
		Piece * piece2 = game.getBoard()->getPiece(16);

		string type = piece->getType();

		// Verify.
		assert(type == "Rook");
		assert(piece2 == nullptr);

		// Teardown.
   }

   void testSetPiece() {
		// Setup.
		Game game;

		// Exercise.
		Piece * piece = game.getBoard()->getPiece(0);
//        Piece * piece2 = game.getBoard()->getPiece(16);
		game.getBoard()->setPiece(16, piece);
		Piece * piece3 = game.getBoard()->getPiece(16);

		string type = piece3->getType();

		// Verify.
		assert(type == "Rook");

		// Teardown.
   }
};


#endif /* testBoard_h */
