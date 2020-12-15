#ifndef GAME_H
#define GAME_H

#include "Constants.h"

// Game object holds the status of the current game being played
// Every time a new chessboard is created or the board is cleared
// a new game begins.

class Game
{
public:    
    Game();
    ~Game(){}

    // Set/reset the class members to default state
    void configureGame();

    bool isWhitesTurn();
    bool isCheckMate();
    bool isStaleMate();
    void switchPlayer();
    void setCheckMate();
    void setStaleMate();
    void printGameStatus() const;
    
private:
    bool whitesTurn;
    bool checkMate;
    bool staleMate;
};

#endif