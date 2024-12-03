#include <stdio.h>
#define SIZE 8

int contaMinacciati(char a[][SIZE]);

int main() {
    char scacchiera[SIZE][SIZE] = {
        {' ', ' ', ' ', 'R', ' ', ' ', ' ', ' '},
        {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
        {' ', 'A', ' ', 'A', ' ', ' ', ' ', ' '},
        {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
        {' ', 'C', ' ', 'D', ' ', 'P', ' ', ' '},
        {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
        {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
        {' ', ' ', ' ', 'T', ' ', ' ', ' ', ' '},
        
    };
    for(int i = 0; i < SIZE; i++) {
        for(int j = 0; j < SIZE; j++) {
            printf("|%c", scacchiera[i][j]);
        }
        printf("\n");
    }
    printf("%d\n", contaMinacciati(scacchiera));
}
int contaMinacciati(char a[][SIZE]) {
    int iRegina, jRegina, trovato = 0;;
    for(int i = 0; i < SIZE && !trovato; i++) {
        for(int j = 0; j < SIZE && !trovato; j++) {
            if(a[i][j] == 'D') {
                iRegina = i;
                jRegina = j;
                trovato = 1;
            }
        }
    }

    char pedine[6] = {'R', 'T', 'D', 'A', 'C', 'P'};

    int count = 0;
    int trovataDiag1 = 0;
    int trovataDiag2 = 0;
    int trovataDiag3 = 0;
    int trovataDiag4 = 0;
    int trovataNord = 0;
    int trovataSud = 0;
    int trovataSX = 0;
    int trovataDX = 0;
    for(int i = 1; i < SIZE; i++) {
        if(iRegina + i < SIZE && jRegina + i < SIZE) {
            for(int j = 0; j < 6 && !trovataDiag1; j++) {
                if(a[iRegina + i][jRegina + i] == pedine[j]) {
                    trovataDiag1 = 1;
                    count++;
                }
            } 
        }

        if(iRegina - i >= 0 && jRegina - i >= 0) {
            for(int j = 0; j < 6 && !trovataDiag2; j++) {
                if(a[iRegina - i][jRegina - i] == pedine[j]) {
                    trovataDiag2 = 1;
                    count++;
                }
            } 
        }

        if(iRegina + i < SIZE && jRegina - i >= 0) {
            for(int j = 0; j < 6 && !trovataDiag3; j++) {
                if(a[iRegina + i][jRegina - i] == pedine[j]) {
                    trovataDiag3 = 1;
                    count++;
                }
            } 
        }

        if(iRegina - i >= 0 && jRegina + i < SIZE) {
            for(int j = 0; j < 6 && !trovataDiag4; j++) {
                if(a[iRegina - i][jRegina + i] == pedine[j]) {
                    trovataDiag4 = 1;
                    count++;
                }
            } 
        }

        if(iRegina - i < SIZE) {
            for(int j = 0; j < 6 && !trovataNord; j++) {
                if(a[iRegina - i][jRegina] == pedine[j]) {
                    trovataNord = 1;
                    count++;
                }
            }   
        }

        if(iRegina + i >= 0) {
            for(int j = 0; j < 6 && !trovataSud; j++) {
                if(a[iRegina + i][jRegina] == pedine[j]) {
                    trovataSud = 1;
                    count++;
                }
            } 
        }

        if(jRegina + i < SIZE) {
            for(int j = 0; j < 6 && !trovataDX; j++) {
                if(a[iRegina][jRegina + i] == pedine[j]) {
                    trovataDX = 1;
                    count++;
                }
            } 
        }

        if(jRegina - i >= 0) {
            for(int j = 0; j < 6 && !trovataSX; j++) {
                if(a[iRegina][jRegina - i] == pedine[j]) {
                    trovataSX = 1;
                    count++;
                }
            } 
        }


        
        
    }

    
    return count;
}