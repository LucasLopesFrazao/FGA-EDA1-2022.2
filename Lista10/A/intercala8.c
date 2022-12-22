#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int vetor[1600006];

void merge(int *vetor, int inicio, int fim, int meio)
{
    int aux[fim - inicio + 1];
    int Ai = inicio, Bi = meio + 1, auxi = 0, p;

    while (Ai <= meio && Bi <= fim)
    {
        if (vetor[Ai] <= vetor[Bi])
        {
            aux[auxi++] = vetor[Ai++];
        }
        else
        {
            aux[auxi++] = vetor[Bi++];
        }
    }

    while (Ai <= meio)
    {
        aux[auxi++] = vetor[Ai++];
    }
    while (Bi <= fim)
    {
        aux[auxi++] = vetor[Bi++];
    }

    int v = 0;
    for (p = inicio; p <= fim; ++p)
    {
        vetor[p] = aux[v++];
    }
}

int main()
{

    int read, tamanho = 0;
    for (int i = 0; i < 8; ++i)
    {
        scanf("%d", &read);
        if (read == 0)
            continue;
        for (int j = 0; j < read; ++j)
            scanf("%d", &vetor[tamanho + j]);
        merge(&vetor[0], 0, tamanho + read - 1, tamanho - 1);
        tamanho += read;
    }

    printf("%d", vetor[0]);
    for (int i = 1; i < tamanho; ++i)
        printf(" %d", vetor[i]);
    printf("\n");
    return 0;
}