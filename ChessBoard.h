#ifndef CHESSBOARD_H
#define CHESSBOARD_H

#include <array>
#include <string>
#include <set> 
#include <utility>
#include <vector>

#include "Constants.h"
#include "Game.h"

// ChessBoard object has two main functions submitMove() and resetBoard()
// and other functions that helps to implement them. It is responsible for
// managing and deleting all heap allocated piece objectsthat it holds on 
// the board.

class Piece;

class ChessBoard
{
public:
    // Type of 2D array that holds pointers to heap allocated Piece objects
    using BoardArray = Piece* [BOARD_LENGTH][BOARD_LENGTH];
    // Type to hold a pair of row and col values
    // (This type is also used in Piece.h but I have made it 
    // non-global and redefined it here for readability purposes)
    using Coord = std::pair<int, int>;
    // Type to hold a set of coordinate pairs
    // (Same as above)
    using SetOfCoords = std::set<Coord>;
    
    ChessBoard();

    void printBoard();
    const Game& getGame() const;
    const BoardArray& getBoard() const;

    // Sets the board to default and restarts the game
    void resetBoard();

    // Checks the validity of the move and relocates the piece
    void submitMove(std::string origin, std::string destination);
    
    // If no argument is given, checks if the current player's King is in check
    // and if there is an coord passed in, checks if the King will be in check
    // in that position with the current state of the board. The former is used
    // after a move is made to see if the move has made the opponent in check
    // and the latter is used to during finding all possible moves King can make
    // and ensures that King is not walking into check
    bool isKingInCheck(Coord* coord=nullptr);

    ~ChessBoard();
private:
    BoardArray board;
    Game curGame;

    // Quick access pointer to blackKing which gets destroyed in clearBoard()
    Piece* blackKing;

    // Quick access pointer to whiteKing which gets destroyed in clearBoard()
    Piece* whiteKing;

    // Container that gets filled with permitted moves a checked player can make
    // It gets emptied once the King moves out of check
    std::vector<std::array<int, 4> > permittedMoves;

    // Set/Reset board to the default state
    void configureBoard();

    // Deletes all heap allocated objects
    // and sets all necessary pointers to nullptr
    void clearBoard();

    // Pre-move check
    bool canPieceBePlayed(int row, int col);

    // Utility function of isValidMove() and checks if the move being made
    // is included in permittedMove container
    bool isPermittedMove(int rowOrigin, int colOrigin,
                        int rowDest, int colDest);

    // Checks if the move being submitted is valid or not
    bool isValidMove(int rowOrigin, int colOrigin, int rowDest, int colDest);

    // Checks for stalemate
    bool canCurPlayerMove();

    // Simulates what would happen if a piece is moved - more specifically
    // whether it will uncheck the current King in check
    // If it does, the coordinate is added to permittedMoves container
    void simulateMove(int rowOrigin, int colOrigin, int rowDest, int colDest);

    // Checks if King currently in check can be unchecked
    bool canKingBeUnchecked();

    // Makes move and handles any exisiting piece at destination
    void pieceRelocate(int rowOrigin, int colOrigin, int rowDest, int colDest);

    // Find where oppoent's pieces are and add them to passed set
    void getOpponentsCoords(SetOfCoords& opponentsCoords);

    // Find where current player's pieces are and add them to passed set
    void getCurPlayersCoords(SetOfCoords& currentPlayersCoords);

    // Utility function of isKingInCheck()
    void getAllCoordsOpponentCanReach(SetOfCoords& dangerousCoords);
};

#endif