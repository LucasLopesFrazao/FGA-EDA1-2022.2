#include <stdio.h>
#include <stdlib.h>

int placas[1000000];
int tamanho = 0;

void merge(int inicio, int meio, int fim)
{
    int i, j, k;
    int n1 = meio - inicio + 1;
    int n2 = fim - meio;
    int esquerda[n1], direita[n2];
    for (i = 0; i < n1; i++)
        esquerda[i] = placas[inicio + i];
    for (j = 0; j < n2; j++)
        direita[j] = placas[meio + 1 + j];
    i = 0;
    j = 0;
    k = inicio;
    while (i < n1 && j < n2)
    {
        if (esquerda[i] <= direita[j])
        {
            placas[k] = esquerda[i];
            i++;
        }
        else
        {
            placas[k] = direita[j];
            j++;
        }
        k++;
    }
    while (i < n1)
    {
        placas[k] = esquerda[i];
        i++;
        k++;
    }
    while (j < n2)
    {
        placas[k] = direita[j];
        j++;
        k++;
    }
}

void mergeSort(int inicio, int fim)
{
    if (inicio < fim)
    {
        int meio = inicio + (fim - inicio) / 2;
        mergeSort(inicio, meio);
        mergeSort(meio + 1, fim);
        merge(inicio, meio, fim);
    }
}

void adiciona_placa(int p)
{
    if (tamanho < 100)
    {
        placas[tamanho] = p;
        tamanho++;
        if (p < placas[tamanho-2])
        {
            mergeSort(0, tamanho - 1);
        }
    }
    else if (p < placas[99])
    {
        placas[99] = p;
        mergeSort(0, 99);
    }
}


int main()
{
    int o, placa, total;
    while (scanf("%d", &o) > 0)
    {
        if (o == 1)
        {
            scanf("%d", &placa);
            adiciona_placa(placa);
        }
        else
        {
            scanf("%d", &total);
            int i;
            for (i = 0; i < total; i++)
                printf("%d ", placas[i]);
            printf("\n");
        }
    }
    return 0;
}
