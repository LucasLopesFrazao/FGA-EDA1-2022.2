#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#define CITY_NAME_SIZE 27
typedef struct item
{
    char *cidade;
    struct item *proximo;
} item;
item *inicializa_fila()
{
    item *p;
    p = malloc(sizeof(item));
    p->proximo = NULL;
    return p;
}
void insere_fila(item *p, char *nomeCidade)
{
    item *novo;
    novo = malloc(sizeof(item));
    novo->cidade = malloc(sizeof(char) * CITY_NAME_SIZE);
    strcpy(novo->cidade, nomeCidade);
    p->proximo = novo;
    novo->proximo = NULL;
}
item *todas_cidades(item *ptr)
{
    char nomeCidade[CITY_NAME_SIZE];
    while (scanf(" %s", nomeCidade) != EOF)
    {
        insere_fila(ptr, nomeCidade);
        ptr = ptr->proximo;
    }
    return ptr;
}
item *comeco_fila(item *p, item *u)
{
    u->proximo = p->proximo;
    p->proximo = p->proximo->proximo;
    u->proximo->proximo = NULL;
    return u->proximo;
}
void swap(item *shows, item *ultimo)
{
    item *p = shows;
    while (p != NULL)
    {
        printf("%s\n", p->cidade);
        if (p->proximo == NULL)
        {
            break;
        }
        if (tolower(p->proximo->cidade[0]) == tolower(p->cidade[strlen(p->cidade) - 1]))
        {
            ultimo = comeco_fila(p, ultimo);
        }
        p = p->proximo;
    }
}
int main()
{
    item *turnes;
    item *ultimo;
    turnes = inicializa_fila();
    ultimo = todas_cidades(turnes);
    swap(turnes->proximo, ultimo);
    return 0;
}
