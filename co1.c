#include <stdlib.h>
#include <stdio.h>
#define n 10

int cola[n] = {0};
int *ptr = cola; // Puntero que apunta al inicio del vector

int obtenerTamanoActual(int *ptr, int maximo) {
    int tamano = 0;
    for (int i = 0; i < maximo; i++) {
        if (*(ptr + i) != 0) {
            tamano++;
        }
    }
    return tamano;
}

void sumarElementos(int *ptr, int maximo) {
    int sumatoria = 0;
    printf("\nSumatoria de %d numero/s es: (", obtenerTamanoActual(ptr, n));
    for (int i = 0; i < obtenerTamanoActual(ptr, n); i++) {
        if (i == 0) {
            printf("%d", *(ptr + i));
            sumatoria += *(ptr + i);
        } else {
            printf(" + %d", *(ptr + i));
            sumatoria += *(ptr + i);
        }
    }
    printf(") = %d\n", sumatoria);  
}

int main() {
    system("clear");
    printf("Ingrese los valores para un vector de 10 elementos:\n\n");

    for(int i = 0; i < n; i++) {
        printf("Ingrese el valor para la posicion %d: ", i);
        scanf("%d", ptr + i);
    }

    system("clear");
    printf("Sumatoria y eliminación de elementos del vector:\n");


    for(int i = n; i > 0; i--) {
        sumarElementos(ptr, n);
        *(ptr + i - 1) = 0; // Elimina el último elemento ingresado
    }


    printf("\n");

    return 0;
}