#include <stdio.h>
#include <stdlib.h>

void bubble_sort(int *vetor, int tam)
{
    int aux;

    for (int k = 0; k < tam - 1; k++)
    {
        for (int i = 0; i < tam - k - 1; i++)
        {
            if (vetor[i] > vetor[i + 1])
            {
                aux = vetor[i];
                vetor[i] = vetor[i + 1];
                vetor[i + 1] = aux;
            }
        }
    }
}

int main()
{

    int *v = NULL;
    int i = 0, n;

    while (scanf("%d", &n) != EOF)
    {
        v = realloc(v, (i + 1) * 4);
        v[i] = n;
        i++;
    }

    bubble_sort(v, i);

    for (int e = 0; e < i; e++)
    {
        if (e == (i - 1))
        {
            printf("%d\n", v[e]);
        }
        else
        {
            printf("%d ", v[e]);
        }
    }
}