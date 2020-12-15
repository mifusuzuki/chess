#ifndef QUEEN_H
#define QUEEN_H

#include <iostream>

#include "ChessBoard.h"
#include "Constants.h"
#include "Piece.h"

class Queen : public Piece
{
public:
    Queen(ChessBoard& ownerBoard, Game& game,
        bool kingOrNot, bool whiteOrNot, int initRow, int initCol);
    void getAllPossibleMoves(SetOfCoords& possibleMoves) override;
     ~Queen(){}
};

#endif