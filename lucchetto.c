#include <stdio.h>
#include <string.h>

int lucchetto (char *s1, char *s2);

int main() {
    printf("> Inserisci una parola: ");
    char s1[21];
    scanf("%20s", s1);
    printf("> Inserisci un'altra parola: ");
    char s2[21];
    scanf("%20s", s2);
    printf("%s %s", s1, s2);

    printf("\n\n%d\n", lucchetto(s1, s2));
}

int lucchetto(char *s1, char *s2) {
    int count, trovato;
    for(int i = 0; s1[i] != '\0' && !trovato; i++) {
        count = 0, trovato = 0;
        int index;
        

        for(int j = 0; s2[j] != '\0' && !trovato; j++) {
            if(s2[j] == s1[i]) {
                index = j;
                trovato = 1;
            }
        }//ritrova la lettera iniziale.

        for(int k = 1; s1[k] != '\0' && trovato; i++) {
            if(s1[i+k] == s2[index - k]) {
                count++;
            } else {
                trovato = 0;
            }
        }

    }
    return count;
}