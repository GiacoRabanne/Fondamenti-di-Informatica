#include <stdio.h>

int verificaRegione(int size, int a[][size], int m, int n);
int verificaColonne(int size, int a[][size]);
int verificaRighe(int size, int a[][size]);

int main() {
	int schema[9][9] = {
		{8, 2, 7, 1, 5, 4, 3, 9, 6},
		{9, 6, 5, 3, 2, 7, 1, 4, 8},
		{3, 4, 1, 6, 8, 9, 7, 5, 2},
		{5, 9, 3, 4, 6, 8, 2, 7, 1},
		{4, 7, 2, 5, 1, 3, 6, 8, 9},
		{6, 1, 8, 9, 7, 2, 4, 3, 5},
		{7, 8, 6, 2, 3, 5, 9, 1, 4},
		{1, 5, 4, 7, 9, 6, 8, 2, 3},
		{2, 3, 9, 8, 4, 1, 5, 6, 7},
	};
	
	//printf("%d\n", verificaRegione(9, schema, 0, 0));
	int risolto = 1; 
	for(int i = 0; i <= 6 && risolto; i+=3) {
		for(int j = 0; j <= 6 && risolto; j+=3) {
			if(!verificaRegione(9, schema, i, j)) {
				risolto = 0;
			}
		}
	}

	if(risolto && verificaRighe(9, schema) && verificaColonne(9, schema)) {
		printf("Il sudoku è risolto.\n");
	} else {
		printf("Il sudoku non è risolto.\n");
	}
}

int verificaRegione(int size, int a[][size], int m, int n) {

	for(int i = m; i < 3+m; i++) {
		for(int j = n; j < 3+n; j++) {
			if(a[i][j] < 1 || a[i][j] > 9) {
				return 0; //se la cella ospita un intero non compreso nell'intervallo [1,9] allora la regione non è riempita correttamente.
			}
			for(int k = i; k < 3+m; k++) {
				for(int l = j; l < 3+n; l++) {
					if(a[i][j] == a[k][l] && !(k == i && l == j)) { //se le celle successive sono uguali alla cella a[i][j], ad esclusione della cella stessa, allora la regione è riempita in maniera errata
						return 0;
					}
				}
			}
		}
	}

	return 1;
}

int verificaRighe(int size, int a[][size]) {
    for(int j = 0; j < size; j++) {
        for(int index = 1; index < size; index++) {
            if(a[0][j] == a[index][j]) {
                return 0;
            }
        }
    }
    
    return 1;
}

int verificaColonne(int size, int a[][size]) {
    for(int i = 0; i < size; i++) {
        for(int index = 1; index < size; index++) {
            if(a[i][0] == a[i][index]) {
                return 0;
            }
        }
    }
    
    return 1;
}