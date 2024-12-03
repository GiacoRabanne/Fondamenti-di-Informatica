#include <stdio.h>

int distinti (int a[], int size);

int main() {
	int size;
	printf("> Inserisci la dimensione della sequenza: ");
	scanf("%d", &size);

	int a[size];
	for(int i = 0; i < size; i++) {
		printf("> Elemento in posizione %d: ", i);
		scanf("%d", (a+i));
	}
	
	printf("\n\n");
	if(distinti(a, size)) {
		printf("> La sequenza è composta da elementi tutti distinti.");
	} else {
		printf("> La sequenza NON è composta da elementi distinti.");
	}
	printf("\n");
	
}


int distinti (int a[], int size) {
	int distinti = 1;
	for(int i = 0; i < size && distinti; i++) {
		for(int j = i+1; j < size && distinti; j++) {
			if(a[i] == a[j]) {
				distinti = 0;
			}
		}
	}

	return distinti;
}