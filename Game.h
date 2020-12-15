#ifndef GAME_H
#define GAME_H

#include "Constants.h"

class Game
{
public:    
    Game();
    ~Game(){}
    bool isWhitesTurn();
    bool isCheckMate();
    bool isStaleMate();
    void switchPlayer();
    void setCheckMate();
    void setStaleMate();
    void printGameStatus() const;
    void configureGame();
    
private:
    bool whitesTurn;
    bool checkMate;
    bool staleMate;
    
    //bool result;
};

#endif