#include <stdio.h>

//Initialisierung des Boards
    char board[3][3] ={
        {' ',' ',' '},
        {' ',' ',' '},
        {' ',' ',' '}
    };

    char player = 'O';

void playerMove() {
    int validMove = 0;
    while (validMove != 1) {
        int row, col;

        printf("Spieler %c, gibt Zeile (1-3) und Spalte (1-3) an \n", player);
        scanf("%d %d", &row, &col);
        //Eingabenüberprüfung
        if (row >= 1 && row <= 3 && col >= 1 && col <= 3) {

            row = row - 1;
            col = col - 1;
            if (board[row][col] == ' ') {
                board[row][col] = player;       //Zug setzen
                if (player == 'X') {            //Spieler check
                    player = 'O';
                } else {
                    player = 'X';
                }
                validMove = 1;
            }
            else {
                printf("Feld belegt!\n");
            }

        }
        else {
            printf("Ungültige Eingabe\n");
            continue;
        }
    }
}

int checkGameState() {
    // 1. Waagerecht prüfen (Schleife für Zeilen)
    for (int r = 0; r < 3; r++) {
        if (board[r][0] != ' ' && board[r][0] == board[r][1] && board[r][1] == board[r][2]) {
            return 1;
        }
    // 2. Senkrecht prüfen
         if (board[0][r] != ' ' && board[0][r] == board[1][r] && board[1][r] == board[2][r]) {
            return 1;
        }

    }
    // Diagonalen checken
     if (board[0][0] != ' ' && board[0][0] == board[1][1] && board[1][1] == board[2][2] ) {
        return 1;
    }

     if (board[0][2] != ' ' && board[0][2] == board[1][1] && board[1][1] == board[2][0]) {
        return 1;
    }

    return 0;
}
//Board printen durch schleifendurchgang des ganzen arrays
void printBoard() {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            printf("|%c|", board[i][j]);
        }
        printf("\n");
    }

    printf("\n");
}



int main(void) {
    int gamestate = checkGameState();
    while (gamestate == 0) {
        printBoard();
        playerMove();
        gamestate = checkGameState();
    }

    printBoard();


//Wechsel des Spielers da der Zug erfolgreich war aber gamestate das Spiel beendet nachm Spieler wechsel
    if (player == 'X') {
        printf("Player 0 hat gewonnen\n");

    }
    else {
        printf("Player X hat gewonnen\n");

    }


    printf("Druecke irgendwas zum beenden\n");
    char input;
    scanf(" %c", &input);

    return 0;
}
