#include "Game.h"
#include "Constants.h"

#include <iostream>

Game::Game()
{
    configureGame();
}

void
Game::configureGame()
{
    whitesTurn = true;
    checkMate = false;
    staleMate = false;

    std::cout << "A new game is started!" << std::endl;
}

bool
Game::isWhitesTurn()
{
    return whitesTurn;
}

bool
Game::isCheckMate()
{
    return checkMate;
}

bool
Game::isStaleMate()
{
    return staleMate;
}

void
Game::switchPlayer()
{
    if (whitesTurn)
    {
        whitesTurn = false;
        return;
    }
    whitesTurn = true;
    return;
}

void
Game::setCheckMate()
{
    checkMate = true;
}

void
Game::setStaleMate()
{
    staleMate = true;
}

void
Game::printGameStatus() const
{
    std::cout << "whitesTurn = " << whitesTurn << std::endl
    << "checkMate = " << checkMate << std::endl
    << "staleMate = " << staleMate << std::endl;
    return;
}