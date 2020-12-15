#ifndef KNIGHT_H
#define KNIGHT_H

#include <iostream>

#include "ChessBoard.h"
#include "Constants.h"
#include "Piece.h"

// The knight moves to any of the closest squares that are not on the 
// same rank, file, or diagonal, thus the move forms an ’L’-shape:
// two squares vertically and one square horizontally, or two squares
// horizontally and one square vertically. The knight is the only piece
// that can leap over other pieces.

class Knight : public Piece
{
public:
    Knight(ChessBoard& ownerBoard, Game& game,
            bool kingOrNot, bool whiteOrNot, int initRow, int initCol);
    void getAllPossibleMoves(SetOfCoords& possibleMoves) override;
    ~Knight(){}
};

#endif