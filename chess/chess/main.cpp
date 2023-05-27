/*********************************************
 * Source file:
 *    MAIN
 * Author:
 *    Martin Nkala, Amber Robbins
 * Summary:
 *    Starts an instance of a Game
 **********************************************/

#include <set>            // for STD::SET
#include <cassert>        // for ASSERT
#include <fstream>        // for IFSTREAM
#include <string>         // for STRING
#include <iostream>

#include "uiInteract.h"   // for Interface
#include "uiDraw.h"       // for draw*
#include "game.h"
#include "testRunner.h"

using namespace std;

/*************************************
 * Get called back from OpenGL to draw a frame.
 * Starts the game
 **************************************/
void callBack(Interface *pUI, void * p)
{
   // Cast the void pointer into a game object.
   Game * game = (Game *)p;

   // Run the game.
   game->update(pUI);
}

/*********************************
 * Main
 *********************************/
#ifdef _WIN32
#include <windows.h>
int WINAPI WinMain(
   _In_ HINSTANCE hInstance,
   _In_opt_ HINSTANCE hPrevInstance,
   _In_ PSTR pCmdLine,
   _In_ int nCmdShow)
#else // !_WIN32
int main(int argc, char** argv)
#endif // !_WIN32
{
   Interface ui("Chess");
   ui.setFramesPerSecond(60);

   Game game;
   runTests();

#ifdef _WIN32
 //  int    argc;
 //  LPWSTR * argv = CommandLineToArgvW(GetCommandLineW(), &argc);
 //  string filename = argv[1];
 //if (__argc == 2)
 //   readFile(__argv[1], board);
#else // !_WIN32
//   if (argc == 2)
//      readFile(argv[1], board);
#endif // !_WIN32

   // set everything into action
   ui.run(callBack, &game);

   return 0;
}

