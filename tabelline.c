#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    srand(time(NULL));
    int count = 0;

    for(int i = 0; i < 10; i++) {
        printf("PROVA N°%d:\n", i+1);
        int n1, n2;
        n1 = rand()%10 + 1;
        n2 = rand()%10 + 1;
        int prod = n1*n2;
        int scelta;
        do {
            printf("> Qual è il risultato di %d x %d?: ", n1, n2);
            scanf("%d", &scelta);
            if(scelta != prod) {
                printf("> Mi dispiace, il risultato è sbagliato!\n\n");
            }
            count++;
        } while(scelta != prod);
    }

    if(count == 10) {
        printf("> Bravissimo!");
    } else if(count >= 11 && count <= 13) {
        printf("> Bravo!");
    } else if (count >= 14 && count <= 16){
        printf("> Bravino...");
    } else {
        printf("> Devi allenarti di più.");
    }
    printf("\nN° Tentativi: %d.\n", count);
}