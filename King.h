#ifndef KING_H
#define KING_H

#include <iostream>

#include "ChessBoard.h"
#include "Constants.h"
#include "Piece.h"

// The king moves one square in any direction

class King : public Piece
{
public:
    King(ChessBoard& ownerBoard, Game& game,
        bool kingOrNot, bool whiteOrNot, int initRow, int initCol);
    void getAllPossibleMoves(SetOfCoords& possibleMoves) override;
    ~King(){}
};

#endif