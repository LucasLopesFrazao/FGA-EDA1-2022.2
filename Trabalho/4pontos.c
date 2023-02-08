#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct no
{
    char frase[100];
    struct no *prox;
} no;
typedef struct pilha
{
    no *topo;
} pilha;
void inicializa_pilha_dinamica(pilha *p)
{
    p->topo = NULL;
}
void adiciona_pilha_dinamica(pilha *p, char frase[100])
{
    no *novo = (no *)malloc(sizeof(no));
    strcpy(novo->frase, frase);
    novo->prox = p->topo;
    p->topo = novo;
}
void imprime_pilha_dinamica(pilha *p)
{
    if (p->topo == NULL)
    {
        printf("Pilha vazia!");
        return;
    }
    no *aux = p->topo;
    while (aux != NULL)
    {
        printf("%s ", aux->frase);
        aux = aux->prox;
    }
    printf("\n");
}
char *remove_pilha_dinamica(pilha *p)
{
    no *remover = p->topo;
    p->topo = remover->prox;
    char *removido = (char *)malloc(strlen(remover->frase) + 1);
    strcpy(removido, remover->frase);
    free(remover);
    return removido;
}
int main()
{
    pilha p;
    inicializa_pilha_dinamica(&p);
    char frase[100];
    while (scanf("%s", frase) != EOF)
    {
        if (strcmp(frase, "inserir") == 0)
        {
            scanf("%[^\n]", frase);
            memmove(frase, frase + 1, strlen(frase));
            adiciona_pilha_dinamica(&p, frase);
        }
        else if (strcmp(frase, "desfazer") == 0)
        {
            if (p.topo == NULL)
            {
                printf("NULL\n");
            }
            else
            {
                printf("%s\n", remove_pilha_dinamica(&p));
            }
        }
    }
    return 0;
}
