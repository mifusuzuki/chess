#include <iostream>

#include "Rook.h"

Rook::Rook(ChessBoard& ownerBoard, Game& game,
            bool kingOrNot, bool whiteOrNot, int initRow, int initCol)
    : Piece(ownerBoard, game, kingOrNot, whiteOrNot, initRow, initCol)
{
    name = "Rook";

    if (white)
    {
        symbol = "wr";
    }
    else
    {
        symbol = "br";
    }  
}

void
Rook::getAllPossibleMoves(SetOfCoords& possibleMoves)
{
    // Base class Piece's member function
    searchVerticalHorizontal(possibleMoves);
}