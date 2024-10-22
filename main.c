#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>

char board[4][8];

const char PLAYER = '*';
const char COMPUTER =  'O';

void resetBoard();
void drawBoard();
int possibleMoves();
void playerMove();
void computerMove();
char checkWinner();

int main() {
    char winner = ' ';

    resetBoard();

    while (winner == ' ' && possibleMoves() != 0){
        drawBoard();

        playerMove();
        winner = checkWinner();
        if (winner != ' ' || possibleMoves() == 0){
            break;
        }

        computerMove();
        winner = checkWinner();
        if (winner != ' ' || possibleMoves() == 0){
            break;
        }
    }


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
    printf("| %c | %c | %c | %c | %c | %c | %c | %c |\n", board[1][0], board[1][1], board[1][2], board[1][3], board[1][4], board[1][5], board[1][6], board[1][7]);
    printf("---------------------------------\n");
    printf("| %c | %c | %c | %c | %c | %c | %c | %c |\n", board[2][0], board[2][1], board[2][2], board[2][3], board[2][4], board[2][5], board[2][6], board[2][7]);
    printf("---------------------------------\n");
    printf("| %c | %c | %c | %c | %c | %c | %c | %c |\n", board[3][0], board[3][1], board[3][2], board[3][3], board[3][4], board[3][5], board[3][6], board[3][7]);
    printf("---------------------------------\n");
    printf("  1   2   3   4   5   6   7   8\n");
}

int possibleMoves(){
   int total = 0;

    for(int i = 0; i < 4; i++){
        for(int j = 0; j < 8; j++){
            if(board[i][j] == ' '){
                total++;
            }
        }
    }
}

void playerMove(){
    int mv;

    printf("\n Wybierz kolumnę: ");
    scanf("%d", &mv);
    mv--;

    for (int i = 0; i <= 4; i++){
        if (board[4 - i][mv] == ' '){
            board[4 - i][mv] = PLAYER;
            break;
        }
    }
}

void computerMove(){
    bool quit = true;
    do{
        srand(time(0));
        int computerMove = rand() % 8;

        for (int i = 0; i <= 4; i++){
            if (board[4 - i][computerMove] == ' '){
                quit = false;
                board[4 - i][computerMove] = COMPUTER;
                break;
            }
        }
    } while (quit == true);
}

char checkWinner(){
    for (int i = 0; i < 8; i++){ // Sprawdzenie vertyczne
        if(board[0][i] == board[1][i] && board[0][i] == board[2][i] && board[3][i] && board[0][i] != ' '){
            return board[0][i];
        }
    }

    for (int i = 0; i < 4; i++){ // Sprawdzenie horyzontalne
        for (int j = 0; j <= 4; j++){
            if(board[i][j] == board[i][j+1] && board[i][j] == board[i][j+2] && board[i][j] == board[i][j+3] && board[i][j] != ' '){
                return board[i][j];
            }
        }
    }

    for (int i = 0; i <= 4; i++){ // Sprawdzenie na skos z góry do dołu
        if (board[0][i] == board[1][i+1] && board[0][i] == board[2][i+2] && board[0][i] == board[3][i+3] && board[0][i] != ' '){
            return board[0][i];
        }
    }

    for (int i = 0; i <= 4; i++){ // Sprawdzenie na skos z dołu do góry
        if (board[3][i] == board[2][i+1] && board[3][i] == board[1][i+2] && board[3][i] == board[0][i+3] && board[3][i] != ' '){
            return board[3][i];
        }
    }

    return ' ';
}