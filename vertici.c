#include <stdio.h>
#include <math.h>

typedef struct {
    double x;
    double y;
} punto;

double distanza(punto a, punto b);
double perimetro(punto v[], int n);

double perimetro(punto v[], int n) {
    double somma = 0;

    for(int i = 0; i < n; i++) {
        if(i + 1 == n) {
            somma += distanza(v[i], v[0]);
        } else {
            somma += distanza(v[i], v[i+1]);
        }
    }

    return somma;
}

double distanza(punto a, punto b) {
    return pow(pow(a.x - b.x, 2) + pow(a.y - b.y, 2), 0.5);
}

int main() {
    printf("> Inserisci il numero di punti da inserire: ");
    int n;
    scanf("%d", &n);

    punto vertici[n];

    for(int i = 0; i < n; i++) {
        printf("> Coordinata X del punto %d: ", i+1);
        scanf("%lg", &vertici[i].x);
        printf("> Coordinata Y del punto %d: ", i+1);
        scanf("%lg", &vertici[i].y);
        printf("\n\n");
    }

    printf("> Il perimetro del poligono a %d lati è: %g\n", n, perimetro(vertici, n));

}