#ifndef ROOK_H
#define ROOK_H

#include <iostream>

#include "ChessBoard.h"
#include "Constants.h"
#include "Piece.h"

// The rook (or castle) can move any number of squares along
// any rank or file, but may not leap over other pieces.

class Rook : public Piece
{
public:
    Rook(ChessBoard& ownerBoard, Game& game,
        bool kingOrNot, bool whiteOrNot, int initRow, int initCol);
    void getAllPossibleMoves(SetOfCoords& possibleMoves) override;
    ~Rook(){}
};

#endif