#include "Game.h"
#include <cmath>
#include <limits>

Move::Move(int _x, int _y) : x(_x), y(_y) {}
Move::Move(const char str[3]) : Move(str[0] - 'a', str[1] - '0') {}

std::istream& operator>>(std::istream& stream, Move& move) {
    char in[3];
    std::cin >> in;
    move = Move(in);

    return stream;
}

std::ostream& operator<<(std::ostream& stream, const Move m) {
    if(m.x < 0 || m.y < 0) return stream << "invalid";

    return stream << (char) ('a' + m.x) << (char) ('0' + m.y);
}

bool Move::isValid() const {
    return 0 <= x && x < 3 && 0 <= y && y < 3;
}

Game::Game() {
    for(int x = 0; x < 3; ++x) {
        for(int y = 0; y < 3; ++y) {
            board[x][y] = ' ';
        }
    }
}

char Game::getCurrentPlayer() const {
    return currentPlayer;
}

bool Game::doMove(Move move) {
    if(board[move.x][move.y] != ' ' || !move.isValid()) return false;

    moveStack.push_back(move);

    board[move.x][move.y] = currentPlayer;
    currentPlayer = currentPlayer == 'x' ? 'o' : 'x';

    return true;
}

bool Game::undoMove() {
    if(moveStack.empty()) return false;

    Move move = moveStack.back();
    moveStack.pop_back();

    board[move.x][move.y] = ' ';
    currentPlayer = currentPlayer == 'x' ? 'o' : 'x';

    return true;
}

bool Game::hasEnded() const {
    return winner() != '\0';
}

char Game::winner() const {
    // verticals
    for(int x = 0; x < 3; ++x) {
        if(board[x][0] != ' ' && board[x][0] == board[x][1] && board[x][1] == board[x][2]) return board[x][0];
    }

    // horizontals
    for(int y = 0; y < 3; ++y) {
        if(board[0][y] != ' ' && board[0][y] == board[1][y] && board[1][y] == board[2][y]) return board[0][y];
    }

    // Diagonals
    if(board[0][0] != ' ' && board[0][0] == board[1][1] && board[1][1] == board[2][2]) return board[0][0];
    if(board[0][2] != ' ' && board[0][2] == board[1][1] && board[1][1] == board[2][0]) return board[0][2];

    // no winner, no possible moves. Draw.
    if(moveStack.size() >= 9) return ' ';

    // game is ongoing
    return '\0';
}

Move Game::bestMove() {
    Move best(-1, -1);
    double val = std::numeric_limits<double>::infinity();
    if(currentPlayer == 'x') val = -val;

    for(int x = 0; x < 3; ++x) {
        for(int y = 0; y < 3; ++y) {
            Move m(x, y);
            if(!doMove(m)) continue;

            double current = eval();
            if(currentPlayer != 'x') { // x made the last move
                if (val < current) {
                    val = current;
                    best = m;
                }
            } else {
                if(val > current) {
                    val = current;
                    best = m;
                }
            }

            undoMove();
        }
    }

    return best;
}

double Game::eval() {
    switch (winner()) {
        case 'x':
            return std::numeric_limits<double>::infinity();
        case 'o':
            return -std::numeric_limits<double>::infinity();
        case ' ':
            return 0;
        case '\0':
            double val = std::numeric_limits<double>::infinity();
            if(currentPlayer == 'x') val = -val;

            for(int x = 0; x < 3; ++x) {
                for(int y = 0; y < 3; ++y) {
                    Move m(x, y);
                    if(!doMove(m)) continue;

                    if(currentPlayer != 'x') val = std::max<double>(val, eval()); // x made the last move
                    else val = std::min<double>(val, eval());

                    undoMove();
                }
            }

            return val;
    }

    return NAN;
}

std::ostream& operator<<(std::ostream& stream, const Game& game) {
    stream << "  | a | b | c |\n";
    for(int y = 0; y < 3; ++y) {
        stream << "--+---+---+---+\n";
        stream << (char) ('0' + y) << ' ';

        for(int x = 0; x < 3; ++x) {
            stream << "| ";
            stream << game.board[x][y];
            stream << " ";
        }
        stream << "|\n";
    }
    stream << "--+---+---+---+\n";

    return stream;
}
