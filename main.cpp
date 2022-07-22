#include "game.h"

game g = game("p1", "p2");
string current_player;
char piece;

void run();
int get_col();
int get_row();

int main() {
    system("CLS");
    run();
    return 0;
}

void run() {
    while (!g.is_win()) {
        if (g.turn == 0) {
            piece = 'X';
            current_player = "p1";
        } else {
            piece = 'O';
            current_player = "p2";
        }

        int col = get_col();
        int row = get_row();

        while (!g.set_board(col, row, piece)) {
            cout << "placement already occupied please try again" << endl;
            col = get_col();
            row = get_row();
        }

        system("CLS");

        g.print_board();

        if (g.turn == 0) {
            g.turn = 1;
        } else {
            g.turn = 0;
        }

        if (g.is_draw()) {
            cout << "game is a draw" << endl;
            exit(0);
        }
    }
    cout << current_player + " wins!" << endl;
}

int get_col() {
    int col;
    cout << current_player + ", please enter your column placement:" << endl;
    cin >> col;

    return col;
}

int get_row() {
    int row;
    cout << current_player + ", please enter your row placement:" << endl;
    cin >> row;

    return row;
}