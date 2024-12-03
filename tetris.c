#include <stdio.h>

void controllaRighe(int n, int m, int a[][m]) {
    int tetris;

    for (int i = n-1; i >= 0; i--) {
        tetris = 1;
        for(int j = 0; j < m && tetris; j++) {
            if(a[i][j] == 0) {
                tetris = 0;
            }
        }

        if(tetris) {
            for(int g = i-1; g >= 0; g--) {
                for(int h = 0; h < m; h++) {
                    a[g+1][h] = a[g][h];
                }
                
            }
            i--; //così rimane fermo.
        }
    }
}

int main() {
    int n = 10;
    int m = 10;

    int array[10][10] = {
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 1, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 1, 0, 0, 0, 0, 0},
        {1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
        {0, 0, 0, 0, 0, 0, 1, 0, 0, 0},
        {0, 0, 0, 0, 1, 1, 1, 0, 0, 0},
        {0, 0, 1, 1, 1, 0, 0, 0, 0, 0},
        {1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    };

    controllaRighe(n, m, array);

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            printf("%d ", array[i][j]);
        }
        printf("\n");
    }
}