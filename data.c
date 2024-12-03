#include <stdio.h>
#include <stdlib.h>

typedef struct{
    int giorno;
    int mese;
    int anno;
} data;

void eta(data d, data a);

int main() {
    data d;
    printf("> Inserisci una data di riferimento: ");
    scanf("%d%d%d", &d.giorno, &d.mese, &d.anno);

    data *a = malloc(sizeof(data));
    int index = 0;

    do {
        printf("> Immetti una sequenza di date (0 0 0 per terminare): ");
        scanf("%d%d%d", &a[index].giorno, &a[index].mese, &a[index].anno);
        if(a[index].giorno < 0 || a[index].giorno > 31 || a[index].mese < 0 || a[index].mese > 12 ) {
            printf("ERRORE, Valore non valido.\n%d %d %d\n", a[index].giorno, a[index].mese, a[index].anno);
        } else if(a[index].giorno != 0 || a[index].mese != 0 || a[index].anno != 0){
            eta(d, a[index]);
            index++;
        }
    } while(a[index-1].giorno != 0);

    free(a);
}

void eta(data d, data a) {
    if(a.giorno < d.giorno && a.mese < d.mese && a.anno < d.anno) {
        printf("> La data %d/%d/%d viene prima della data %d/%d/%d\n\n\n", a.giorno, a.mese, a.anno, d.giorno, d.mese, d.anno);
    } else {
        int g, m, y;
        int restog = 0, restom = 0;
        if(a.giorno >= d.giorno) {
            g = a.giorno - d.giorno;
        } else if(a.giorno < d.giorno) {
            g = 31 + a.giorno - d.giorno;
            restog = 1;
        }

        if(restog) {
            if(a.mese > d.mese) {
                m = a.mese - d.mese - 1;
            } else {
                m = a.mese - d.mese - 1 + 12;
                restom = 1;
            }
        } else if(!restog) {
            if(a.mese >= d.mese) {
                m = a.mese - d.mese;
            } else {
                m = a.mese - d.mese + 12;
                restom = 1;
            }
        }

        if(restom) {
            y = a.anno - d.anno - 1;
        } else if(!restom) {
            y = a.anno - d.anno;
        }

        printf("> La data %d/%d/%d e la data di riferimento %d/%d/%d distano:\n%d Giorni.\n%d Mesi.\n%d Anni.\n\n\n", a.giorno, a.mese, a.anno, d.giorno, d.mese, d.anno, g, m , y);
    }
}