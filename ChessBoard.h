#ifndef CHESSBOARD_H
#define CHESSBOARD_H

#include <array>
#include <string>
#include <set> 
#include <utility>
#include <vector>

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
    bool isKingInCheck(Coord* coord=nullptr);
    ~ChessBoard();
private:
    BoardArray board;
    Game curGame;
    Piece* blackKing;
    Piece* whiteKing;
    std::vector<std::array<int, 4> > permittedMoves;
    void configureBoard();
    void clearBoard();
    bool isPermittedMove(int rowOrigin, int colOrigin, int rowDest, int colDest);
    bool isValidMove(int rowOrigin, int colOrigin, int rowDest, int colDest);
    bool canCurPlayerMove();
    void simulateMove(int rowOrigin, int colOrigin, int rowDest, int colDest);
    bool canKingBeUnchecked();
    bool canPieceBePlayed(int row, int col);
    void pieceRelocate(int rowOrigin, int colOrigin, int rowDest, int colDest);
    void getOpponentsCoords(SetOfCoords& opponentsCoords);
    void getCurPlayersCoords(SetOfCoords& currentPlayersCoords);
    void getAllCoordsOpponentCanReach(SetOfCoords& dangerousCoords);
};

#endif