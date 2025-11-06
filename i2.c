#include <stdlib.h>
#include <stdio.h>
#define n 10 

int main() {
    system("clear");
    printf("Suma de impares!\n \n");

    printf("La sumatoria es: (");

    int sumatoria = 0;

    for(int i = 0; i <= n; i++){

        if(i == 1) {
                printf("%d", i);
                sumatoria += i;
        } else if(i % 2 != 0) {
                printf(" + %d", i);
                sumatoria += i;
        }
        
    }

    printf(") \n \nLa suma de los numeros impares es: %d\n", sumatoria);

    return 0;
}