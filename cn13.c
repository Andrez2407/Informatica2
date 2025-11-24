#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main()
{

  int num, i, esPrimo = 1;

  printf("Ingrese un numero para verificar que sea primo:  ");
  scanf("%d", &num);

    if (num <= 1) {
        esPrimo = 0;
    } else {
        for (i = 2; i <= sqrt(num); i++) {
            if (num % i == 0) {
                esPrimo = 0;
                break;
            }
        }
    }

    if(esPrimo == 1) {
        printf("%d es un numero primo.\n", num);
    } else {
        printf("%d no es un numero primo.\n", num);
    }



}


//LUCAS ANDRES ESCUDERO - UTN-FRLR - INFORMATICA II
