#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Pilha
{
    int top;
    char **palavra;
};

void empilha(struct Pilha *pilha, char *palavra)
{
    pilha->top++;
    pilha->palavra[pilha->top] = malloc((strlen(palavra) + 1) * sizeof(char));
    strcpy(pilha->palavra[pilha->top], palavra);
}

void desempilha(struct Pilha *pilha)
{
    free(pilha->palavra[pilha->top]);
    pilha->top--;
}

int main()
{
    char str[4194304];
    struct Pilha palavras;
    palavras.top = -1;
    palavras.palavra = malloc(100000 * sizeof(char *));

    while (scanf("%s", str) != EOF)
    {
        empilha(&palavras, str);
    }

    char *ultimaStr = palavras.palavra[palavras.top];
    for (int i = 0; i <= palavras.top - 1; i++)
    {
        int cont = 0;
        char *ptr = palavras.palavra[i];
        //conta quantas ocorrencias a ultima string tem em cada palavra
        while ((ptr = strstr(ptr, ultimaStr)) != NULL)
        {
            cont++;
            //move o ponteiro para o fim da ocorrência
            ptr += strlen(ultimaStr);
        }

        printf("%d\n", cont);
    }

    for (int i = 0; i <= palavras.top; i++)
    {
        free(palavras.palavra[i]);
    }
    free(palavras.palavra);

    return 0;
}
