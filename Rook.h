#ifndef ROOK_H
#define ROOK_H

#include <iostream>

#include "ChessBoard.h"
#include "Constants.h"
#include "Piece.h"

class Rook : public Piece
{
public:
    Rook(ChessBoard& ownerBoard, Game& game,
        bool kingOrNot, bool whiteOrNot, int initRow, int initCol);
    void getAllPossibleMoves(SetOfCoords& possibleMoves) override;
    ~Rook(){}
};

#endif