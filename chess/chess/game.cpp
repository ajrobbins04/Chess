/*********************************************
 * Source file:
 *    Game
 * Author:
 *    Martin Nkala, Amber Robbins
 * Summary:
 *    Represents an instance of a Chess Game
 *    Draws all the components
 *    Ask pieces where they can move and moves them
 **********************************************/

#include "game.h"

 /******************************************************
  * GAME :: GAME
  * Defines Game's default constructor.
  ******************************************************/
Game::Game() {

	// Construct white pieces.
	auto * whiteRook1 = new Rook(true, 0);
	board.setPiece(0, whiteRook1);

	auto * whiteKnight1 = new Knight(true, 1);
	board.setPiece(1, whiteKnight1);

	auto * whiteBishop1 = new Bishop(true, 2);
	board.setPiece(2, whiteBishop1);

	auto * whiteQueen = new Queen(true, 3);
	board.setPiece(3, whiteQueen);

	auto * whiteKing = new King(true, 4);
	board.setPiece(4, whiteKing);

	auto * whiteBishop2 = new Bishop(true, 5);
	board.setPiece(5, whiteBishop2);

	auto * whiteKnight2 = new Knight(true, 6);
	board.setPiece(6, whiteKnight2);

	auto * whiteRook2 = new Rook(true, 7);
	board.setPiece(7, whiteRook2);

	for (int i = 8; i < 16; i++) { // White pawns
	   auto* whitePawn = new Pawn(true, i);
	   board.setPiece(i, whitePawn);
	}

	// Construct black pieces.
	auto * blackRook1 = new Rook(false, 56);
	board.setPiece(56, blackRook1);

	auto * blackKnight1 = new Knight(false, 57);
	board.setPiece(57, blackKnight1);

	auto * blackBishop1 = new Bishop(false, 58);
	board.setPiece(58, blackBishop1);

	auto * blackQueen = new Queen(false, 59);
	board.setPiece(59, blackQueen);

	auto * blackKing = new King(false, 60);
	board.setPiece(60, blackKing);

	auto * blackBishop2 = new Bishop(false, 61);
	board.setPiece(61, blackBishop2);

	auto * blackKnight2 = new Knight(false, 62);
	board.setPiece(62, blackKnight2);

	auto * blackRook2 = new Rook(false, 63);
	board.setPiece(63, blackRook2);

	for (int i = 48; i < 56; i++) {  // Black pawns
		auto * blackPawn = new Pawn(false, i);
		board.setPiece(i, blackPawn);
	}

	for (int i = 16; i < 48; i++) {  // All the blank spaces
		board.setPiece(i, nullptr);
	}
}

/******************************************************
 * GAME :: MOVE
 * Move pieces accross the board and handles the logic
 * of special movements.
 ******************************************************/
bool Game::move(int posFrom, int posTo) {

	// Check if positions are within the board boundaries.
	if (posFrom < 0 || posFrom > 63 || posTo < 0 ||
		posTo > 63 || board.getPiece(posFrom) == nullptr) {
		return false;
	}

	Piece * piece = board.getPiece(posFrom);
	vector <int> possibleMoves = piece->getPossibleMoves(&board);

	// Don't allow movements if isn't a player's turn.
	if (piece->getIsWhite() != board.getWhiteTurn()) {
		return false;
	}

	for (int & possibleMove : possibleMoves) {
		if (possibleMove == posTo) {

			// Normal movements
			board.setPiece(posTo, piece);               // Move piece to.
			piece->getPosition()->setFromIndex(posTo);    // Set piece's position.
			board.setPiece(posFrom, nullptr);      // Remove piece from.
			board.toggleTurn();

			// Pawn especial movements
			if (piece->getType() == "Pawn") {
				auto * pawn = dynamic_cast<Pawn *>(piece);
				pawn->toggleHasMoved();
				// Enpassant
				if ( posTo == pawn->getEnpassantIndex() ) {
				   board.setPiece(pawn->getEnemyIndex(), nullptr);
				}
				// Promotion
				checkForPromotions();

			// King especial movements
			} else if (piece->getType() == "King") {
				auto * king = dynamic_cast<King *>(piece);
				king->toggleHasMoved();

				// Castle
				if(posTo - posFrom == 2) {
					auto * rook = dynamic_cast<Rook *>(board.getPiece(posTo + 1));
					rook->toggleHasMoved();
					board.setPiece(posTo - 1, rook);
					rook->getPosition()->setFromIndex(posTo - 1);
					board.setPiece(posTo + 1, nullptr);
				} else if (posTo - posFrom == -2) {
					cout << "True" << endl;
					auto * rook = dynamic_cast<Rook *>(board.getPiece(posTo - 2));
					rook->toggleHasMoved();
					board.setPiece(posTo + 1, rook);
					rook->getPosition()->setFromIndex(posTo + 1);
					board.setPiece(posTo - 2, nullptr);
				}

			// Rook especial movements
			} else if (piece->getType() == "Rook") {
				auto * rook = dynamic_cast<Rook *>(piece);
				rook->toggleHasMoved();
			}

			return true;
		}
	}

	return false;
}

/******************************************************
 * GAME :: CHECK FOR PROMOTIONS
 *  pawn
 * reaches the oponents's edge of the board.
 ******************************************************/
void Game::checkForPromotions() {
	for (int i = 0; i<8; i++) {
		Piece* piece = board.getPiece(i);
		if (piece != nullptr && piece->getType() == "Pawn" && \
		   !piece->getIsWhite()) {
		   promotePawn(i, false);
		}
	}

	for (int i = 56; i<64; i++) {
		Piece* piece = board.getPiece(i);
		if (piece != nullptr && piece->getType() == "Pawn" && \
		   piece->getIsWhite()) {
		   promotePawn(i, true);
		}
	}
}

/******************************************************
 * GAME :: PROMOTE PAWN
 * Promote a Pawn piece into another piece
 ******************************************************/
void Game::promotePawn(int pos, bool isWhite) {
	delete board.getPiece(pos);
	board.setPiece(pos, nullptr);
	auto * queen = new Queen(isWhite, Position(pos)); // Promote to a Queen
	board.setPiece(pos, queen);
}

/******************************************************
 * GAME :: UPDATE
 * Invokes all the actions needed to play the Chess Game
 ******************************************************/
void Game::update(Interface* pUI) {

   vector <int> possible;


   // move
   if (move(pUI->getPreviousPosition(), pUI->getSelectPosition())) {
		pUI->clearSelectPosition();
		for (int i = 0; i < 64; i++) {
			Piece* piece = board.getPiece(i);
			if (piece != nullptr && piece->getType() == "Pawn") {
				auto * pawn = dynamic_cast<Pawn *>(board.getPiece(i));
				if (pawn->getHasMoved()) {
					pawn->incrementTurnsSinceMoved();
				}
			}
		}
   }
   else {
		if (pUI->getSelectPosition() != -1 &&
			board.getPiece(pUI->getSelectPosition()) != nullptr) {
			Piece *piece = board.getPiece(pUI->getSelectPosition());
			possible = piece->getPossibleMoves(&board);
		}
   }

   // if we clicked on a blank spot, then it is not selected
   if (pUI->getSelectPosition() != -1 &&
	   board.getPiece(pUI->getSelectPosition()) == nullptr)
	  pUI->clearSelectPosition();

   // draw the board
   draw(*pUI, possible);
}

/***************************************************
 * GAME :: DRAW
 * Draw the current state of the game
 ***************************************************/
void Game::draw(const Interface& ui, const vector <int>& possible) {
   ogstream gout;

   // draw the checkerboard
   gout.drawBoard();

   // draw any selections
   gout.drawHover(ui.getHoverPosition());
   gout.drawSelected(ui.getSelectPosition());

   // draw the possible moves
   for (const int& position : possible) {
	  gout.drawPossible(position);
   }

   // draw the pieces
   for (int i = 0; i < 64; i++) {
	  Piece* piece = board.getPiece(i);

	  if (piece != nullptr)
		 piece->draw(gout);
   }
}

