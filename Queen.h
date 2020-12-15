#ifndef QUEEN_H
#define QUEEN_H

#include <iostream>

#include "ChessBoard.h"
#include "Constants.h"
#include "Piece.h"

class Queen : public Piece
{
public:
    Queen(ChessBoard& ownerBoard, Game& game, bool kingOrNot, bool whiteOrNot, int initRow, int initCol);
    ~Queen(){}

    void findPossibleMoves(SetOfCoords& possibleMoves) override;

private:
    
};

#endif