#ifndef PIECE_H
#define PIECE_H

#include <iostream>
#include <string>
#include <set> 
#include <utility>

#include "ChessBoard.h"
#include "Constants.h"

// Piece is an abstract class with a pure virtual function
// and is the base class for all chess pieces

class Piece 
{
public:
    using Coord = std::pair<int, int>;
    using SetOfCoords = std::set<Coord>;

    Piece(ChessBoard& ownerBoard, Game& game, bool kingOrNot, bool whiteOrNot, int initRow, int initCol);
    std::string getName();
    std::string getSymbol();
    void setRow(int newRow);
    void setCol(int newCol);
    int getRow();
    int getCol();
    bool isKing();
    bool isWhite();
    bool isInCheck();
    void setInCheck(bool checkOrNot);
    virtual void getAllPossibleMoves(SetOfCoords& possibleMoves) = 0;
    virtual ~Piece();

protected:
    ChessBoard& curBoard;
    Game& curGame;
    std::string name;
    std::string symbol;
    const bool king;
    const bool white;
    bool inCheck;
    int curRow;
    int curCol;
    void searchDiagnal(SetOfCoords& possibleMoves);
    void searchVerticalHorizontal(SetOfCoords& possibleMoves);

};

#endif