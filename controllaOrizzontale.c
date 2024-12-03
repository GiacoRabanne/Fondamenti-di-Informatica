#include <stdio.h>
#define r 7
#define c 7

int controllaOrizzontale(int n, int a[][n]);

int main() {
    int scacchi[r][c] = {
        {0, 0, 1, 1, 0, 0, 0},
        {0, 0, 1, 1, 0, 0, 0},
        {0, 0, 0, 1, 0, 0, 0},
        {0, 0, 1, 1, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0},
    };
    printf("%d", controllaOrizzontale(c, scacchi));
}

int controllaOrizzontale(int n, int a[][n]) {

    for(int i = 0; i < r; i++) {
        for(int j = 0; j < c; j++) {
            if(a[i][j] && a[i+1][j] && a[i+2][j] && a[i+3][j] && i < 4) {
                return 1;
            }
        }
    }

    return 0;
}