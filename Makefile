chess: ChessMain.o Helper.o Game.o ChessBoard.o Piece.o Bishop.o King.o Knight.o Pawn.o Queen.o Rook.o
	g++ ChessMain.o Helper.o Game.o ChessBoard.o Piece.o Bishop.o King.o Knight.o Pawn.o Queen.o Rook.o -o chess

ChessMain.o: ChessMain.cpp ChessBoard.h
	g++ -Wall -g -c ChessMain.cpp

Helper.o: Helper.cpp Constants.h
	g++ -Wall -g -c Helper.cpp

Game.o: Game.cpp Game.h Constants.h
	g++ -Wall -g -c Game.cpp

ChessBoard.o: ChessBoard.cpp ChessBoard.h Game.h Helper.h Piece.h Bishop.h King.h Knight.h Pawn.h Queen.h Rook.h Constants.h 
	g++ -Wall -g -c ChessBoard.cpp

Piece.o: Piece.cpp Piece.h ChessBoard.h Constants.h
	g++ -Wall -g -c Piece.cpp

Bishop.o: Bishop.cpp Bishop.h Piece.h Constants.h
	g++ -Wall -g -c Bishop.cpp

King.o: King.cpp King.h Piece.h Constants.h
	g++ -Wall -g -c King.cpp

Knight.o: Knight.cpp Knight.h Piece.h Constants.h
	g++ -Wall -g -c Knight.cpp

Pawn.o: Pawn.cpp Pawn.h Piece.h Constants.h
	g++ -Wall -g -c Pawn.cpp 

Queen.o: Queen.cpp Queen.h Piece.h Constants.h
	g++ -Wall -g -c Queen.cpp 

Rook.o: Rook.cpp Rook.h Piece.h Constants.h
	g++ -Wall -g -c Rook.cpp
