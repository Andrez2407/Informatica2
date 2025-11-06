#include <stdlib.h>
#include <stdio.h>

//Realizar una función, en el cual se ingresa un número entero de varias cifras y un entero con una posición yl se retorna el digito de dicha posición.

int main() {
    system("clear");

    int numero, posicion, digito, i;
    printf("Ingrese un numero entero: ");
    scanf("%d", &numero);
    printf("Ingrese la posicion del digito que desea obtener (0 para el ultimo digito): ");
    scanf("%d", &posicion);

    digito = numero;
    for(i = 0; i < posicion; i++) {
        digito = digito / 10;
    }
    digito = digito % 10;
    printf("El digito en la posicion %d es: %d\n", posicion, digito);
   

    return 0;
}