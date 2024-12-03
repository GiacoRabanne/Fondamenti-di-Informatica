#include <stdio.h>

int contaMinacciati(int size, char a[][size]);

int main() {
    char scacchiera[8][8] = {
        {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
        {' ', ' ', ' ', ' ', ' ', ' ', 'T', ' '},
        {' ', 'R', ' ', ' ', ' ', 'D', ' ', ' '},
        {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
        {' ', ' ', ' ', 'A', ' ', ' ', ' ', ' '},
        {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
        {' ', 'P', ' ', ' ', ' ', 'C', ' ', ' '},
        {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
    };
    
    printf("Minacciati: %d.\n", contaMinacciati(8, scacchiera));
}


int contaMinacciati(int size, char a[][size]) {
    int riga, colonna, trovato, count = 0;
    
    char pedine[] = {'R', 'D', 'T', 'A', 'C', 'P'};
    
    for(int i = 0; i < size; i++) {
        for(int j = 0; j < size; j++) {
            if(a[i][j] == 'A') {
                riga = i;
                colonna = j;
            }
        }
    }
    
    trovato = 0;
    for(int i = 1; i+riga < size && colonna+i < size && !trovato; i++) {
        for(int p = 0; p < sizeof(pedine) && !trovato; p++) {
            if(a[riga+i][colonna+i] == pedine[p]) {
                count++;
                trovato = 1;
            }
        }
    }
    
    trovato = 0;
    for(int i = 1; i+riga < size && colonna-i < size && !trovato; i++) {
        for(int p = 0; p < sizeof(pedine) && !trovato; p++) {
            if(a[riga+i][colonna-i] == pedine[p]) {
                count++;
                trovato = 1;
            }
        }
    }
    
    trovato = 0;
    for(int i = 1; i-riga < size && colonna+i < size && !trovato; i++) {
        for(int p = 0; p < sizeof(pedine) && !trovato; p++) {
            if(a[riga+i][colonna-i] == pedine[p]) {
                count++;
                trovato = 1;
            }
        }
    }
    
    trovato = 0;
    for(int i = 1; i-riga < size && colonna-i < size && !trovato; i++) {
        for(int p = 0; p < sizeof(pedine) && !trovato; p++) {
            if(a[riga+i][colonna-i] == pedine[p]) {
                count++;
                trovato = 1;
            }
        }
    }
    
    return count;
}