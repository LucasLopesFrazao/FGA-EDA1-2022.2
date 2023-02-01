#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct pilha_st
{
    int topo;
    int capacidade;
    int *v;
} pilha_st;

int inicializar(pilha_st *pilha, int capacidade)
{
    pilha->v = (int *)malloc(capacidade * sizeof(int));
    if (pilha->v == NULL)
        return 0;
    pilha->topo = 0;
    pilha->capacidade = capacidade;
    return 1;
}

int empilha(pilha_st *pilha, int valor)
{
    if (pilha->topo == pilha->capacidade)
        return 0;
    pilha->v[pilha->topo++] = valor;
    return 1;
}

int pilhaVazia(pilha_st *pilha)
{
    return pilha->topo == 0;
}

int topo(pilha_st *pilha)
{
    if (pilhaVazia(pilha))
        return 0;
    return pilha->v[pilha->topo - 1];
}

int desempilha(pilha_st *pilha)
{
    if (pilhaVazia(pilha))
        return 0;
    pilha->topo--;
    return 1;
}

void move_topo_base(pilha_st *pilha)
{
    if (pilha->topo > 0)
    {
        int topo = pilha->v[pilha->topo - 1];
        for (int i = pilha->topo - 1; i > 0; i--)
        {
            pilha->v[i] = pilha->v[i - 1];
        }
        pilha->v[0] = topo;
    }
}

int main(void)
{
    int N;
    scanf("%d", &N);
    pilha_st pilha;
    inicializar(&pilha, N);
    for (int i = N; i > 0; i--)
        empilha(&pilha, i);

    printf("Cartas descartadas: ");
    for (int i = 0; i < N - 2; i++)
    {
        int mao = topo(&pilha);
        printf("%d, ", mao);
        desempilha(&pilha);
        move_topo_base(&pilha);
    }

    int mao = topo(&pilha);
    printf("%d\n", mao);
    desempilha(&pilha);

    printf("Carta restante: %d\n", topo(&pilha));
}
