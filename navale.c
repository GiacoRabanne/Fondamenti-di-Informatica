#include <stdio.h>

int colpo(int m, int n, int schema[][n], int i, int j);

int main(){

}

int colpo(int m, int n, int schema[][n], int i, int j) {
    

    if(schema[i][j] == 0) {
        return 0;
    } else {
        if(schema[i][j] > 0) {
            schema[i][j] = -schema[i][j];
        }
        for(int g = 0; g < n; g++) {
            if(schema[i][g] > 0) {
                return 1;
            }
        }
        return 2;
    }
    
}