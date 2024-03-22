cmake_minimum_required(VERSION 3.10)
project(Chess VERSION 1.0)
add_executable(Chess Main.cpp)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Skopiuj plik tekstowy do katalogu wyjściowego (build)

file(COPY chessBoard.txt DESTINATION ${CMAKE_BINARY_DIR})
file(COPY instruction.txt DESTINATION ${CMAKE_BINARY_DIR})
file(COPY introduction.txt DESTINATION ${CMAKE_BINARY_DIR})


add_library(Background Background.cpp Background.h)
add_library(BishopPiece BishopPiece.cpp BishopPiece.h)
#add_library(Black Black.cpp Black.h)
add_library(CheckValidation CheckValidation.cpp CheckValidation.h)
add_library(functions functions.cpp functions.h)
add_library(KingPiece KingPiece.cpp KingPiece.h)
add_library(KnightPiece KnightPiece.cpp KnightPiece.h)
add_library(PawnPiece PawnPiece.cpp PawnPiece.h)
add_library(Piece Piece.cpp Piece.h)
add_library(Player Player.cpp Player.h)
add_library(QueenPiece QueenPiece.cpp QueenPiece.h)
add_library(RookPiece RookPiece.cpp RookPiece.h)
#add_library(White White.cpp White.h)

target_link_libraries(Chess PUBLIC Background BishopPiece CheckValidation functions
KingPiece KnightPiece PawnPiece Piece Player QueenPiece RookPiece)