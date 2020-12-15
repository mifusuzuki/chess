#ifndef QUEEN_H
#define QUEEN_H

#include <iostream>

#include "ChessBoard.h"
#include "Constants.h"
#include "Piece.h"

// The queen combines the power of the rook and bishop and can
// move any number of squares along rank, file, or diagonal,
// but it may not leap over other pieces.

class Queen : public Piece
{
public:
    Queen(ChessBoard& ownerBoard, Game& game,
        bool kingOrNot, bool whiteOrNot, int initRow, int initCol);
    void getAllPossibleMoves(SetOfCoords& possibleMoves) override;
     ~Queen(){}
};

#endif