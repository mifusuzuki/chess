#include <iostream>

#include "Knight.h"

Knight::Knight(ChessBoard& ownerBoard, Game& game, bool kingOrNot, bool whiteOrNot, int initRow, int initCol) : Piece(ownerBoard, game, kingOrNot, whiteOrNot, initRow, initCol)
{

    name = "Knight";
    if (white)
    {
        symbol = "wk";
    }
    else
    {
        symbol = "bk";
    }  
}

void
Knight::findPossibleMoves(SetOfCoords& possibleMoves)
{
    // Find all available squares on L-shape path
    // i.e. 2 steps in one direction --> 1 step in another
    // (can leap over other pieces)

    int row;
    int col;
    Coord temp;
    const ChessBoard::BoardArray& board = curBoard.getBoard();

    // Check north --> west
    // This path only works if there is 2 spaces in north and 1 space in west

    row = curRow - 2;
    col = curCol - 1;

    if (row >= INDEX_MIN && col >= INDEX_MIN)
    {   
        if ((board[row][col] == nullptr) || (board[row][col]->isWhite()!=white))
        {
            // Either a nullptr or opponent's piece at landing square

            temp = std::make_pair(row, col);
            possibleMoves.insert(temp);
            //std::cout << "searchL: Coord added! [" << row << "][" << col << "] (north --> west)" << std::endl;
        }
    }

    // Check north --> east
    // This path only works if there is 2 spaces in north and 1 space in east

    row = curRow - 2;
    col = curCol + 1;

    if (row >= INDEX_MIN && col <= INDEX_MAX)
    {   
        if ((board[row][col] == nullptr) || (board[row][col]->isWhite()!=white))
        {
            // Either a nullptr or opponent's piece at landing square

            temp = std::make_pair(row, col);
            possibleMoves.insert(temp);
            //std::cout << "searchL: Coord added! [" << row << "][" << col << "] (north --> east)" << std::endl;
        }
    }

    // Check south --> west
    // This path only works if there is 2 spaces in south and 1 space in west

    row = curRow + 2;
    col = curCol - 1;

    if (row <= INDEX_MAX && col >= INDEX_MIN)
    {   
        if ((board[row][col] == nullptr) || (board[row][col]->isWhite()!=white))
        {
            // Either a nullptr or opponent's piece at landing square

            temp = std::make_pair(row, col);
            possibleMoves.insert(temp);
            //std::cout << "searchL: Coord added! [" << row << "][" << col << "] (south --> west)" << std::endl;
        }
    }

    // Check south --> east
    // This path only works if there is 2 spaces in south and 1 space in east

    row = curRow + 2;
    col = curCol + 1;

    if (row <= INDEX_MAX && col <= INDEX_MAX)
    {   
        if ((board[row][col] == nullptr) || (board[row][col]->isWhite()!=white))
        {
            // Either a nullptr or opponent's piece at landing square

            temp = std::make_pair(row, col);
            possibleMoves.insert(temp);
            //std::cout << "searchL: Coord added! [" << row << "][" << col << "] (south --> east)" << std::endl;
        }
    }

    // Check west --> north
    // This path only works if there is 2 spaces in west and 1 space in north

    row = curRow - 1;
    col = curCol - 2;

    if (row >= INDEX_MIN && col >= INDEX_MIN)
    {   
        if ((board[row][col] == nullptr) || (board[row][col]->isWhite()!=white))
        {
            // Either a nullptr or opponent's piece at landing square

            temp = std::make_pair(row, col);
            possibleMoves.insert(temp);
            //std::cout << "searchL: Coord added! [" << row << "][" << col << "] (west --> north)" << std::endl;
        }
    }

    // Check west --> south
    // This path only works if there is 2 spaces in west and 1 space in south

    row = curRow + 1;
    col = curCol - 2;

    if (row <= INDEX_MAX && col >= INDEX_MIN)
    {   
        if ((board[row][col] == nullptr) || (board[row][col]->isWhite()!=white))
        {
            // Either a nullptr or opponent's piece at landing square

            temp = std::make_pair(row, col);
            possibleMoves.insert(temp);
            //std::cout << "searchL: Coord added! [" << row << "][" << col << "] (west --> south)" << std::endl;
        }
    }

    // Check east --> north
    // This path only works if there is 2 spaces in east and 1 space in north

    row = curRow - 1;
    col = curCol + 2;

    if (row >= INDEX_MIN && col <= INDEX_MAX)
    {   
        if ((board[row][col] == nullptr) || (board[row][col]->isWhite()!=white))
        {
            // Either a nullptr or opponent's piece at landing square

            temp = std::make_pair(row, col);
            possibleMoves.insert(temp);
            //std::cout << "searchL: Coord added! [" << row << "][" << col << "] (east --> north)" << std::endl;
        }
    }

    // Check east --> south
    // This path only works if there is 2 spaces in east and 1 space in south

    row = curRow + 1;
    col = curCol + 2;

    if (row <= INDEX_MAX && col <= INDEX_MAX)
    {   
        if ((board[row][col] == nullptr) || (board[row][col]->isWhite()!=white))
        {
            // Either a nullptr or opponent's piece at landing square

            temp = std::make_pair(row, col);
            possibleMoves.insert(temp);
            //std::cout << "searchL: Coord added! [" << row << "][" << col << "] (east --> south)" << std::endl;
        }
    }
    
}