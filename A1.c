#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

typedef struct
{
    int num_linea;
    int cant_palabras;
    int cant_signos;
} Registro;

int esPuntuacion(char c)
{
    char signos[] = ".,;:?!()[]{}\"\'";
    for (int i = 0; signos[i] != '\0'; i++)
    {
        if (c == signos[i])
            return 1;
    }
    return 0;
}

int main()
{
    FILE *f_texto = fopen("palabras.txt", "r");
    FILE *f_bin = fopen("contador.dat", "wb");

    if (!f_texto)
    {
        printf("Error: No se pudo abrir palabras.txt\n");
        return 1;
    }
    if (!f_bin)
    {
        printf("Error: No se pudo crear contador.dat\n");
        fclose(f_texto);
        return 1;
    }

    char linea[256];
    int num_linea = 0;

    while (fgets(linea, sizeof(linea), f_texto))
    {
        num_linea++;

        Registro reg;
        reg.num_linea = num_linea;
        reg.cant_palabras = 0;
        reg.cant_signos = 0;

        int en_palabra = 0;

        for (int i = 0; linea[i] != '\0'; i++)
        {

            if (esPuntuacion(linea[i]))
            {
                reg.cant_signos++;
            }

            if (isspace(linea[i]))
            {
                if (en_palabra)
                {
                    reg.cant_palabras++;
                    en_palabra = 0;
                }
            }
            else if (isalnum(linea[i]))
            {
                if (!en_palabra)
                    en_palabra = 1;
            }
        }

        if (en_palabra)
            reg.cant_palabras++;

        fwrite(&reg, sizeof(Registro), 1, f_bin);
    }

    fclose(f_texto);
    fclose(f_bin);

    printf("Proceso completado. Datos guardados en contador.dat\n");

    return 0;
}

//LUCAS ANDRES ESCUDERO - UTN-FRLR - INFORMATICA II