#include <stdio.h>
#include <string.h>

typedef struct {
    char nome[20];
    char cognome[20];
    char nazionalita[20];
    int bagagli;
} passeggero;

void menu(int *opzione);

void scanParole(char *p);

int main() {
    FILE* fin = fopen("passeggeri.dat", "w+");
    if(fin == NULL) {
        printf("> Impossibile aprire il file.\n");
    } else {
        passeggero vuoto = {"", "", "", -1};
        for(int i = 0; i < 150; i++) {
            fwrite(&vuoto, sizeof(passeggero), 1, fin);
        }
        int opzione;
        do{
            menu(&opzione);
            if(opzione == 1) {
                int trovato = 0;
                passeggero p;
                for(int i = 0; i < 150 && !trovato; i++) {
                    fseek(fin, i*sizeof(passeggero), SEEK_SET);
                    fread(&p, sizeof(passeggero), 1, fin);

                    if(p.bagagli == -1) {
                        trovato = 1;
                        printf("> Inserire il nome: ");
                        scanParole(p.nome);

                        printf("> Inserire il cognome: ");
                        scanParole(p.cognome);

                        printf("> Inserire la nazionalita': ");
                        scanParole(p.nazionalita);

                        do{
                            printf("> Inserisci il numero di bagagli: ");
                            scanf("%d", &p.bagagli);
                            if(p.bagagli < 0) {
                                printf("- Valore non valido.\n\n");
                            }
                        } while(p.bagagli < 0);

                        fseek(fin, -sizeof(passeggero), SEEK_CUR);
                        fwrite(&p, sizeof(passeggero), 1, fin);
                        
                        printf("Il tuo posto è il numero %d\n\n", i+1);
                    }
                }
                if(!trovato) {
                    printf("> Il volo è pieno.\n");
                }
            } else if(opzione == 2) {
                int posto;
                printf("> Inserisci il numero del posto: ");
                scanf("%d", &posto);

                passeggero p;
                fseek(fin, (posto-1)*sizeof(passeggero), SEEK_SET);
                fread(&p, sizeof(passeggero), 1, fin);

                if(p.bagagli != -1) {
                    printf("Ecco le informazioni relative al posto prenotato:\n");
                    printf("Nome: %s\nCognome: %s\nNazionalita': %s\nNumero bagagli: %d", p.nome, p.cognome, p.nazionalita, p.bagagli);
                } else {
                    printf("Questo posto non è stato prenotato.");
                }
                printf("\n\n");
            } else if(opzione == 3) {
                int posto;
                printf("> Inserisci il numero del posto da eliminare: ");
                scanf("%d", &posto);

                passeggero p;
                fseek(fin, (posto-1)*sizeof(passeggero), SEEK_SET);
                fread(&p, sizeof(passeggero), 1, fin);

                if(p.bagagli != -1) {
                    fseek(fin, -sizeof(passeggero), SEEK_CUR);
                    fwrite(&vuoto, sizeof(passeggero), 1, fin);

                    printf("Prenotazione cancellata con successo.");
                } else {
                    printf("Questo posto non è stato prenotato.");
                }
                printf("\n\n");
            } else if(opzione == 4) {
                printf("Lista prenotazioni totali:\n");
                passeggero p;
                int finito = 0;
                for(int i = 0; i < 150 && !finito; i++) {
                    fseek(fin, i*sizeof(passeggero), SEEK_SET);
                    fread(&p, sizeof(passeggero), 1, fin);

                    if(p.bagagli != -1) {
                        printf("POSTO %d\n\n", i+1);
                        printf("Nome: %s\nCognome: %s\nNazionalita': %s\nNumero bagagli: %d", p.nome, p.cognome, p.nazionalita, p.bagagli);
                    } else {
                        finito = 1;
                        if(i == 0) {
                            printf("Non ci sono state prenotazioni.\n");
                        }
                    }
                    printf("\n\n");
                }
            }

        } while (opzione != 5);
    }
}

void menu(int *opzione) {
        printf("1 - Prenota\n");
        printf("2 - Verifica prenotazione per numero di posto\n");
        printf("3 - Cancella prenotazione\n");
        printf("4 - Stampa lista passeggeri\n");
        printf("5 - Esci\n");
        

        do{
            printf("\n> Scegli un opzione: ");
            scanf("%d", opzione);
            if(*opzione < 1 || *opzione > 5) {
                printf("\n- Valore non valido.\n\n");
            }
        } while(*opzione < 1 || *opzione > 5);
        getchar();
        printf("\n\n");
}

void scanParole(char *p) {
    fgets(p, 19, stdin);
    if(p[strlen(p)-1] == '\n') {
        p[strlen(p)-1] = '\0';
    }
}