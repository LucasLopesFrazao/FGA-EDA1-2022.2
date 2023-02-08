#include <stdio.h>
#include <stdlib.h>

char pilha[100001];
int top = -1;

void empilha(char c)
{
    pilha[++top] = c;
}

void desempilha()
{
    top--;
}

char espia()
{
    return pilha[top];
}

int pilhavazia()
{
    return top == -1;
}

int main()
{
    int N;
    char linha[100001];

    scanf("%d", &N);

    for (int i = 0; i < N; i++)
    {
        scanf(" %[^\n]s", linha);
        // limpando buffer
        getchar();

        int comprimento_linha = strlen(linha);
        for (int j = 0; j < comprimento_linha; j++)
        {
            if (linha[j] == espia())
            {
                desempilha();
            }
            else if (linha[j] == '*' || linha[j] == '/' || linha[j] == '_')
            {
                empilha(linha[j]);
            }
        }
    }

    printf(pilhavazia() ? "C\n" : "E\n");

    return 0;
}
