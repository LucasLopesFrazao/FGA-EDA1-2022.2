#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

#define MAXTAM 100

typedef struct
{
    int item[MAXTAM];
    int fim;
} Fila;

int fila_vazia(Fila *fila)
{
    if (fila->fim == 0)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

void fila_inicia(Fila *fila)
{
    for (int i = 0; i < MAXTAM; i++)
        fila->item[i] = 0;
    fila->fim = 0;
}

void fila_insere(Fila *fila, int x)
{
    if (fila->fim == MAXTAM)
    {
        printf("Fila cheia\n");
        return;
    }
    else
    {
        fila->item[fila->fim] = x;
        fila->fim++;
    }
}

int fila_retira(Fila *fila)
{
    int aux;
    if (fila->fim == 0)
    {
        printf("Fila vazia\n");
        return -1;
    }
    else
    {
        aux = fila->item[0];
        for (int i = 0; i < fila->fim; i++)
            fila->item[i] = fila->item[i + 1];
        fila->fim--;
        return aux;
    }
}

void fila_imprime(Fila *fila)
{
    if(fila_vazia(fila))
    {
        printf("Fila vazia\n");
        return;
    }
    for (int i = 0; i < fila->fim; i++)
        printf("%d ", fila->item[i]);
    printf("\n");
}

void fila_imprime_recursivo(Fila *fila, int i)
{
    if (i == fila->fim)
    {
        return;
    }
    printf("%d ", fila->item[i]);
    fila_imprime_recursivo(fila, i + 1);
}

void fila_imprime_recursao(Fila *fila)
{
    fila_imprime_recursivo(fila, 0);
    printf("\n");
}

void fila_tamanho(Fila *fila)
{
    printf("Tamanho da fila: %d\n", fila->fim);
}

void fila_imprime_inversa_recursivo(Fila *fila, int i)
{
    if (i < 0)
    {
        return;
    }
    printf("%d ", fila->item[i]);
    fila_imprime_inversa_recursivo(fila, i - 1);
}

void fila_imprime_inversa_recursao(Fila *fila)
{
    fila_imprime_inversa_recursivo(fila, fila->fim - 1);
    printf("\n");
}

int main()
{
    Fila fila;
    fila_inicia(&fila);
    fila_imprime(&fila);
    fila_insere(&fila, 41);
    fila_insere(&fila, 25);
    fila_insere(&fila, 74);
    fila_insere(&fila, 196);

    fila_imprime(&fila);
    fila_retira(&fila);
    fila_imprime_recursao(&fila);
    fila_tamanho(&fila);
    fila_imprime_inversa_recursao(&fila);
}