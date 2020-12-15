#ifndef KNIGHT_H
#define KNIGHT_H

#include <iostream>

#include "ChessBoard.h"
#include "Constants.h"
#include "Piece.h"

class Knight : public Piece
{
public:
    Knight(ChessBoard& ownerBoard, Game& game, bool kingOrNot, bool whiteOrNot, int initRow, int initCol);
    void getAllPossibleMoves(SetOfCoords& possibleMoves) override;
    ~Knight(){}
    
private:
    
};

#endif