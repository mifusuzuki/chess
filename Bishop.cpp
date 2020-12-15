
#include <iostream>
#include <set>
#include <utility>

#include "Bishop.h"
#include "Constants.h"

Bishop::Bishop(ChessBoard& ownerBoard, Game& game, bool kingOrNot, bool whiteOrNot, int initRow, int initCol) : Piece(ownerBoard, game, kingOrNot, whiteOrNot, initRow, initCol)
{
    name = "Bishop";
    if (white)
    {
        symbol = "wb";
    }
    else
    {
        symbol = "bb";
    }  
}

void
Bishop::findPossibleMoves(SetOfCoords& possibleMoves)
{
    searchDiagnal(possibleMoves);
}