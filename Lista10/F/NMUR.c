#include <stdio.h>
#include <stdlib.h>

void merge(int *vetor, int i, int f, int m)
{
    int vetorAux[f - i + 1];
    int Ai = i, Bi = m + 1, AUXi = 0, p;

    while (Ai <= m && Bi <= f)
    {
        if (vetor[Ai] <= vetor[Bi])
        {
            vetorAux[AUXi++] = vetor[Ai++];
        }
        else
        {
            vetorAux[AUXi++] = vetor[Bi++];
        }
    }

    while (Ai <= m)
    {
        vetorAux[AUXi++] = vetor[Ai++];
    }
    while (Bi <= f)
    {
        vetorAux[AUXi++] = vetor[Bi++];
    }

    int v = 0;
    for (p = i; p <= f; ++p)
    {
        vetor[p] = vetorAux[v++];
    }
}

void mergeSort(int *vetor, int i, int j)
{
    if (i >= j)
        return;

    int meio = i + (j - i) / 2;
    mergeSort(vetor, i, meio);
    mergeSort(vetor, meio + 1, j);
    merge(vetor, i, j, meio);
}

int searchNumber(int *vetor, int search, int len)
{
    int i;
    for (i = 0; i < len; i++)
    {
        if (vetor[i] == search)
            return i;
    }
    return -1;
}

void removeRep(int *vetor, int f, int i)
{
    int vetAux[f - i + 1], p, auxI = 0, h, k;

    for (p = 0; p <= f; p++)
    {
        if (p == 0)
            vetAux[auxI++] = vetor[p];

        if (searchNumber(vetAux, vetor[p], auxI) == -1)
            vetAux[auxI++] = vetor[p];
    }

    for (h = 0; h < f - 1; h++)
    {
        vetor[h] = vetAux[h];
    }
}

int main()
{
    int i, tam;
    int *vetor;

    scanf("%d", &tam);
    vetor = (int *)malloc(tam * sizeof(int));

    for (i = 0; i < tam; i++)
    {
        scanf("%d", &vetor[i]);
    }

    mergeSort(vetor, 0, tam - 1);
    removeRep(vetor, tam - 1, 0);

    return 0;
}