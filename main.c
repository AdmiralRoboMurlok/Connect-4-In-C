#include <stdio.h>

char board[4][8];

void resetBoard();
void drawBoard();
int possibleMoves();
void playerMove();
void computerMove();
char checkWinner();

int main() {
    char player = ' ';
    char computer = ' ';

    resetBoard();

    drawBoard();

    return 0;
}

void resetBoard(){
    for(int i = 0; i < 4; i++){
        for(int j = 0; j < 8; j++){
            board[i][j] = ' ';
        }
    }
}

void drawBoard(){
    printf("| %c | %c | %c | %c | %c | %c | %c | %c |\n", board[0][0], board[0][1], board[0][2], board[0][3], board[0][4], board[0][5], board[0][6], board[0][7]);
    printf("---------------------------------\n");
}