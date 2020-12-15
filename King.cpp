#include <iostream>

#include "King.h"

King::King(ChessBoard& ownerBoard, Game& game, bool kingOrNot, bool whiteOrNot, int initRow, int initCol) : Piece(ownerBoard, game, kingOrNot, whiteOrNot, initRow, initCol)
{
    if (white)
    {
        symbol = "wK";
    }
    else
    {
        symbol = "bK";
    }  
}

void
King::getAllPossibleMoves(SetOfCoords& possibleMoves)
{
    // Find all available squares on diagnal (no leap over other pieces)

    int row;
    int col;
    Coord tempCoord;
    const ChessBoard::BoardArray& board = curBoard.getBoard();

    // Check north

    row = curRow - 1;
    col = curCol;
    tempCoord = std::make_pair(row, col);
    
    if (row>=INDEX_MIN
        && (board[row][col]==nullptr || (board[row][col]->isWhite()!=white))
        && !curBoard.isKingInCheck(&tempCoord))
    {
        // This is a safe coord for King to move to
        possibleMoves.insert(tempCoord);
    }

    // Check south

    row = curRow + 1;
    col = curCol;
    tempCoord = std::make_pair(row, col);
    
    if (row<=INDEX_MAX
        && (board[row][col]==nullptr || (board[row][col]->isWhite()!=white))
        && !curBoard.isKingInCheck(&tempCoord))
    {
        // This is a safe coord for King to move to
        possibleMoves.insert(tempCoord);
    }

    // Check west

    row = curRow;
    col = curCol - 1;
    tempCoord = std::make_pair(row, col);
    
    if (col>=INDEX_MIN
        && (board[row][col]==nullptr || (board[row][col]->isWhite()!=white))
        && !curBoard.isKingInCheck(&tempCoord))
    {
        // This is a safe coord for King to move to
        possibleMoves.insert(tempCoord);
    }

    // Check east

    row = curRow;
    col = curCol + 1;
    tempCoord = std::make_pair(row, col);
    
    if (col<=INDEX_MAX 
        && (board[row][col]==nullptr || (board[row][col]->isWhite()!=white))
        && !curBoard.isKingInCheck(&tempCoord))
    {
        // This is a safe coord for King to move to
        possibleMoves.insert(tempCoord);
    }

    // Check north west

    row = curRow - 1;
    col = curCol - 1;
    tempCoord = std::make_pair(row, col);
    
    if (row >= INDEX_MIN && col >= INDEX_MIN 
        && (board[row][col]==nullptr || (board[row][col]->isWhite()!=white))
        && !curBoard.isKingInCheck(&tempCoord))
    {
        // This is a safe coord for King to move to
        possibleMoves.insert(tempCoord);
    }

    // Check north east

    row = curRow - 1;
    col = curCol + 1;
    tempCoord = std::make_pair(row, col);
    
    if (row >= INDEX_MIN && col <= INDEX_MAX
        && (board[row][col]==nullptr || (board[row][col]->isWhite()!=white))
        && !curBoard.isKingInCheck(&tempCoord))
    {
        // This is a safe coord for King to move to
        possibleMoves.insert(tempCoord);
    }

    // Check south west

    row = curRow + 1;
    col = curCol - 1;
    tempCoord = std::make_pair(row, col);
    
    if (row<=INDEX_MAX && col>=INDEX_MIN
        && (board[row][col]==nullptr || (board[row][col]->isWhite()!=white))
        && !curBoard.isKingInCheck(&tempCoord))
    {
        // This is a safe coord for King to move to
        possibleMoves.insert(tempCoord);
    }

    // Check south east

    row = curRow + 1;
    col = curCol + 1;
    tempCoord = std::make_pair(row, col);
    
    if (row<=INDEX_MAX && col<=INDEX_MAX
        && (board[row][col]==nullptr || (board[row][col]->isWhite()!=white))
        && !curBoard.isKingInCheck(&tempCoord))
    {
        // This is a safe coord for King to move to
        possibleMoves.insert(tempCoord);
    }

}