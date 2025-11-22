#include <stdio.h>
#include <stdlib.h>

void burbuja(int v[], int n)
{
    if (n == 1)
        return;
        
    for (int i = 0; i < n - 1; i++)
    {
        if (v[i] > v[i + 1])
        {
            int temp = v[i];
            v[i] = v[i + 1];
            v[i + 1] = temp;
        }
    }
    burbuja(v, n - 1);
}

int main()
{
    int v[] = {5, 1, 9, 3, 2};
    int n = sizeof(v) / sizeof(v[0]);

    burbuja(v, n);

    printf("Vector ordenado:\n");
    for (int i = 0; i < n; i++)
        printf("%d ", v[i]);

    return 0;
}
