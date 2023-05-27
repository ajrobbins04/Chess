/***********************************************************************
 * Header File:
 *    Board
 * Author:
 *    Martin Nkala, Amber Robbins
 * Summary:
 *    Game uses this class to create a board
 *    Handle 64 pieces of a Chess Board
 *    Keeps track of the pieces' turns
 ************************************************************************/

#ifndef board_h
#define board_h

#include "uiDraw.h"

class Piece; // Forward declaration to prevent circular dependency.
class Rook;
class TestBoard;

/******************************************************
 * BOARD
 * A Chess Board
 ******************************************************/
class Board {

private:

	Piece * board[64];
	bool whiteTurn = true;

public:

   friend TestBoard;
	
   void setPiece(int pos, Piece* piece) {
	   this->board[pos] = nullptr;
	   this->board[pos] = piece;
	}

   bool getWhiteTurn()      const { return this->whiteTurn;  }
   Piece* getPiece(int pos) const { return this->board[pos]; }

   void toggleTurn() {
	  whiteTurn ? whiteTurn = false : whiteTurn = true;
   }

 };

#endif /* board_h */
