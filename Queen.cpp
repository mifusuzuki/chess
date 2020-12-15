#include <iostream>

#include "Queen.h"

Queen::Queen(ChessBoard& ownerBoard, Game& game, bool kingOrNot, bool whiteOrNot, int initRow, int initCol) : Piece(ownerBoard, game, kingOrNot, whiteOrNot, initRow, initCol)
{
    name = "Queen";
    if (white)
    {
        symbol = "wQ";
    }
    else
    {
        symbol = "bQ";
    }  
}

void
Queen::getAllPossibleMoves(SetOfCoords& possibleMoves)
{
    searchDiagnal(possibleMoves);
    searchVerticalHorizontal(possibleMoves);
}