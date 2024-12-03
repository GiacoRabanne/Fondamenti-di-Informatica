#include <stdio.h>

void pulizia (int m, int n, int a[][n]) {
    int isolato;
    for(int i = 0; i < m; i++) {
        for(int j = 0; j < n; j++) {
            if(a[i][j] == 1) { // se il pixel è nero.
            isolato = 1;
                


                for(int g = -1; g <= 1 && isolato; g++) {
                    for(int h = -1; h <= 1 && isolato; h++) {
                        if(g+i >= 0 && g+i < m && h +j >= 0 && h+j < n && (g != 0 && h != 0)) {
                            if(a[g+i][h+i] == 1) {
                                isolato = 0;
                            }
                        } 
                    }
                }

                if(isolato) {
                    a[i][j] = 0;
                }
            }
        }
    }
}

int main() {

    int m = 3;
    int n = 3;
    int a[3][3] = {
        {0, 0, 0},
        {0, 1, 0},
        {0, 0, 0},
    };


    for(int i = 0; i < m; i++) {
        for(int j = 0; j < n; j++) {
            printf("%d ", a[i][j]);
        }
        printf("\n");
    }

    pulizia(m,n, a);
    printf("\n\n\n\n");

    for(int i = 0; i < m; i++) {
        for(int j = 0; j < n; j++) {
            printf("%d ", a[i][j]);
        }
        printf("\n");
    }

}