#pragma once

#include <iostream>
#include <string.h>
#include <stdlib.h>

using namespace std;

class game {
    public:
        game(string p1, string p2);
        bool is_win();
        bool is_draw();
        bool set_board(int x, int y, char c);
        void print_board();
        int ctoi(char c);
        int turn = 0;

    private:
        string p1_name;
        string p2_name;

        char row1[3];
        char row2[3];
        char row3[3];
};

game::game(string p1, string p2) {
    this -> p1_name = p1;
    this -> p2_name = p2;
}

bool game::is_win() {
    if (ctoi(row1[0]) == ctoi(row1[1]) && ctoi(row1[1]) == ctoi(row1[2]) && ctoi(row1[2]) == ctoi('X') || ctoi(row1[0]) == ctoi(row1[1]) && ctoi(row1[1]) == ctoi(row1[2]) && ctoi(row1[2]) == ctoi('O')) return true;
    if (ctoi(row2[0]) == ctoi(row2[1]) && ctoi(row2[1]) == ctoi(row2[2]) && ctoi(row2[2]) == ctoi('X') || ctoi(row2[0]) == ctoi(row2[1]) && ctoi(row2[1]) == ctoi(row2[2]) && ctoi(row2[2]) == ctoi('O')) return true;
    if (ctoi(row3[0]) == ctoi(row3[1]) && ctoi(row3[1]) == ctoi(row3[2]) && ctoi(row3[2]) == ctoi('X') || ctoi(row3[0]) == ctoi(row3[1]) && ctoi(row3[1]) == ctoi(row3[2]) && ctoi(row3[2]) == ctoi('O')) return true;
    if (ctoi(row1[0]) == ctoi(row2[0]) && ctoi(row2[0]) == ctoi(row3[0]) && ctoi(row3[0]) == ctoi('X') || ctoi(row1[0]) == ctoi(row2[0]) && ctoi(row2[0]) == ctoi(row3[0]) && ctoi(row3[0]) == ctoi('O')) return true;
    if (ctoi(row1[1]) == ctoi(row2[1]) && ctoi(row2[1]) == ctoi(row3[1]) && ctoi(row3[1]) == ctoi('X') || ctoi(row1[1]) == ctoi(row2[1]) && ctoi(row2[1]) == ctoi(row3[1]) && ctoi(row3[1]) == ctoi('O')) return true;
    if (ctoi(row1[2]) == ctoi(row2[2]) && ctoi(row2[2]) == ctoi(row3[2]) && ctoi(row3[2]) == ctoi('X') || ctoi(row1[2]) == ctoi(row2[2]) && ctoi(row2[2]) == ctoi(row3[2]) && ctoi(row3[2]) == ctoi('O')) return true;
    if (ctoi(row1[0]) == ctoi(row2[1]) && ctoi(row2[1]) == ctoi(row3[2]) && ctoi(row3[2]) == ctoi('X') || ctoi(row1[0]) == ctoi(row2[1]) && ctoi(row2[1]) == ctoi(row3[2]) && ctoi(row3[2]) == ctoi('O')) return true;
    if (ctoi(row1[2]) == ctoi(row2[1]) && ctoi(row2[1]) == ctoi(row3[0]) && ctoi(row3[0]) == ctoi('X') || ctoi(row1[2]) == ctoi(row2[1]) && ctoi(row2[1]) == ctoi(row3[0]) && ctoi(row3[0]) == ctoi('O')) return true;
    return false;
}

bool game::is_draw() {
    for (int i = 0; i < 3; i++) {
        if (row1[i] == '\0') return false;
    }
    for (int i = 0; i < 3; i++) {
        if (row2[i] == '\0') return false;
    }
    for (int i = 0; i < 3; i++) {
        if (row3[i] == '\0') return false;
    }
    return false;
}

bool game::set_board(int x, int y, char c) {
    switch (x) {
        case 1:
            if (row1[y - 1] == '\0') row1[y - 1] = c;
            else return false;

            break;
        case 2:
            if (row2[y - 1] == '\0') row2[y - 1] = c;
            else return false;

            break;
        case 3:
            if (row3[y - 1] == '\0') row3[y - 1] = c;
            else return false;

            break;
    }

    return true;
}

void game::print_board() {
    cout << "+---+---+---+" << endl;
    cout << "| ";
    for (int i = 0; i < 3; i++) {
        if (row1[i] == '\0') cout << " " << " | ";
        else cout << (row1[i]) << " | ";
    }
    
    cout << endl;
    cout << "+---+---+---+" << endl;
    cout << "| ";

    for (int i = 0; i < 3; i++) {
        if (row2[i] == '\0') cout << " " << " | ";
        else cout << (row2[i]) << " | ";
    }
    cout << endl;
    cout << "+---+---+---+" << endl;
    cout << "| ";

    for (int i = 0; i < 3; i++) {
        if (row3[i] == '\0') cout << " " << " | ";
        else cout << (row3[i]) << " | ";
    }
    cout << endl;
    cout << "+---+---+---+" << endl;
}

int game::ctoi(char c) {
    return int(c);
}