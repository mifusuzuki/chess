#ifndef KING_H
#define KING_H

#include <iostream>

#include "ChessBoard.h"
#include "Constants.h"
#include "Piece.h"

class King : public Piece
{
public:
    King(ChessBoard& ownerBoard, Game& game, bool kingOrNot, bool whiteOrNot, int initRow, int initCol);
    ~King(){}

    void findPossibleMoves(SetOfCoords& possibleMoves) override;
    
private:
    
};

#endif