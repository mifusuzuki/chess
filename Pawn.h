#ifndef PAWN_H
#define PAWN_H

#include <iostream>

#include "ChessBoard.h"
#include "Constants.h"
#include "Piece.h"

class Pawn : public Piece
{
public:
    Pawn(ChessBoard& ownerBoard, Game& game,
        bool kingOrNot, bool whiteOrNot, int initRow, int initCol);
    void getAllPossibleMoves(SetOfCoords& possibleMoves) override;
    ~Pawn(){}
    
private:
    bool firstMove;
    
};

#endif