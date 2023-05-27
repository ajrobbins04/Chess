/*************************************************************
*  Source file:
*    	TEST RUNNER
* Author:
*    	Martin Nkala, Amber Robbins
* Summary:
* 	Runs all test cases for the Position, Game,
* 	and Board classes;
* ****************************************************************/

#ifndef testRunner_h
#define testRunner_h

#include "testGame.h"
#include "testBoard.h"

void runTests()
{
	TestGame().run();
	TestBoard().run();
}


#endif /* testRunner_h */
