#include <stdio.h>
#include <string.h>


void aBinario(int num, char bin[])
{
    for (int i = 7; i >= 0; i--)
    {
        bin[i] = (num % 2) + '0';
        num /= 2;
    }
    bin[8] = '\0';
}


char paridadImpar(const char bin[])
{
    int count = 0;

    for (int i = 0; i < 8; i++)
    {
        if (bin[i] == '1')
            count++;
    }
    return (count % 2 == 0) ? '1' : '0';
}

int main()
{
    char palabra[50];
    char bin[9];

    printf("Ingrese una palabra: ");
    scanf("%s", palabra);

    printf("\nSecuencia de bits a transmitir (8 bits + paridad impar):\n\n");

    for (int i = 0; i < strlen(palabra); i++)
    {
        int ascii = (int)palabra[i];


        aBinario(ascii, bin);

        char p = paridadImpar(bin);

        
        printf("Caracter '%c' ASCII(%d): %s | Paridad: %c → %s%c\n",
               palabra[i], ascii, bin, p, bin, p);
    }

    return 0;
}
