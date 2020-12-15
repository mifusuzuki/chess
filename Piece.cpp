#include "Piece.h"

Piece::Piece(ChessBoard& ownerBoard, Game& game, bool kingOrNot, bool whiteOrNot, int initRow, int initCol) :
    curBoard(ownerBoard),
    curGame(game),
    king(kingOrNot),
    white(whiteOrNot),
    curRow(initRow),
    curCol(initCol)
{
    inCheck = false;
}

std::string
Piece::getSymbol()
{
    return symbol;
}

std::string
Piece::getName()
{
    return name;
}

void
Piece::setRow(int newRow)
{
    curRow = newRow;
}

void
Piece::setCol(int newCol)
{
    curCol = newCol;
}

int
Piece::getRow()
{
    return curRow;
}

int
Piece::getCol()
{
    return curCol;
}

bool
Piece::isKing()
{
    return king;
}

bool
Piece::isWhite()
{
    return white;
}

bool
Piece::isInCheck()
{
    return inCheck;
}

void
Piece::setInCheck(bool checkOrNot)
{
    inCheck = checkOrNot;
}

void
Piece::searchDiagnal(SetOfCoords& possibleMoves)
{
    // Find all available squares on diagnal (no leap over other pieces)

    int row;
    int col;
    Coord temp;
    const ChessBoard::BoardArray& board = curBoard.getBoard();

    // Check north west

    row = curRow - 1;
    col = curCol - 1;

    while (row >= INDEX_MIN && col >= INDEX_MIN)
    {   
        if (board[row][col] != nullptr)
        {
            // There is an obstacle

            if (board[row][col]->isWhite() != white)
            {
                // It is the opponents piece

                temp = std::make_pair(row, col);
                possibleMoves.insert(temp);
            }
            break;
        }
        temp = std::make_pair(row, col);
        possibleMoves.insert(temp);
        row--;
        col--;
    }

    // Check north east

    row = curRow - 1;
    col = curCol + 1;
    while (row >= INDEX_MIN && col <= INDEX_MAX)
    {
        if (board[row][col] != nullptr)
        {
            // There is an obstacle

            if (board[row][col]->isWhite() != white)
            {
                // It is the opponents piece

                temp = std::make_pair(row, col);
                possibleMoves.insert(temp);
            }
            break;
        }
        temp = std::make_pair(row, col);
        possibleMoves.insert(temp);
        row --;
        col ++;
    }

    // Check south west

    row = curRow + 1;
    col = curCol - 1;
    while (row<=INDEX_MAX && col>=INDEX_MIN)
    {
        if (board[row][col] != nullptr)
        {
            // There is an obstacle

            if (board[row][col]->isWhite() != white)
            {
                // It is the opponents piece

                temp = std::make_pair(row, col);
                possibleMoves.insert(temp);
            }
            break;
        }
        temp = std::make_pair(row, col);
        possibleMoves.insert(temp);
        row ++;
        col --;
    }

    // Check south east

    row = curRow + 1;
    col = curCol + 1;
    while (row<=INDEX_MAX && col<=INDEX_MAX)
    {
        if (board[row][col] != nullptr)
        {
            // There is an obstacle

            if (board[row][col]->isWhite() != white)
            {
                // It is the opponents piece

                temp = std::make_pair(row, col);
                possibleMoves.insert(temp);
            }
            break;
        }
        temp = std::make_pair(row, col);
        possibleMoves.insert(temp);
        row ++;
        col ++;
    }
}

void
Piece::searchVerticalHorizontal(SetOfCoords& possibleMoves)
{
    // Find all available squares on vertical and horizontal

    int row;
    int col;
    Coord temp;
    const ChessBoard::BoardArray& board = curBoard.getBoard();

    // Check north

    row = curRow - 1;
    col = curCol;

    while (row >= INDEX_MIN)
    {   
        if (board[row][col] != nullptr)
        {
            // There is an obstacle

            if (board[row][col]->isWhite() != white)
            {
                // It is the opponents piece

                temp = std::make_pair(row, col);
                possibleMoves.insert(temp);
            }
            break;
        }
        temp = std::make_pair(row, col);
        possibleMoves.insert(temp);
        row--;
    }

    // Check south

    row = curRow + 1;
    col = curCol;

    while (row <= INDEX_MAX)
    {
        if (board[row][col] != nullptr)
        {
            // There is an obstacle

            if (board[row][col]->isWhite() != white)
            {
                // It is the opponents piece

                temp = std::make_pair(row, col);
                possibleMoves.insert(temp);
            }
            break;
        }
        temp = std::make_pair(row, col);
        possibleMoves.insert(temp);
        row ++;
    }

    // Check west

    row = curRow;
    col = curCol - 1;

    while (col>=INDEX_MIN)
    {
        if (board[row][col] != nullptr)
        {
            // There is an obstacle

            if (board[row][col]->isWhite() != white)
            {
                // It is the opponents piece

                temp = std::make_pair(row, col);
                possibleMoves.insert(temp);
            }
            break;
        }
        temp = std::make_pair(row, col);
        possibleMoves.insert(temp);
        col --;
    }
    
    // Check east

    row = curRow;
    col = curCol + 1;

    while (col<=INDEX_MAX)
    {
        if (board[row][col] != nullptr)
        {
            // There is an obstacle

            if (board[row][col]->isWhite() != white)
            {
                // It is the opponents piece

                temp = std::make_pair(row, col);
                possibleMoves.insert(temp);
            }
            break;
        }
        temp = std::make_pair(row, col);
        possibleMoves.insert(temp);
        col ++;
    }
}