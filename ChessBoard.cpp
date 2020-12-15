#include "ChessBoard.h"
#include "Constants.h"
#include "Helper.h"
#include "Piece.h"

#include "Bishop.h"
#include "King.h"
#include "Knight.h"
#include "Pawn.h"
#include "Queen.h"
#include "Rook.h"

ChessBoard::ChessBoard()
{
    // Set up the board
    configureBoard();
}

void
ChessBoard::configureBoard()
{
    // Create a board filled with nullptrs
    
    for (int i=0; i<BOARD_LENGTH; i++)
    {
        for (int j=0; j<BOARD_LENGTH; j++)
        {
            board[i][j] = nullptr;
        }

    }

    // Create all chess pieces on the heap and place them on the board

    bool king = true;
    bool notKing = false;

    // Black pieces

    bool black = false;
    board[0][0] = new Rook(*this, curGame, notKing, black, 0, 0);
    board[0][1] = new Knight(*this, curGame, notKing, black, 0, 1);
    board[0][2] = new Bishop(*this, curGame, notKing, black, 0, 2);
    board[0][3] = new Queen(*this, curGame, notKing, black, 0, 3);
    board[0][4] = new King(*this, curGame, king, black, 0, 4);
    board[0][5] = new Bishop(*this, curGame, notKing, black, 0, 5);
    board[0][6] = new Knight(*this, curGame, notKing, black, 0, 6);
    board[0][7] = new Rook(*this, curGame, notKing, black, 0, 7);
    for (int i=0; i<BOARD_LENGTH; i++)
    {
        board[1][i] = new Pawn(*this, curGame, notKing, black, 1, i);
    }

    // White pieces
    bool white = true;
    board[7][0] = new Rook(*this, curGame, notKing, white, 7, 0);
    board[7][1] = new Knight(*this, curGame, notKing, white, 7, 1);
    board[7][2] = new Bishop(*this, curGame, notKing, white, 7, 2);
    board[7][3] = new Queen(*this, curGame, notKing, white, 7, 3);
    board[7][4] = new King(*this, curGame, king, white, 7, 4);
    board[7][5] = new Bishop(*this, curGame, notKing, white, 7, 5);
    board[7][6] = new Knight(*this, curGame, notKing, white, 7, 6);
    board[7][7] = new Rook(*this, curGame, notKing, white, 7, 7);
    for (int i=0; i<BOARD_LENGTH; i++)
    {
        board[6][i] = new Pawn(*this, curGame, notKing, white, 6, i);
    }

    // Allow quick access to black and white Kings
    blackKing = board[0][4];
    whiteKing = board[7][4];
}

void
ChessBoard::resetBoard()
{
    clearBoard();
    configureBoard();
    curGame.configureGame();
}

void
ChessBoard::clearBoard()
{
    // Set quick access pointers to null

    blackKing = nullptr;
    whiteKing = nullptr;

    // Delete all heap allocated objects

    for (int i=0; i<BOARD_LENGTH; i++)
    {
        for (int j=0; j<BOARD_LENGTH; j++)
        {
            if (!(board[i][j] == nullptr))
            {
                delete board[i][j];
                board[i][j] = nullptr;
            }
        }
    }
}

void
ChessBoard::printBoard()
{
    std::cout << " ";
    for (int j=0; j<BOARD_LENGTH; j++)
    {
        std::cout << " --- ";
    }
    std::cout << std::endl;
    for (int i=0; i<BOARD_LENGTH; i++)
    {
        std::cout << " | ";
        for (int j=0; j<BOARD_LENGTH; j++)
        {
            if (board[i][j] == nullptr)
            {
                std::cout << ".." << " | ";
            }
            else
            {
                std::cout << board[i][j]->getSymbol() << " | ";
            }
        }
        std::cout << std::endl;
        std::cout << " ";
        for (int j=0; j<BOARD_LENGTH; j++)
        {
            std::cout << " --- ";
        }
        std::cout << std::endl;
    }

}

void
ChessBoard::relocate(int rowOrigin, int colOrigin, int rowDest, int colDest)
{
    // Print Narration

    if(board[rowOrigin][colOrigin]->isWhite())
    {
        std::cout << "White's ";
    }
    else
    {
        std::cout << "Black's ";
    }
    std::cout << board[rowOrigin][colOrigin]->getName() 
            << " moves from " << getPos(rowOrigin, colOrigin)
            << " to " << getPos(rowDest, colDest);

    // Capture if any piece present at destination

    if (board[rowDest][colDest] != nullptr)
    {
        // Kill opponent's piece
        
        if (board[rowDest][colDest]->isKing())
        {
            // Check if King is in checkmate (still more valid moves)

            curGame.setCheckMate();

            if(board[rowDest][colDest]->isWhite())
            {
                std::cout << "Black is in checkmate" << std::endl;
                curGame.setBlackKingInCheck(true);
            }

            if(!board[rowDest][colDest]->isWhite())
            {
                std::cout << "White is in checkmate" << std::endl;
                curGame.setWhiteKingInCheck(true);
            }

        }

        // Conitnue printing narration

        std::cout << " taking ";
        if (board[rowDest][colDest]->isWhite())
        {
            std::cout << "White's ";
        }
        else
        {
            std::cout << "Black's ";
        }
        std::cout << board[rowDest][colDest]->getName();

        // destroy heap allocated piece that was captured

        delete board[rowDest][colDest];       
    }

    std::cout << std::endl;

    // Take over

    board[rowDest][colDest] = board[rowOrigin][colOrigin];
    board[rowOrigin][colOrigin] = nullptr;
    
    // Update info

    board[rowDest][colDest]->setRow(rowDest);
    board[rowDest][colDest]->setCol(colDest);
    
    return;
}

void
ChessBoard::submitMove(std::string origin, std::string destination)
{
    if (curGame.isCheckMate() || curGame.isStaleMate())
    {
        std::cerr << "[Error] Game is finished already!" << std::endl;
        return;
    }

    std::cout << "This is ";
    if (curGame.isWhitesTurn())
    {
        std::cout << "White's ";
    }
    if (!curGame.isWhitesTurn())
    {
        std::cout << "Black's ";
    }
    std::cout << "turn!" << std::endl;

    if (!(isValidPos(origin) && isValidPos(destination)))
    {
        return;
    }
    
    // Convert pos to row and col indexes

    int rowOrigin = getRow(origin);
    int colOrigin = getCol(origin);
    int rowDest = getRow(destination);
    int colDest = getCol(destination);

    // Check there is a piece at origin and is the current player's piece

    if (!pieceCanBePlayed(rowOrigin, colOrigin))
    {
        return;
    }

    // Check if move is valid

    if (!(board[rowOrigin][colOrigin]->isValidMove(rowDest, colDest)))
    {
        // Print Narration
    
        if(board[rowOrigin][colOrigin]->isWhite())
        {
            std::cout << "White's ";
        }
        else
        {
            std::cout << "Black's ";
        }
        std::cout << board[rowOrigin][colOrigin]->getName() 
                << " cannot move to " << getPos(rowDest, colDest)
                << "!" << std::endl;

        return;
    }

    // Make move
    relocate(rowOrigin, colOrigin, rowDest, colDest);
    
    // Check if King is in checkmate (no more valid moves)

    if (curGame.isCheckMate())
    {
        // GAME HAS FINISHED - COULD PRINT SOMETHING
        return;
    }

    // Check if King is in check
    
    if (curGame.isWhitesTurn())
    {
        int rowKing = blackKing->getRow();
        int colKing = blackKing->getCol();
        Coord tempCoord = std::make_pair(rowKing, colKing);

        if (isKingInCheck(tempCoord))
        {
            // Update game status
            curGame.setBlackKingInCheck(true);
            std::cout << "Black is in check" << std::endl;
        }
    }
    
    if (!curGame.isWhitesTurn())
    {
        int rowKing = whiteKing->getRow();
        int colKing = whiteKing->getCol();
        Coord tempCoord = std::make_pair(rowKing, colKing);

        if (isKingInCheck(tempCoord))
        {
            // Update game status
            curGame.setWhiteKingInCheck(true);
            
            std::cout << "White is in check" << std::endl;
        }
    }

    // Switch player in turn
    curGame.switchPlayer();
}

bool
ChessBoard::pieceCanBePlayed(int row, int col)
{
    // Check if no piece found at origin

    if (board[row][col] == nullptr)
    {
        std::cout << "There is no piece at position " << getPos(row, col) << "!" << std::endl;
        return false;
    }


    // Check if wrong player is trying to play

    if (!board[row][col]->isWhite() && curGame.isWhitesTurn())
    {
        // Black trying to play in white's turn

        std::cout << "It is not Black's turn to move!" << std::endl;
        return false;
    }

    if (board[row][col]->isWhite() && !curGame.isWhitesTurn())
    {
        // White trying to play in black's turn

        std::cout << "It is not White's turn to move!" << std::endl;
        return false;
    }
    
    return true;
}

const Game&
ChessBoard::getGame() const
{
    return curGame;
}

const ChessBoard::BoardArray&
ChessBoard::getBoard() const
{
    return board;
}


void
ChessBoard::getOpponentsCoords(SetOfCoords& opponentsCoords)
{
    for (int i=INDEX_MIN; i<=INDEX_MAX; i++)
    {
        for (int j=INDEX_MIN; j<=INDEX_MAX; j++)
        {
            if (board[i][j]!=nullptr && (board[i][j]->isWhite() != curGame.isWhitesTurn()))
            {
                Coord tempCoord = std::make_pair(i, j);
                opponentsCoords.insert(tempCoord);
            }
        }
    }
}

void
ChessBoard::getDangerousCoords(SetOfCoords& dangerousCoords)
{   
    int rowKing;
    int colKing;
    SetOfCoords opponentsCoords;
    getOpponentsCoords(opponentsCoords);

    /*
    std::cout << "opponentsCoords" << std::endl;
    for (auto it = opponentsCoords.begin(); it != opponentsCoords.end(); ++it)
    {
        if (!board[(*it).first][(*it).second]->isKing())
        {
            std::cout << (*it).first << " " << (*it).second << std::endl;
        }
    }
    */

    // Add all possible coord the opponent's non-king pieces could reach
    for (auto it = opponentsCoords.begin(); it != opponentsCoords.end(); ++it)
    {
        if (!board[(*it).first][(*it).second]->isKing())
        {
            board[(*it).first][(*it).second]->findPossibleMoves(dangerousCoords);
        }

        // King found
        rowKing = (*it).first;
        colKing = (*it).second;
    }

    // Add all neighbouring coordinates of the opponent's king
    Coord tempCoord;

    // Add north of opponent's King
    
    int row = rowKing - 1;
    int col = colKing;
    if (row >= INDEX_MIN)
    {
        tempCoord = std::make_pair(row, col);
        dangerousCoords.insert(tempCoord);
    }
    
    // Add south of opponent's King

    row = rowKing + 1;
    col = colKing;
    if (row <= INDEX_MAX)
    {
        tempCoord = std::make_pair(row, col);
        dangerousCoords.insert(tempCoord);
    }

    // Add west of opponent's King

    row = rowKing;
    col = colKing - 1;
    if (col>=INDEX_MIN)
    {
        tempCoord = std::make_pair(row, col);
        dangerousCoords.insert(tempCoord);
    }

    // Add east of opponent's King

    row = rowKing;
    col = colKing + 1;
    if (col<=INDEX_MAX)
    {
        tempCoord = std::make_pair(row, col);
        dangerousCoords.insert(tempCoord);
    }

    // Add north west of opponent's King

    row = rowKing - 1;
    col = colKing - 1;
    if (row >= INDEX_MIN && col >= INDEX_MIN)
    {
        tempCoord = std::make_pair(row, col);
        dangerousCoords.insert(tempCoord);
    }

    // Add north east of opponent's King

    row = rowKing - 1;
    col = colKing + 1;
    if (row >= INDEX_MIN && col <= INDEX_MAX)
    {
        tempCoord = std::make_pair(row, col);
        dangerousCoords.insert(tempCoord);
    }
    
    // Add south west of opponent's King

    row = rowKing + 1;
    col = colKing - 1;
    if (row<=INDEX_MAX && col>=INDEX_MIN)
    {
        tempCoord = std::make_pair(row, col);
        dangerousCoords.insert(tempCoord);
    }

    // Add south east of opponent's King

    row = rowKing + 1;
    col = colKing + 1;
    if (row<=INDEX_MAX && col<=INDEX_MAX)
    {
        tempCoord = std::make_pair(row, col);
        dangerousCoords.insert(tempCoord);
    }
}

bool
ChessBoard::isKingInCheck(Coord& trialCoord)
{
    SetOfCoords dangerousCoords;
    getDangerousCoords(dangerousCoords);
    
    /*
    std::cout << "dangerousCoords" << std::endl;
    for (auto it = dangerousCoords.begin(); it != dangerousCoords.end(); ++it)
    {
        std::cout << (*it).first << " " << (*it).second << std::endl;
    }
    */

    if (dangerousCoords.find(trialCoord)==dangerousCoords.end())
    {
        return false;
    }
    return true;
}

ChessBoard::~ChessBoard()
{
    clearBoard();
}