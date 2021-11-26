#ifndef TICTACTOE_GAME_H
#define TICTACTOE_GAME_H

#include <iostream>
#include <vector>

class Move {
public:
    int x;
    int y;

    explicit Move(const char str[2]);
    Move(int x, int y);

    friend std::istream& operator>>(std::istream&, Move&);
    friend std::ostream& operator<<(std::ostream&, const Move);

    bool isValid() const;
};

class Game {
    char board[3][3] = {};
    char currentPlayer = 'x';
    std::vector<Move> moveStack = {};

    friend std::ostream& operator<<(std::ostream&, const Game&);

public:
    Game();

    char getCurrentPlayer() const;
    bool doMove(Move);
    bool undoMove();
    bool hasEnded() const;
    char winner() const;

    double eval();
    Move bestMove();
};

#endif //TICTACTOE_GAME_H
