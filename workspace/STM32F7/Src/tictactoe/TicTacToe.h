#ifndef TICTACTOE_GAME_H
#define TICTACTOE_GAME_H

#include <iostream>
#include <vector>

#include "lib.h"

class Move {
public:
    int row;
    int col;

    explicit Move(const char str[2]);
    Move(int row, int col);

    friend std::istream& operator>>(std::istream&, Move&);
    friend std::ostream& operator<<(std::ostream&, const Move);

    bool isValid() const;
};

class TicTacToeGame {
    char board[3][3] = {};
    char currentPlayer = 'x';
    std::vector<Move> moveStack = {};

    friend std::ostream& operator<<(std::ostream&, const TicTacToeGame&);

public:
    TicTacToeGame();

    char at(int row, int col);

    char getCurrentPlayer() const;
    bool doMove(Move);
    bool undoMove();
    bool hasEnded() const;
    char winner() const;

    void uartPrint(cDevTextIO_UART&) const;

    double eval();
    Move bestMove();
};

#endif //TICTACTOE_GAME_H
