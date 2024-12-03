#include <stdio.h>
#include <string.h>
#define SIZE 100

typedef struct {
    char nome[21];
    char cognome[21];
    char numero[7];
} prenotazione;

int main() {
    prenotazione studenti[SIZE];

    for(int i = 0; i < SIZE; i++) {
        studenti[i].nome[0] = '\0';
        studenti[i].cognome[0] = '\0';
        studenti[i].numero[0] = '\0';
    }
    int scelta;
    do {
        int index = 0;
        do{
            printf("1) Inserisci prenotazione.\n");
            printf("2) Cancella prenotazione.\n");
            printf("3) Stampa prenotazione.\n");
            printf("4) Esci.\n\n");
            printf("Scegli un opzione: ");
            scanf("%d", &scelta);
            if(scelta < 1 || scelta > 4) {
                printf("Valore immesso non valido.\n\n");
            }
        } while (scelta < 1 || scelta > 4);
        
        if(scelta == 1) {
            printf("> Inserisci il nome: ");
            scanf("%20s", studenti[index].nome);
            
            printf("> Inserisci il cognome: ");
            scanf("%20s", studenti[index].cognome);
            
            printf("> Inserisci il numero matricola: ");
            scanf("%6s", studenti[index].numero);
            
            printf("Prenotazione effettuata, posto %d\n\n", index+1);
            index++;
        }
        if(scelta == 2) {
            char matricola[7];
            printf("> Inserisci il numero matricola della prenotazione da eliminare: ");
            scanf("%6s", matricola);
            int trovato = 0;
            
            for(int i = 0; i < SIZE && !trovato; i++) {
                if(strcmp(studenti[i].numero, matricola) == 0) {
                    studenti[i].nome[0] = '\0';
                    studenti[i].cognome[0] = '\0';
                    studenti[i].numero[0] = '\0';
                    trovato = 1;
                }
            }
            if(trovato) {
                printf("Prenotazione eliminata.");
            } else {
                printf("La prenotazione non esiste.");
            }
            printf("\n\n");
        }
        if(scelta == 3) {
            int finito = 0;
            for(int i = 0; i < SIZE && !finito; i++) {
                if(studenti[i].nome[0] == '\0') {
                    finito = 1;
                    if(!i) {
                        printf("Non ci sono state prenotazioni\n\n\n");
                    }
                } else {
                    printf("PRENOTAZIONE No. %d\n", i+1);
                    printf("Nome: %s\nCognome: %s\nMatricola: %s\n\n\n", studenti[i].nome, studenti[i].cognome, studenti[i].numero);
                }
            }
        }
        
    } while (scelta != 4);
}