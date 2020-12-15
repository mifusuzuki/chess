#include <iostream>

#include "Rook.h"

Rook::Rook(ChessBoard& ownerBoard, Game& game, bool kingOrNot, bool whiteOrNot, int initRow, int initCol) : Piece(ownerBoard, game, kingOrNot, whiteOrNot, initRow, initCol)
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
Rook::findPossibleMoves(SetOfCoords& possibleMoves)
{
    searchVerticalHorizontal(possibleMoves);
}