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
    // Type to hold a pair of row and col values
    using Coord = std::pair<int, int>;
    // Type to hold a set of coordinate pairs
    using SetOfCoords = std::set<Coord>;

    Piece(ChessBoard& ownerBoard, Game& game,
            bool kingOrNot, bool whiteOrNot, int initRow, int initCol);
    std::string getName();
    std::string getSymbol();
    void setRow(int newRow);
    void setCol(int newCol);
    int getRow();
    int getCol();
    bool isKing();
    bool isWhite();

    // Returns true if King is in check
    bool isInCheck();

    // Set King in either check or uncheck state
    void setInCheck(bool checkOrNot);

    // Find all possible moves the piece can make from its current location
    // and append them to the passed set
    virtual void getAllPossibleMoves(SetOfCoords& possibleMoves) = 0;

    virtual ~Piece(){}

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

    // Find all possible moves the piece can make from its current location
    // in all diagnal directions and append them to the passed set
    void searchDiagnal(SetOfCoords& possibleMoves);

    // Find all possible moves the piece can make from its current location
    // in all vertical and horizontal directions
    // and append them to the passed set
    void searchVerticalHorizontal(SetOfCoords& possibleMoves);

};

#endif