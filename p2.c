#include <stdlib.h>
#include <stdio.h>
#define n 10

int array[n] = {5, 12, 7, 3, 9, 15, 21, 8, 6, 10};
int *ptr = array; // Puntero que apunta al inicio del vector
int arrayDos[n] = {0};

void copiaArray(int *origen, int *destino, int tamano) {
    for(int i = 0; i < tamano; i++) {
        *(destino + i) = *(origen + i);
    }

    printf("Elementos del array copiado y sus posiciones:\n\n");
    for(int i = 0; i < tamano; i++) {
        printf("Posición %d: Valor %d\n", i, *(destino + i));
    }
}

int main() {

    system("clear");
    
    copiaArray(array, arrayDos, n);

    return 0;
}


//LUCAS ANDRES ESCUDERO - UTN-FRLR - INFORMATICA II