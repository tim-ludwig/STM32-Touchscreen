#include <tictactoe/TicTacToe.h>
#include <cmath>
#include <limits>

Move::Move(int _row, int _col) : col(_col), row(_row) {}
Move::Move(const char str[3]) : Move(str[1] - '0', str[0] - 'a') {}

std::istream& operator>>(std::istream& stream, Move& move) {
    char in[3];
    std::cin >> in;
    move = Move(in);

    return stream;
}

std::ostream& operator<<(std::ostream& stream, const Move m) {
    if(m.col < 0 || m.row < 0) return stream << "invalid";

    return stream << (char) ('a' + m.col) << (char) ('0' + m.row);
}

bool Move::isValid() const {
    return 0 <= row && row < 3 && 0 <= col && col < 3;
}

Game::Game() {
    for(int row = 0; row < 3; ++row) {
        for(int col = 0; col < 3; ++col) {
            board[row][col] = ' ';
        }
    }
}

char Game::at(int row, int col) {
	return board[row][col];
}

char Game::getCurrentPlayer() const {
    return currentPlayer;
}

bool Game::doMove(Move move) {
    if(board[move.row][move.col] != ' ' || !move.isValid()) return false;

    moveStack.push_back(move);

    board[move.row][move.col] = currentPlayer;
    currentPlayer = currentPlayer == 'x' ? 'o' : 'x';

    return true;
}

bool Game::undoMove() {
    if(moveStack.empty()) return false;

    Move move = moveStack.back();
    moveStack.pop_back();

    board[move.row][move.col] = ' ';
    currentPlayer = currentPlayer == 'x' ? 'o' : 'x';

    return true;
}

bool Game::hasEnded() const {
    return winner() != '\0';
}

char Game::winner() const {
    // verticals
    for(int col = 0; col < 3; ++col) {
        if(board[0][col] != ' ' && board[0][col] == board[1][col] && board[1][col] == board[2][col]) return board[0][col];
    }

    // horizontals
    for(int row = 0; row < 3; ++row) {
        if(board[row][0] != ' ' && board[row][0] == board[row][1] && board[row][1] == board[row][2]) return board[row][0];
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

    for(int row = 0; row < 3; ++row) {
       	for(int col = 0; col < 3; ++col) {
            Move m(row, col);
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

        for(int row = 0; row < 3; ++row) {
            for(int col = 0; col < 3; ++col) {
                    Move m(row, col);
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
    for(int row = 0; row < 3; ++row) {
        stream << "--+---+---+---+\n";
        stream << (char) ('0' + row) << ' ';

        for(int col = 0; col < 3; ++col) {
            stream << "| ";
            stream << game.board[row][col];
            stream << " ";
        }
        stream << "|\n";
    }
    stream << "--+---+---+---+\n";

    return stream;
}

void Game::uartPrint(cDevTextIO_UART& com) const {
	com.printf("  | a | b | c |\r\n");

	for(int row = 0; row < 3; ++row) {
		com.printf("--+---+---+---+\r\n");
		com.printf("%c ", '0' + row);

		for(int col = 0; col < 3; ++col) {
			com.printf("| %c ", board[row][col]);
		}
		com.printf("|\r\n");
	}
	com.printf("--+---+---+---+\r\n");
}
