#include <stdlib.h>
#include <stdio.h>


//Dado un vector de 10 elementos escribir un programa en C (haciendo uso de punteros) que muestre el valor de cada elemento del vector y su posición de

int main() {
    system("clear");

    int vector[10] = {5, 12, 7, 3, 9, 15, 21, 8, 6, 10};
    int *ptr = vector; // Puntero que apunta al inicio del vector

    printf("Elementos del vector y sus posiciones:\n\n");
    for(int i = 0; i < 10; i++) {
        printf("Posición %d: Valor %d\n", i, *(ptr + i));
    }

    printf("\n");

    return 0;
}