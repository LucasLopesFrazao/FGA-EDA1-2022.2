#include <stdio.h>
#include <stdlib.h>

void insertion_sort(int *vetor, int tam)
{
    for (int i = 0; i < tam; i++)
    {
        int temp = vetor[i];
        int j = i;
        while (j > 0 && temp < vetor[j - 1])
        {
            vetor[j] = vetor[j - 1];
            j = j - 1;
        }
        vetor[j] = temp;
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

    insertion_sort(v, i);

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