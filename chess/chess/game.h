/*********************************************
 * Header file:
 *    Game
 * Author:
 *    Martin Nkala, Amber Robbins
 * Summary:
 *    Represents an instance of a Chess Game
 *    Draws all the components
 *    Ask pieces where they can move and moves them
 **********************************************/

#ifndef game_h
#define game_h

#include <iostream>
#include <vector>

#include "board.h"
#include "king.h"
#include "queen.h"
#include "rook.h"
#include "bishop.h"
#include "knight.h"
#include "pawn.h"
#include "uiInteract.h"

/******************************************************
 * GAME
 * An instance of a Chess Game
 ******************************************************/
class Game {

private:

   Board board;

public:

   Game();

   bool move(int posFrom, int posTo);

   void checkForPromotions();

   void promotePawn(int pos, bool isWhite);

   Board* getBoard() { return &board; }

   void update(Interface* pUI);

   void draw(const Interface& ui, const vector <int>& possible);

};


#endif /* game_h */
