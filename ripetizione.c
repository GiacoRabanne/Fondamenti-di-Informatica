#include <stdio.h>

int main() {
    printf("> Inserisci la dimensione dell'array: ");
    int size;
    scanf("%d", &size);
    
    int a[size];
    for(int i = 0; i < size; i++) {
        printf("> Elemento in posizione %d: ", i);
        scanf("%d", (a+i));
    }
    printf("\n\n");
    
    for(int i = 0; i < size; i++) {
        int trovato = 0;
        for(int j = i+1; j < size && !trovato; j++) {
            if(a[i] == a[j]) {
                printf("%d ", i);
                trovato = 1;
            }
        }
    }
}