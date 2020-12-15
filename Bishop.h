#ifndef BISHOP_HPP
#define BISHOP_HPP

#include <iostream>

#include "ChessBoard.h"
#include "Constants.h"
#include "Piece.h"

// The bishop can move any number of squares diagonally
// but may not leap over other pieces.

class Bishop : public Piece
{
public:
    Bishop(ChessBoard& ownerBoard, Game& game,
            bool kingOrNot, bool whiteOrNot, int initRow, int initCol);
    void getAllPossibleMoves(SetOfCoords& possibleMoves) override;
    ~Bishop(){}
};

#endif