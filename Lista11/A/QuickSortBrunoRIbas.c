#include <stdio.h>
#include <stdlib.h>

#define exchange(a, b) \
    {                   \
        int t = a;      \
        a = b;          \
        b = t;          \
    }

#define cmpexch(a, b) \
    if (a > b)             \
    {                      \
        int t = a;         \
        a = b;             \
        b = t;             \
    }

// Função auxiliar para dividir a lista em duas sublistas, usando o primeiro elemento como pivot
int separa(int *v, int l, int r)
{
    int pivo = v[r]; // pivo
    int i = l - 1;   // índice do menor elemento
    int j = r;       // índice do maior elemento

    for (;;)
    {
        while (v[++i] < pivo)
            ; // procura elemento maior que o pivo
        while (v[--j] > pivo)
            ; // procura elemento menor que o pivo
        if (j == l)
            break; // se os índices se cruzarem, para
        if (i >= j)
            break;    // se os índices se cruzarem, para
        int t = v[i]; // troca os elementos
        v[i] = v[j];
        v[j] = t;
    }
    int t = v[i]; // troca o pivo com o elemento maior
    v[i] = v[r];
    v[r] = t;

    return i;
}

// Função de ordenação rápida
// void quick_sort(int *v, int l, int r)
// {
//     if (l >= r)
//         return; // se a lista tiver um elemento, não precisa ordenar

//     int j = separa(v, l, r);
//     quick_sort(v, l, j - 1);
//     quick_sort(v, j + 1, r);
// }

void quick_sort(int *v, int l, int r)
{
    quick_sortM3(v, l, r);
    insertion_sort(v, l, r);
}

// Função de ordenação rápida
void quick_sortM3(int *v, int l, int r)
{
    if (r-l+1 <= 16)
        return; // se a lista tiver um elemento, não precisa ordenar

    exchange(v[(l + r) / 2], v[r - 1]);
    cmpexch(v[l], v[r]);
    cmpexch(v[l], v[r - 1]);
    cmpexch(v[r-1], v[r]);

    int j = separa(v, l+1, r-1);
    quick_sortM3(v, l, j - 1);
    quick_sortM3(v, j + 1, r);
}

int main()
{

    int v[100000];
    int i = 0, quantidade;

    scanf("%d", &quantidade);
    while (i < quantidade)
    {
        scanf("%d", &v[i]);
        i++;
    }

    quick_sortM3(v, 0, quantidade - 1);

    for (int e = 0; e < quantidade; e++)
    {
        printf("%d ", v[e]);
    }

    printf("\n");
    return 0;
}
