#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#define n 30

char cadena[n];
char cadenaMayus[n];
char cadenaSinEspacios[n];

int a = 0;
int e = 0;
int i = 0;
int o = 0;
int u = 0;

int main(){
    system("clear");
    printf("Ingrese una cadena de texto: ");
    fgets(cadena, sizeof(cadena), stdin);

    for(int j = 0; j < strlen(cadena); j++){
        switch(cadena[j]){
            case 'a':
            case 'A':
                a++;
                break;
            case 'e':
            case 'E':
                e++;
                break;
            case 'i':
            case 'I':
                i++;
                break;
            case 'o':
            case 'O':
                o++;
                break;
            case 'u':
            case 'U':
                u++;
                break;
        }
    
        cadenaMayus[j] = toupper(cadena[j]);

        if(cadena[j] != ' ' && cadena[j] != '\n'){
            cadenaSinEspacios[strlen(cadenaSinEspacios)] = cadena[j];
        }

    }

    printf("\nCantidad de vocales:\n");
    printf("A/a: %d\n", a);
    printf("E/e: %d\n", e);
    printf("I/i: %d\n", i);
    printf("O/o: %d\n", o);
    printf("U/u: %d\n", u);

    printf("\nLa cadena en mayusculas es: %s\n", cadenaMayus);

    printf("La cadena sin espacios es: %s\n", cadenaSinEspacios);


    return 0;
}

//LUCAS ANDRES ESCUDERO - UTN-FRLR - INFORMATICA II