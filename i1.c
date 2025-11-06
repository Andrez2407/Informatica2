#include <stdlib.h>
#include <stdio.h>
#define n 10 

int main() {
    system("clear");
    printf("Calculo de cuadrados !\n \n");
    for(int i = 0; i <= n; i++){
        
        int x = i * i;
        printf("El cuadrado de %d es %d\n", i, x);

    }

    printf("\n");

    return 0;
}