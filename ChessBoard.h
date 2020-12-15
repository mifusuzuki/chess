#ifndef CHESSBOARD_H
#define CHESSBOARD_H

#include <string>
#include <set> 
#include <utility>

#include "Constants.h"
#include "Game.h"

class Piece;

class ChessBoard
{
public:
    using BoardArray = Piece* [BOARD_LENGTH][BOARD_LENGTH];
    using Coord = std::pair<int, int>;
    using SetOfCoords = std::set<Coord>;

    ChessBoard();
    void printBoard();
    void resetBoard();
    void submitMove(std::string origin, std::string destination);
    const Game& getGame() const;
    const BoardArray& getBoard() const;
    bool isKingInCheck(Coord& trialCoord);
    ~ChessBoard();
private:
    BoardArray board;
    Game curGame;
    Piece* blackKing;
    Piece* whiteKing;
    void configureBoard();
    void clearBoard();
    bool pieceCanBePlayed(int row, int col);
    void relocate(int rowOrigin, int colOrigin, int rowDest, int colDest);
    void getOpponentsCoords(SetOfCoords& opponentsCoords);
    void getDangerousCoords(SetOfCoords& dangerousCoords);
};

#endif