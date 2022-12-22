#include <stdio.h>
#include <stdlib.h>

#define exch(A, B) \
    Item tt = A;   \
    A = B;         \
    B = tt

typedef struct
{
    int pos;
    int elem;
} Item;

void selectionSort(Item *vetor, int i)
{
    int j, min, k;

    for (j = 0; j < i; j++)
    {
        min = j;
        for (k = j + 1; k < i; k++)
        {
            if (vetor[k].elem < vetor[min].elem)
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

    if (vetor[metade].elem == chave)
    {
        return metade;
    }

    if (vetor[metade].elem < chave)
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
    int i = 0, e = 0;
    int m, n, read;

    scanf("%d %d", &m, &n);
    Item v[m];


    while (i < m)
    {
        scanf("%d", &read);
        v[i].elem = read;
        v[i].pos = i;
        i++;
    }
    
    selectionSort(v, m);

    for (int e = 0; e < n; e++)
    {
        scanf("%d", &read);
        int resultado = binarySearch(v, 0, m, read);
        if(resultado == -1){
            printf("-1\n");
        }else{
            printf("%d\n", v[resultado].pos);
        }
    }
}