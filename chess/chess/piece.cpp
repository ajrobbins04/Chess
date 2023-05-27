/***********************************************************************
 * Source File:
 *    Piece
 * Author:
 *    Martin Nkala, Amber Robbins
 * Summary:
 *    Defines the structure of a Chess Piece, which is an
 *    abstract base class.
 ************************************************************************/

#include "piece.h"

void Piece::initialize(bool isWhite, Position position, string type) {
	this->isWhite = isWhite;
	this->position = position;
	this->type = type;
};

