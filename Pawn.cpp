#include <iostream>

#include "Pawn.h"

Pawn::Pawn(ChessBoard& ownerBoard, Game& game, bool kingOrNot, bool whiteOrNot, int initRow, int initCol) : Piece(ownerBoard, game, kingOrNot, whiteOrNot, initRow, initCol)
{
    name = "Pawn";
    if (white)
    {
        symbol = "wp";
    }
    else
    {
        symbol = "bp";
    }
    firstMove = true;
}

void
Pawn::findPossibleMoves(SetOfCoords& possibleMoves)
{
    int row;
    int col;
    Coord temp;
    const ChessBoard::BoardArray& board = curBoard.getBoard();

    // White pawn

    if (white == true)
    {
        if (firstMove == true)
        {
            // Check two squares ahead

            row = curRow - 2;
            col = curCol;
            if ((row>=INDEX_MIN) && (board[row][col]==nullptr))
            {
                temp = std::make_pair(row, col);
                possibleMoves.insert(temp);
                //std::cout << "searchFoward: Coord added! [" << row << "][" << col << "] (2 squares north)" << std::endl;
            }
        }

        // Check one square ahead

        row = curRow - 1;
        col = curCol;
        if ((row>=INDEX_MIN) && (board[row][col]==nullptr))
        {
            temp = std::make_pair(row, col);
            possibleMoves.insert(temp);
            //std::cout << "searchFoward: Coord added! [" << row << "][" << col << "] (north)" << std::endl;
        }

        // Check if opponents piece present at north west diagnal
        
        row = curRow - 1;
        col = curCol - 1;
        if ((row>=INDEX_MIN) && (col>=INDEX_MIN) && (board[row][col]!=nullptr) && (board[row][col]->isWhite()!=white))
        {
            temp = std::make_pair(row, col);
            possibleMoves.insert(temp);
            //std::cout << "searchFoward: Coord added! [" << row << "][" << col << "] (north west)" << std::endl;
        }

        // Check if opponents piece present at north east diagnal
        
        row = curRow - 1;
        col = curCol + 1;
        if ((row>=INDEX_MIN) && (col<=INDEX_MAX) && (board[row][col]!=nullptr) && (board[row][col]->isWhite()!=white))
        {
            temp = std::make_pair(row, col);
            possibleMoves.insert(temp);
            //std::cout << "searchFoward: Coord added! [" << row << "][" << col << "] (north east)" << std::endl;
        }
    }

    // Black pawn

    if (white == false)
    {
        if (firstMove == true)
        {
            // Check two squares ahead

            row = curRow + 2;
            col = curCol;
            if ((row<=INDEX_MAX) && (board[row][col]==nullptr))
            {
                temp = std::make_pair(row, col);
                possibleMoves.insert(temp);
                //std::cout << "searchFoward: Coord added! [" << row << "][" << col << "] (2 squares south)" << std::endl;
            }
        }

        // Check one square ahead

        row = curRow + 1;
        col = curCol;
        if ((row<=INDEX_MAX) && (board[row][col] == nullptr))
        {
            temp = std::make_pair(row, col);
            possibleMoves.insert(temp);
            //std::cout << "searchFoward: Coord added! [" << row << "][" << col << "] (south)" << std::endl;
        }

        // Check if opponents piece present at south west diagnal
        
        row = curRow + 1;
        col = curCol - 1;
        if ((row<=INDEX_MAX) && (col>=INDEX_MIN) && (board[row][col]!=nullptr) && (board[row][col]->isWhite()!=white))
        {
            temp = std::make_pair(row, col);
            possibleMoves.insert(temp);
            //std::cout << "searchFoward: Coord added! [" << row << "][" << col << "] (south west)" << std::endl;
        }

        // Check if opponents piece present at south east diagnal
        
        row = curRow + 1;
        col = curCol + 1;
        if ((row<=INDEX_MAX) && (col<=INDEX_MAX) && (board[row][col]!=nullptr) && (board[row][col]->isWhite()!=white))
        {
            temp = std::make_pair(row, col);
            possibleMoves.insert(temp);
            //std::cout << "searchFoward: Coord added! [" << row << "][" << col << "] (south east)" << std::endl;
        }
    }
}