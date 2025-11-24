#include <stdio.h>
#define SIZE 3

int main()
{
    double A[SIZE][SIZE];
    double B[SIZE][SIZE];
    double C[SIZE][SIZE];
    int i, j, k;

    printf("Introduce los datos de la primera matriz (A):\n");
    for (i = 0; i < SIZE; i++)
    {
        for (j = 0; j < SIZE; j++)
        {
            printf("Elemento A(%d,%d): ", i + 1, j + 1);
            scanf("%lf", &A[i][j]);
        }
    }

    printf("\nIntroduce los datos de la segunda matriz (B):\n");
    for (i = 0; i < SIZE; i++)
    {
        for (j = 0; j < SIZE; j++)
        {
            printf("Elemento B(%d,%d): ", i + 1, j + 1);
            scanf("%lf", &B[i][j]);
        }
    }

    // Multiplicación de matrices C = A * B
    for (i = 0; i < SIZE; i++)
    {
        for (j = 0; j < SIZE; j++)
        {
            C[i][j] = 0;
            for (k = 0; k < SIZE; k++)
            {
                C[i][j] += A[i][k] * B[k][j];
            }
        }
    }

    printf("\nLa matriz resultado C = A * B es:\n");
    for (i = 0; i < SIZE; i++)
    {
        for (j = 0; j < SIZE; j++)
        {
            printf("%lf ", C[i][j]);
        }
        printf("\n");
    }

    return 0;
}


//LUCAS ANDRES ESCUDERO - UTN-FRLR - INFORMATICA II