#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct
{
    char character;
    int lenght;
    int position;
} Item;

void merge(Item *v, int start, int end, int mid)
{
    Item *v2 = malloc(sizeof(Item) * (end - start + 1));
    int i = start;
    int j = mid + 1;
    int k = 0;

    while (i <= mid && j <= end)
    {
        if (v[i].lenght >= v[j].lenght)
        {
            v2[k++] = v[i++];
        }
        else
        {
            v2[k++] = v[j++];
        }
    }

    while (i <= mid)
    {
        v2[k++] = v[i++];
    }
    while (j <= end)
    {
        v2[k++] = v[j++];
    }

    k = 0;
    for(i = start; i <= end; i++)
    {
        v[i] = v2[k++];
    }

    free(v2);
}

void mergeSort(Item *vetor, int start, int end)
{
    if(start >= end) return;
    int mid = (start + end) / 2;
    mergeSort(vetor, start, mid);
    mergeSort(vetor, mid + 1, end);
    merge(vetor, start, end, mid);
}

int main(void)
{
    Item bebidas[100000];
    char leitura[100001];
    int aux = 0;
    
    scanf("%s", leitura);

    int lenght = strlen(leitura);
    for (int i = 0; i < lenght; i++)
    {

        bebidas[aux].character = leitura[i];
        bebidas[aux].position = i;

        while (leitura[i] == bebidas[aux].character)
        {
            bebidas[aux].lenght++;
            i++;
        }
        i--;
        aux++;
    }

    mergeSort(bebidas, 0, aux - 1);

    for (int j = 0; j < aux; j++)
    {
        printf("%d %c %d\n", bebidas[j].lenght, bebidas[j].character, bebidas[j].position);
    }

    return 0;
}