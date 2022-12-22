#include <stdio.h>
#include <string.h>
#define exch(A, B) \
    Item tt = A;   \
    A = B;         \
    B = tt

typedef struct
{
    int num;
    char nome[16];
} Item;

void selectionSort(Item *vetor, int i)
{
    int j, min, k;

    for (j = 0; j < i; j++)
    {
        min = j;
        for (k = j + 1; k < i; k++)
        {
            if (vetor[k].num < vetor[min].num)
            {
                min = k;
            }
        }
        exch(vetor[j], vetor[min]);
    }
}

int binarySearch(Item *vetor, int comeco, int fim, int chave)
{
    int metade = (comeco + fim) / 2;

    if (comeco > fim)
    {
        return -1;
    }

    if (vetor[metade].num == chave)
    {
        return metade;
    }

    if (vetor[metade].num < chave)
    {
        return binarySearch(vetor, metade + 1, fim, chave);
    }
    else
    {
        return binarySearch(vetor, comeco, metade - 1, chave);
    }
}

int main()
{
    int n, numero, i = 0, read;
    char texto[16];

    scanf("%d", &n);
    Item v[n];

    while (i < n)
    {
        scanf("%d %s", &numero, texto);
        v[i].num = numero;
        strcpy(v[i].nome, texto);
        i++;
    }

    selectionSort(v, n);

    while (scanf("%d", &read) != EOF)
    {
        int resultado = binarySearch(v, 0, n, read);

        if (resultado == -1)
        {
            printf("undefined\n");
        }
        else
        {
            printf("%s\n", v[resultado].nome);
        }
    }

    return 0;
}