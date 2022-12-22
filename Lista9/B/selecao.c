#include <stdio.h>
#include <stdlib.h>

void selection_sort(int *vetor, int tam)
{
    int minimo;

    for (int i = 0; i < tam - 1; i++)
    {
        minimo = i;
        for (int j = i + 1; j < tam; j++)
        {
            if (vetor[j] < vetor[minimo])
            {
                minimo = j;
            }
        }
        int temp = vetor[minimo];
        vetor[minimo] = vetor[i];
        vetor[i] = temp;
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

    selection_sort(v, i);

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