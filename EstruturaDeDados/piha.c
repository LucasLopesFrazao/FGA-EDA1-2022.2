#include <stdio.h>
#include <stdlib.h>

#define MAXTAM 10000

typedef struct
{
    int item[MAXTAM];
    int topo;
} Pilha;

void pilha_inicia(Pilha *pilha)
{
    pilha->topo = -1;
}

int pilha_vazia(Pilha *pilha)
{
    if (pilha->topo == -1)
        return 1;
    else
        return 0;
}

int pilha_cheia(Pilha *pilha)
{
    if (pilha->topo == MAXTAM - 1)
        return 1;
    else
        return 0;
}

void pilha_insere(Pilha *pilha, int x)
{
    if (pilha_cheia(pilha))
    {
        printf("Pilha cheia");
    }
    else
    {
        pilha->topo++;
        pilha->item[pilha->topo] = x;
    }
}

int pilha_retira(Pilha *pilha)
{
    int aux;
    if (pilha_vazia(pilha))
    {
        printf("Pilha vazia");
    }
    else
    {
        aux = pilha->item[pilha->topo];
        pilha->topo--;
        return aux;
    }
}

void pilha_print(Pilha *pilha)
{
    if (pilha_vazia(pilha))
    {
        return;
    }
    int x = pilha_retira(pilha);
    printf("%d ", x);
    pilha_print(pilha);
    pilha_insere(pilha, x);
}

int main()
{
    Pilha *p = (Pilha *)malloc(sizeof(Pilha));
    pilha_inicia(p);

    pilha_insere(p, 2);
    pilha_insere(p, 3);
    pilha_insere(p, 5);

    pilha_print(p);
    printf("\n");
    printf("Removi: %d\n", pilha_retira(p));
    pilha_print(p);
    printf("\n");
    printf("\n");

    pilha_insere(p, 7);
    pilha_insere(p, 11);
    pilha_insere(p, 13);

    pilha_print(p);
    printf("\n");
    printf("Removi: %d\n", pilha_retira(p));
    pilha_print(p);
    printf("\n");
    printf("\n");
}