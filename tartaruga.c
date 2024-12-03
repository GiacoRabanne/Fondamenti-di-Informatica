#include <stdio.h>
#define SIZE 20

void iniziaPavimento(char *s, int n, int a[][n], int *penna, int posizione[], int orientamento[]);

int main() {
    int pavimento[SIZE][SIZE], penna, posizione[2], orientamento[2];
    char freccia;
    iniziaPavimento(&freccia, SIZE, pavimento, &penna, posizione, orientamento);
    int scelta;
    
    
    do {
    printf("1 - Penna alzata\n");
    printf("2 - Penna abbassata\n");
    printf("3 - Gira a destra\n");
    printf("4 - Gira a sinistra\n");
    printf("5 - Spostati in avanti di n posizioni\n");
    printf("6 - Visualizza lo schema\n");
    printf("7 - Esci\n\n");

    printf("> Immetti il comando: ");
    scanf("%d", &scelta);

    if(scelta == 1) {
        penna = 0;
    }

    if(scelta == 2) {
        penna = 1;
        pavimento[posizione[0]][posizione[1]] = 1;
    }

    if(scelta == 3) {
        if(orientamento[0] == posizione[0] && orientamento[1]>posizione[1]) { //->
            orientamento[0] += 1;
            orientamento[1] -= 1;
            freccia = 'v';
        } else if(orientamento[0] == posizione[0] && orientamento[1]<posizione[1]) { //<-
            orientamento[0] -= 1;
            orientamento[1] += 1;
            freccia = '^';
        } else if(orientamento[1] == posizione[1] && orientamento[0]>posizione[0]) { //v
            orientamento[0] -= 1;
            orientamento[1] -= 1;
            freccia = '<';
        } else if(orientamento[1] == posizione[1] && orientamento[0]<posizione[0]) { //^
            orientamento[0] += 1;
            orientamento[1] += 1;
            freccia = '>';
        }
    }

    if(scelta == 4) {
        if(orientamento[0] == posizione[0] && orientamento[1]>posizione[1]) {
            orientamento[0] -= 1;
            orientamento[1] -= 1;
            freccia = '^';
        } else if(orientamento[0] == posizione[0] && orientamento[1]<posizione[1]) {
            orientamento[0] += 1;
            orientamento[1] += 1;
            freccia = 'v';
        } else if(orientamento[1] == posizione[1] && orientamento[0]>posizione[0]) {
            orientamento[0] -= 1;
            orientamento[1] += 1;
            freccia = '>';
        } else if(orientamento[1] == posizione[1] && orientamento[0]<posizione[0]) {
            orientamento[0] += 1;
            orientamento[1] -= 1;
            freccia = '<';
        }
    }

    if(scelta == 5) {
        int n;
        printf("> Di quante caselle desideri spostarti avanti?: ");
        scanf("%d", &n);
        
            if(orientamento[0] == posizione[0] && orientamento[1]>posizione[1]) {
                if(posizione[1] + n >= SIZE) {
                    printf("ERRORE, non puoi andare oltre.\n");
                } else {
                    if(penna) {
                        for(int i = 1; i <= n; i++) {
                            pavimento[posizione[0]][posizione[1]+i] = 1;
                        }
                    }
                    posizione[1] += n;
                    orientamento[1] += n;
                }
                
            } else if(orientamento[0] == posizione[0] && orientamento[1]<posizione[1]) {
                if(posizione[1] - n < 0) {
                    printf("ERRORE, non puoi andare oltre.\n");
                } else {
                    if(penna) {
                        for(int i = 1; i <= n; i++) {
                            pavimento[posizione[0]][posizione[1]-i] = 1;
                        }
                    }
                    posizione[1] -= n;
                    orientamento[1] -= n;
                }
            } else if(orientamento[1] == posizione[1] && orientamento[0]>posizione[0]) {
                if(posizione[0] + n >= SIZE) {
                    printf("ERRORE, non puoi andare oltre.\n");
                } else {
                    if(penna) {
                        for(int i = 1; i <= n; i++) {
                            pavimento[posizione[0] + i][posizione[1]] = 1;
                        }
                    }
                    posizione[0] += n;
                    orientamento[0] += n;
                }
            } else if(orientamento[1] == posizione[1] && orientamento[0]<posizione[0]) {
                if(posizione[0] - n < 0) {
                    printf("ERRORE, non puoi andare oltre.\n");
                } else {
                    if(penna) {
                        for(int i = 1; i <= n; i++) {
                            pavimento[posizione[0] - i][posizione[1]] = 1;
                        }
                    }
                    posizione[0] -= n;
                    orientamento[0] -= n;
                }
            }
        
    }

    if(scelta == 6) {
        for(int i = 0; i < SIZE; i++) {
            for(int j = 0; j < SIZE; j++) {
                if(i == posizione[0] && j == posizione[1]) {
                    printf("T"); //tartaruga
                } else if(i == orientamento[0] && j == orientamento[1]) {
                    printf("%c", freccia);
                } else if(pavimento[i][j] == 1) {
                    printf("*");
                }  else {
                    printf(" ");
                }
            }
            printf("\n");
        }
    }
    if(scelta < 1 || scelta > 7) {
        printf("Valore non valido.\n");
    }


    } while (scelta != 7);
}

void iniziaPavimento(char *s, int n, int a[][n], int* penna, int posizione[], int orientamento[]) {
    *penna = 0;
    for(int i = 0; i < SIZE; i++) {
        for(int j = 0; j < SIZE; j++) {
            if(!i && !j) {
                posizione[0] = i;
                posizione[1] = j;
            } 
            a[i][j] = 0;
        }
    }
    orientamento[0] = 0;
    orientamento[1] = 1;
    *s = '>';
}