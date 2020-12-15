#include "ChessBoard.h"
#include "Helper.h"

#include "Bishop.h"
#include "King.h"
#include "Knight.h"
#include "Pawn.h"
#include "Queen.h"
#include "Rook.h"

#include <iostream>

using std::cout;
using std::endl;

int main() {

    /*
    // Test chess pieces initialisation

    std::cout << std::endl;
    Bishop bishopWhite(true, 0, 0);
    std::cout << "name = " << bishopWhite.getName() << std::endl;
    std::cout << "symbol = " << bishopWhite.getSymbol() << std::endl;
    std::cout << "curRow = " << bishopWhite.getRow() << std::endl;
    std::cout << "curCol = " << bishopWhite.getCol() << std::endl;
    std::cout << std::endl;
    King kingWhite(true, 0, 0);
    std::cout << "name = " << kingWhite.getName() << std::endl;
    std::cout << "symbol = "<< kingWhite.getSymbol() << std::endl;
    std::cout << std::endl;
    Knight knightWhite(true, 0, 0);
    std::cout << "name = " << knightWhite.getName() << std::endl;
    std::cout << "symbol = "<< knightWhite.getSymbol() << std::endl;
    std::cout << std::endl;
    Pawn pawnWhite(true, 0, 0);
    std::cout << "name = " << pawnWhite.getName() << std::endl;
    std::cout << "symbol = "<< pawnWhite.getSymbol() << std::endl;
    std::cout << std::endl;
    Queen queenWhite(true, 0, 0);
    std::cout << "name = " << queenWhite.getName() << std::endl;
    std::cout << "symbol = "<< queenWhite.getSymbol() << std::endl;
    std::cout << std::endl;
    Rook rookWhite(true, 0, 0);
    std::cout << "name = " << rookWhite.getName() << std::endl;
    std::cout << "symbol = "<< rookWhite.getSymbol() << std::endl;
    std::cout << std::endl;

    std::cout << std::endl;
    Bishop bishopBlack(false, 0, 0);
    std::cout << "name = " << bishopBlack.getName() << std::endl;
    std::cout << "symbol = " << bishopBlack.getSymbol() << std::endl;
    std::cout << std::endl;
    King kingBlack(false, 0, 0);
    std::cout << "name = " << kingBlack.getName() << std::endl;
    std::cout << "symbol = "<< kingBlack.getSymbol() << std::endl;
    std::cout << std::endl;
    Knight knightBlack(false, 0, 0);
    std::cout << "name = " << knightBlack.getName() << std::endl;
    std::cout << "symbol = "<< knightBlack.getSymbol() << std::endl;
    std::cout << std::endl;
    Pawn pawnBlack(false, 0, 0);
    std::cout << "name = " << pawnBlack.getName() << std::endl;
    std::cout << "symbol = "<< pawnBlack.getSymbol() << std::endl;
    std::cout << std::endl;
    Queen queenBlack(false, 0, 0);
    std::cout << "name = " << queenBlack.getName() << std::endl;
    std::cout << "symbol = "<< queenBlack.getSymbol() << std::endl;
    std::cout << std::endl;
    Rook rookBlack(false, 0, 0);
    std::cout << "name = " << rookBlack.getName() << std::endl;
    std::cout << "symbol = "<< rookBlack.getSymbol() << std::endl;
    std::cout << std::endl;
    */
    /*

    // Test chessboard initialisation

    ChessBoard cb;
    cb.printBoard();

    
    // Test getPos()
    int i = 1;
    int j = 3;
    cout << "getPos(i, j) = " << getPos(i, j) << endl;

    // Test isValidPos()
    std::string pos = "D7";
    cout << "isValidPos(pos) = " << isValidPos(pos) << endl;

    // Test getRow()
    cout << "getRow(pos) = " << getRow(pos) << endl;

    // Test getCol()
    cout << "getCol(pos) = " << getCol(pos) << endl;
    */

    /*
    // Test Game class()
    cb.getGame().printGameStatus();

    // Test isValidMove() on Bishop
    cout << "Bishop Test 1 [5][2]" << endl;
    cb.printBoard();
    cb.getBoard()[5][2]->isValidMove(0,0);
    std::cout << std::endl;

    // Test isValidMove() on Rook
    cout << "Rook Test 1 [0][0]" << endl;
    cb.printBoard();
    cb.getBoard()[0][0]->isValidMove(7,0);
    std::cout << std::endl;

    // Test isValidMove() on Rook
    cout << "Rook Test 2 [0][7]" << endl;
    cb.printBoard();
    cb.getBoard()[0][7]->isValidMove(0,0);
    std::cout << std::endl;

    // Test isValidMove() on Rook
    cout << "Rook Test 3 [7][0]" << endl;
    cb.printBoard();
    cb.getBoard()[7][0]->isValidMove(4,1);
    std::cout << std::endl;

    // Test isValidMove() on Rook
    cout << "Rook Test 4 [5][4]" << endl;
    cb.printBoard();
    cb.getBoard()[5][4]->isValidMove(3,2);
    std::cout << std::endl;

    // Test isValidMove() on Queen
    cout << "Queen Test 1 [0][3]" << endl;
    cb.printBoard();
    cb.getBoard()[0][3]->isValidMove(1,7);
    std::cout << std::endl;

    // Test isValidMove() on Queen
    cout << "Queen Test 2 [4][4]" << endl;
    cb.printBoard();
    cb.getBoard()[4][4]->isValidMove(1,7);
    std::cout << std::endl;

    // Test isValidMove() on Knight
    cout << "Knight Test 1 [2][5]" << endl;
    cb.printBoard();
    cb.getBoard()[2][5]->isValidMove(1,7);
    std::cout << std::endl;

    // Test isValidMove() on Knight
    cout << "Knight Test 2 [0][1]" << endl;
    cb.printBoard();
    cb.getBoard()[0][1]->isValidMove(5,7);
    std::cout << std::endl;

    // Test isValidMove() on King
    cout << "King Test 1 [0][4]" << endl;
    cb.printBoard();
    cb.getBoard()[0][4]->isValidMove(1,2);
    std::cout << std::endl;

    // Test isValidMove() on King
    cout << "King Test 1 [2][4]" << endl;
    cb.printBoard();
    cb.getBoard()[2][4]->isValidMove(1,4);
    std::cout << std::endl;
    */

    /*
    // test pieceCanBePlayed()
    cout << "pieceCanBePlayed(black) = "
    << cb.pieceCanBePlayed(0, 1) << endl;
    cout << "pieceCanBePlayed(nullptr) = "
    << cb.pieceCanBePlayed(4, 1) << endl;
    cout << "pieceCanBePlayed(white) = "
    << cb.pieceCanBePlayed(7, 1) << endl;
    */

    // Test isValidMove()

    
	cout << "========================\n";
	cout << "Testing the Chess Engine\n";
	cout << "========================\n\n";

	ChessBoard cb;
    cb.printBoard();
	cout << '\n';

	cb.submitMove("D7", "D6");
    cb.printBoard();
	cout << '\n';

	cb.submitMove("D4", "H6");
    cb.printBoard();
	cout << '\n';

	cb.submitMove("D2", "D4");
    cb.printBoard();
	cout << '\n';

	cb.submitMove("F8", "B4");
    cb.printBoard();
	cout << '\n';

	cout << "=========================\n";
	cout << "Alekhine vs. Vasic (1931)\n";
	cout << "=========================\n\n";

	cb.resetBoard();
    cb.printBoard();
	cout << '\n';

	cb.submitMove("E2", "E4");
    cb.printBoard();
	cb.submitMove("E7", "E6");
    cb.printBoard();
	cout << '\n';

	cb.submitMove("D2", "D4");
    cb.printBoard();
	cb.submitMove("D7", "D5");
    cb.printBoard();
	cout << '\n';

	cb.submitMove("B1", "C3");
    cb.printBoard();
	cb.submitMove("F8", "B4");
    cb.printBoard();
	cout << '\n';

	cb.submitMove("F1", "D3");
    cb.printBoard();
	cb.submitMove("B4", "C3");
    cb.printBoard();
	cout << '\n';

	cb.submitMove("B2", "C3");
    cb.printBoard();
	cb.submitMove("H7", "H6");
    cb.printBoard();
	cout << '\n';

	cb.submitMove("C1", "A3");
    cb.printBoard();
	cb.submitMove("B8", "D7");
    cb.printBoard();
	cout << '\n';

	cb.submitMove("D1", "E2");
    cb.printBoard();
	cb.submitMove("D5", "E4");
    cb.printBoard();
	cout << '\n';

	cb.submitMove("D3", "E4");
    cb.printBoard();
	cb.submitMove("G8", "F6");
    cb.printBoard();
	cout << '\n';

	cb.submitMove("E4", "D3");
    cb.printBoard();
	cb.submitMove("B7", "B6");
    cb.printBoard();
	cout << '\n';

	cb.submitMove("E2", "E6");
    cb.printBoard();
	cb.submitMove("F7", "E6");
    cb.printBoard();
	cout << '\n';

	cb.submitMove("D3", "G6");
    cb.printBoard();
	cout << '\n';
    

	return 0;
}
