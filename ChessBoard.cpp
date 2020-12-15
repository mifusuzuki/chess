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

bool
ChessBoard::isPermittedMove(int rowOrigin, int colOrigin,
                            int rowDest, int colDest)
{
    for (long unsigned int move=0; move<permittedMoves.size(); move++)
    {
        if (permittedMoves[move][0]==rowOrigin
            && permittedMoves[move][1]==colOrigin
            && permittedMoves[move][2]==rowDest
            && permittedMoves[move][3]==colDest)
        {
            // Matching move found in pemittedMoves
            return true;
        }
    }

    // No match found in pemittedMoves
    return false;
}

bool
ChessBoard::isValidMove(int rowOrigin, int colOrigin,
                        int rowDest, int colDest)
{
    /****************** Case where king is in check *******************/

    if (curGame.isWhitesTurn() && whiteKing->isInCheck())
    {
        if (isPermittedMove(rowOrigin, colOrigin, rowDest, colDest))
        {
            // This is a valid move that unchecks the King
            permittedMoves.clear();
            whiteKing->setInCheck(false);
            return true;
        }
        else 
        {
            // This move does not uncheck the King
            return false;
        }
    }

    if (!curGame.isWhitesTurn() && blackKing->isInCheck())
    {
        if (isPermittedMove(rowOrigin, colOrigin, rowDest, colDest))
        {
            // This is a valid move that unchecks the King
            permittedMoves.clear();
            blackKing->setInCheck(false);
            return true;
        }
        else
        {
            // This move does not uncheck the King
            return false;
        }
    }

    
    /***************** Case where king is not in check *****************/

    // Get all possible moves the piece at origin can make

    SetOfCoords possibleMoves;
    board[rowOrigin][colOrigin]->getAllPossibleMoves(possibleMoves);

    // Check if the destination given matches any of the possible moves

    Coord destination(rowDest, colDest);
    for (auto it = possibleMoves.begin(); it != possibleMoves.end(); ++it)
    {
        if (*it == destination)
        {
            // Match found
            return true;
        }
    }

    // Match not found
    return false;
}

void
ChessBoard::pieceRelocate(int rowOrigin, int colOrigin, int rowDest,
                            int colDest)
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

        // Destroy heap allocated piece that was captured

        delete board[rowDest][colDest];       
    }

    std::cout << std::endl;

    // Relocate piece

    board[rowDest][colDest] = board[rowOrigin][colOrigin];
    board[rowOrigin][colOrigin] = nullptr;
    
    // Update the relocated piece's object info

    board[rowDest][colDest]->setRow(rowDest);
    board[rowDest][colDest]->setCol(colDest);
    
    return;
}

void
ChessBoard::submitMove(std::string origin, std::string destination)
{
    // Initial checks before submiting move

    if (curGame.isCheckMate() || curGame.isStaleMate())
    {
        std::cerr << "[Error] Game is finished already!" << std::endl;
        return;
    }

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

    if (!canPieceBePlayed(rowOrigin, colOrigin))
    {
        return;
    }

    // Check if move is valid

    if (!isValidMove(rowOrigin, colOrigin, rowDest, colDest))
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
    pieceRelocate(rowOrigin, colOrigin, rowDest, colDest);

    // Switch player in turn
    curGame.switchPlayer();

    // Check if the current player's King is in check
    
    if (isKingInCheck())
    {
        if (canKingBeUnchecked()) // King can be unchecked
        {
            // Print Narration
        
            if(curGame.isWhitesTurn())
            {
                std::cout << "White is in check" << std::endl;
                whiteKing->setInCheck(true);
            }
            else
            {
                std::cout << "Black is in check" << std::endl;
                blackKing->setInCheck(true);
            }
        }
        else // King cannot be unchecked
        {
            // Print Narration
        
            if(curGame.isWhitesTurn())
            {
                std::cout << "White is in checkmate" << std::endl;
                curGame.setCheckMate();
                return;
            }
            else
            {
                std::cout << "Black is in checkmate" << std::endl;
                curGame.setCheckMate();
                return;
            }
        }
    }

    // Check if the current player is in stalemate

    if (!canCurPlayerMove())
    {
        if(curGame.isWhitesTurn())
        {
            std::cout << "White is in stalemate" << std::endl;
            curGame.setStaleMate();
            return;
        }
        else
        {
            std::cout << "Black is in stalemate" << std::endl;
            curGame.setStaleMate();
            return;
        }
    }
}

bool
ChessBoard::canCurPlayerMove()
{
    // Get current player's pieces
    SetOfCoords curPlayersCoords;
    getCurPlayersCoords(curPlayersCoords);

    // Continuously add the possible moves to the set

    SetOfCoords possibleMoves;
    for (auto i = curPlayersCoords.begin(); i != curPlayersCoords.end(); ++i)
    {
        int row = (*i).first;
        int col = (*i).second;
        board[row][col]->getAllPossibleMoves(possibleMoves);
    }

    // Check there is at least 1 possible move in set

    if (possibleMoves.size() <= 0)
    {
        return false;
    }
    return true;
}

void
ChessBoard::simulateMove(int rowOrigin, int colOrigin, int rowDest, int colDest)
{
    // Save the chess piece at destination if there are any
    Piece* savedPiece = board[rowDest][colDest];

    // Relocate piece

    board[rowDest][colDest] = board[rowOrigin][colOrigin];
    board[rowOrigin][colOrigin] = nullptr;

    // Check if this would uncheck King

    if (!isKingInCheck())
    {
        // Add this move to permmitedMoves container
        std::array<int, 4> move = {rowOrigin, colOrigin, rowDest, colDest};
        permittedMoves.push_back(move);
    }

    // Revert the board

    board[rowOrigin][colOrigin] = board[rowDest][colDest];
    if (savedPiece == nullptr)
    {
        board[rowDest][colDest] = nullptr;
    }
    else
    {
        // Put back the captured object
        board[rowDest][colDest] = savedPiece;
    }
}

bool
ChessBoard::canKingBeUnchecked()
{
    SetOfCoords curPlayersCoords;
    SetOfCoords coordsToUncheckKing;

    // Get current player's pieces
    getCurPlayersCoords(curPlayersCoords);

    // Find each piece's possible moves and add them to trialCoords set

    for (auto i = curPlayersCoords.begin(); i != curPlayersCoords.end(); ++i)
    {
        SetOfCoords possibleMoves;

        int rowOrigin = (*i).first;
        int colOrigin = (*i).second;
        board[rowOrigin][colOrigin]->getAllPossibleMoves(possibleMoves);
        
        for (auto j = possibleMoves.begin(); j != possibleMoves.end(); ++j)
        {
            int rowDest = (*j).first;
            int colDest = (*j).second;
            
            // Check what would happen if piece was to be moved
            // If it can uncheck King, add coord to permittedMoves container
            simulateMove(rowOrigin, colOrigin, rowDest, colDest);
        }
    }
    
    // Check if there are any permmited moves for the next round

    if (permittedMoves.size() == 0)
    {
        // King cannot be unchecked
        return false;
    }

    // King can be unchecked
    return true;
}

bool
ChessBoard::canPieceBePlayed(int row, int col)
{
    // Check if no piece found at origin

    if (board[row][col] == nullptr)
    {
        std::cout << "There is no piece at position " << getPos(row, col) << "!"
                    << std::endl;
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
            if (board[i][j]!=nullptr
                && (board[i][j]->isWhite() != curGame.isWhitesTurn()))
            {
                // Found opponent's piece
                Coord tempCoord = std::make_pair(i, j);
                opponentsCoords.insert(tempCoord);
            }
        }
    }
}

void
ChessBoard::getCurPlayersCoords(SetOfCoords& currentPlayersCoords)
{
    for (int i=INDEX_MIN; i<=INDEX_MAX; i++)
    {
        for (int j=INDEX_MIN; j<=INDEX_MAX; j++)
        {
            if (board[i][j]!=nullptr
                && (board[i][j]->isWhite() == curGame.isWhitesTurn()))
            {
                // Found current player's piece
                Coord tempCoord = std::make_pair(i, j);
                currentPlayersCoords.insert(tempCoord);
            }
        }
    }
}

void
ChessBoard::getAllCoordsOpponentCanReach(SetOfCoords& reachedCoords)
{   
    int rowKing;
    int colKing;
    SetOfCoords opponentsCoords;
    getOpponentsCoords(opponentsCoords);

    // Add all possible coord the opponent's non-king pieces could reach

    for (auto it = opponentsCoords.begin(); it != opponentsCoords.end(); ++it)
    {
        if (!board[(*it).first][(*it).second]->isKing())
        {
            board[(*it).first][(*it).second]->
            getAllPossibleMoves(reachedCoords);
        }

        // King found
        rowKing = (*it).first;
        colKing = (*it).second;
    }

    // Add all neighbouring coordinates of the opponent's king

    // Add north of opponent's King
    
    Coord tempCoord;
    int row = rowKing - 1;
    int col = colKing;
    if (row >= INDEX_MIN)
    {
        tempCoord = std::make_pair(row, col);
        reachedCoords.insert(tempCoord);
    }
    
    // Add south of opponent's King

    row = rowKing + 1;
    col = colKing;
    if (row <= INDEX_MAX)
    {
        tempCoord = std::make_pair(row, col);
        reachedCoords.insert(tempCoord);
    }

    // Add west of opponent's King

    row = rowKing;
    col = colKing - 1;
    if (col>=INDEX_MIN)
    {
        tempCoord = std::make_pair(row, col);
        reachedCoords.insert(tempCoord);
    }

    // Add east of opponent's King

    row = rowKing;
    col = colKing + 1;
    if (col<=INDEX_MAX)
    {
        tempCoord = std::make_pair(row, col);
        reachedCoords.insert(tempCoord);
    }

    // Add north west of opponent's King

    row = rowKing - 1;
    col = colKing - 1;
    if (row >= INDEX_MIN && col >= INDEX_MIN)
    {
        tempCoord = std::make_pair(row, col);
        reachedCoords.insert(tempCoord);
    }

    // Add north east of opponent's King

    row = rowKing - 1;
    col = colKing + 1;
    if (row >= INDEX_MIN && col <= INDEX_MAX)
    {
        tempCoord = std::make_pair(row, col);
        reachedCoords.insert(tempCoord);
    }
    
    // Add south west of opponent's King

    row = rowKing + 1;
    col = colKing - 1;
    if (row<=INDEX_MAX && col>=INDEX_MIN)
    {
        tempCoord = std::make_pair(row, col);
        reachedCoords.insert(tempCoord);
    }

    // Add south east of opponent's King

    row = rowKing + 1;
    col = colKing + 1;
    if (row<=INDEX_MAX && col<=INDEX_MAX)
    {
        tempCoord = std::make_pair(row, col);
        reachedCoords.insert(tempCoord);
    }
}

bool
ChessBoard::isKingInCheck(Coord* coord)
{
    int rowKing;
    int colKing;
    Coord kingCoord;

    // Get all coordinates the opponent can reach
    SetOfCoords dangerousCoords;
    getAllCoordsOpponentCanReach(dangerousCoords);
    
    // Check if current King (white) is in check (post-move)
    if (coord == nullptr && curGame.isWhitesTurn())
    {
        rowKing = whiteKing->getRow();
        colKing = whiteKing->getCol();
        kingCoord = std::make_pair(rowKing, colKing);
    }
    // Check if current King (black) is in check (post-move)
    else if (coord == nullptr && !curGame.isWhitesTurn())
    {
        rowKing = blackKing->getRow();
        colKing = blackKing->getCol();
        kingCoord = std::make_pair(rowKing, colKing);
    }
    // Check if given coord would put current king in check (pre-move)
    // This particular bit is called in King.cpp to ensure the King is not
    // walking into check
    else
    {
        kingCoord = *coord;
    }

    // Check if King's coordinate macthes any of the dangerous coords
    if (dangerousCoords.find(kingCoord)==dangerousCoords.end())
    {
        return false;
    }
    return true;
}

ChessBoard::~ChessBoard()
{
    clearBoard();
}