#ifndef PAWN_H
#define PAWN_H

#include <iostream>

#include "ChessBoard.h"
#include "Constants.h"
#include "Piece.h"

//The pawn may move forward to the unoccupied square immediately in front of it
// on the same file; or on its first move it may advance two squares along the
// same file provided both squares are unoccupied; or it may move to a square
// occupied by an opponent’s piece which is diagonally in front of it on an
// adjacent file, capturing that piece.

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