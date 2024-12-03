#include <stdio.h>
#include <string.h>

typedef struct {
    char nome[21];
    double quantita;
} ingrediente;

int main() {
    printf("> Quanti ingredienti prevede la ricetta?: ");
    int size;
    scanf("%d", &size);
    ingrediente ingredienti[size];
    printf("\n\n");
    
    for(int i = 0; i < size; i++) {
        printf("> Inserire nome Ingrediente %d: ", i+1);
        getchar();
        fgets(ingredienti[i].nome, 21, stdin);
        if(ingredienti[i].nome[strlen(ingredienti[i].nome)-1] == '\n') {
            ingredienti[i].nome[strlen(ingredienti[i].nome)-1] = '\0';
        }
        
        
        printf("> Inserire quantita' di %s: ", ingredienti[i].nome);
        scanf("%lg", &ingredienti[i].quantita);
        printf("\n");
    }
    
    
    printf("\n> Per quante porzioni è prevista la ricetta?: ");
    double porzioni, desiderate;
    scanf("%lg", &porzioni);
    printf("> Per quante porzioni la si vuole realizzare?: ");
    scanf("%lg", &desiderate);
    
    printf("\n\n> Ecco le quantità di ogni ingrediente:\n");
    
    for(int i = 0; i < size; i++) {
        double quantita = ingredienti[i].quantita * desiderate / porzioni;
        
        printf("%d) Quantita' %s: %g\n", i+1, ingredienti[i].nome, quantita);
    }
    
    
}