#include <stdio.h>
#include <string.h>
#include <time.h>
#include <stdlib.h>

int main() {
    char *dizionario[] = {"sole", "mare", "neve"};
    srand(time(NULL));

    
    char *parola = dizionario[rand()%3];
    int l = strlen(parola), i;
    char *nascosta;
    
    for(i = 0; parola[i] != '\0'; i++) {
       nascosta[i] = '_';
    }
    nascosta[i] = '\0';

    
    
    int indovinata = 0, count = 0;

    while (!indovinata && count < 6) {
        printf("Parola da indovinare:\n%s\n\n", nascosta);

        printf("> Inserisci una lettera: ");
        char c;
        scanf("%c", &c);
        getchar();
        int trovata = 0;
        
        for(int i = 0; parola[i] != '\0'; i++) {
            if(parola[i] == c) {
                nascosta[i] = c;
                trovata = 1;
            }
        }

        if(trovata) {
            printf("Ci hai preso!\n");
            indovinata = 1;
            for(int i = 0; nascosta[i] != '\0' && indovinata; i++) {
                if(nascosta[i] == '_') {
                    indovinata = 0;
                }
            }
        } else {
            printf("Questa parola non è contenuta.\n");
            count++;
        }
        
    }
    
    if(count == 6 && !indovinata) {
        printf("> la parola era: '%s'", parola);
    } else {
        printf("> Hai indovinato la parola '%s'!\n", parola);
    }
}