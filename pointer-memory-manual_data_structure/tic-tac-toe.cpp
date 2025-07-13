// tic-tac-toe game
#include <iostream>
#include <ctime>

using namespace std;

// define interface functions
void drawBoard(char *spaces);
void playerMove(char *spaces, char player);
void computerMove(char *spaces, char computer);
bool checkWinner(char *spaces, char player, char computer);
bool checkTie(char *spaces);

int main() {
    char spaces[9] = {' ', ' ', ' ',
                      ' ', ' ', ' ',
                      ' ', ' ', ' '};
    char player = 'X';
    char computer = 'O';
    bool gameOver = false;

    cout << "Welcome to Tic-Tac-Toe!\n";
    drawBoard(spaces);

    while (!gameOver) {
        playerMove(spaces, player);
        drawBoard(spaces);

        if (checkWinner(spaces, player, computer)) {
            gameOver = true;
            break;
        }

        computerMove(spaces, computer);
        drawBoard(spaces);

        if (checkWinner(spaces, computer, player)) {
            gameOver = true;
            break;
        }

        cout << "Current spaces:\n";

        if (checkTie(spaces)) {
            gameOver = true;
            break;
        }
    }

    return 0;
}

void drawBoard(char *spaces) {
    cout << " " << spaces[0] << " | " << spaces[1] << " | " << spaces[2] << "\n";
    cout << "---|---|---\n";
    cout << " " << spaces[3] << " | " << spaces[4] << " | " << spaces[5] << "\n";
    cout << "---|---|---\n";
    cout << " " << spaces[6] << " | " << spaces[7] << " | " << spaces[8] << "\n";
    cout << "=========================\n";
}

void playerMove(char *spaces, char player) {
    int move = -1;

    do {
        cout << "Enter your move (1-9): ";
        cin >> move;
    } while (move < 1 || move > 9);

    move--; // convert to 0-indexed
    if (spaces[move] == ' ') {
        spaces[move] = player;
    } else {
        cout << "Space already taken! Try again.\n";
        playerMove(spaces, player); // ask for move again
    }
}

void computerMove(char *spaces, char computer) {
    srand(time(0)); // seed random number generator
    int move;

    do {
        move = rand() % 9; // generate random move
    } while (spaces[move] != ' '); // ensure space is empty

    spaces[move] = computer;
}

bool checkWinner(char *spaces, char player, char computer) {
    // check rows, columns, and diagonals for a win
    for (int i = 0; i < 8; i = i + 3) {
        if ((spaces[i] != ' ' && spaces[i] == spaces[i + 1] && spaces[i] == spaces[i + 2]) ||
            (spaces[i] != ' ' && spaces[i] == spaces[i + 3] && spaces[i] == spaces[i + 6]) ||
            (spaces[i] != ' ' && spaces[i] == spaces[4] && spaces[i] == spaces[8 - i])) {
            cout << "You " << (spaces[i] == player ? "win!" : "lose!") << endl;
            return true;
        }
    }

    return false;
}

bool checkTie(char *spaces) {
    for (int i = 0; i < 9; i++) {
        if (spaces[i] == ' ') {
            return false; // found an empty space, not a tie
        }
    }
    cout << "It's a tie!" << endl;
    return true; // no empty spaces, it's a tie
}
