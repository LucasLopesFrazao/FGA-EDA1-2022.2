#include <stdio.h>
#include <string.h>
#include <ctype.h>

void buffer(void)
{
    int c = 0;
    while ((c = getchar()) != '\n' && c != EOF)
    {
    }
    return;
}

int main(void)
{
    int qtdLinhas, l, tam = 0;
    scanf("%d", &qtdLinhas);
    char frases[qtdLinhas][1000];
    buffer();

    for (l = 0; l < qtdLinhas; l++)
    {
        scanf("%1000[^\n]", frases[l]);
        buffer();
    }

    int linha, coluna, temLetra = 0, i, j;
    char acao;
    scanf("%d %d", &linha, &coluna);
    coluna--;
    linha--;

    buffer();
    while (scanf("%c", &acao) == 1)
    {
        if (acao == 'j')
        {

            linha++;
            if (linha > (qtdLinhas - 1))
            {
                linha--;
                while (frases[linha][tam] != '\0')
                {
                    tam++;
                }
                if (coluna >= tam)
                {
                    tam--;
                    printf("%d %d %c\n", (linha + 1), (tam + 1), frases[linha][tam]);
                }
                else
                {
                    printf("%d %d %c\n", (linha + 1), (coluna + 1), frases[linha][coluna]);
                }

                tam = 0;
            }
            else
            {
                while (frases[linha][tam] != '\0')
                {
                    tam++;
                }
                if (coluna >= tam)
                {
                    tam--;
                    printf("%d %d %c\n", (linha + 1), (tam + 1), frases[linha][tam]);
                }
                else
                {
                    printf("%d %d %c\n", (linha + 1), (coluna + 1), frases[linha][coluna]);
                }

                tam = 0;
            }
        }
        if (acao == 'k')
        {
            linha--;
            if (linha < 0)
            {
                linha++;
                while (frases[linha][tam] != '\0')
                {
                    tam++;
                }
                if (coluna >= tam)
                {
                    tam--;
                    printf("%d %d %c\n", (linha + 1), (tam + 1), frases[linha][tam]);
                }
                else
                {
                    printf("%d %d %c\n", (linha + 1), (coluna + 1), frases[linha][coluna]);
                }
                tam = 0;
            }
            else
            {
                while (frases[linha][tam] != '\0')
                {
                    tam++;
                }
                if (coluna >= tam)
                {
                    tam--;
                    printf("%d %d %c\n", (linha + 1), (tam + 1), frases[linha][tam]);
                }
                else
                {
                    printf("%d %d %c\n", (linha + 1), (coluna + 1), frases[linha][coluna]);
                }
                tam = 0;
            }
        }

        buffer();
    }
    return 0;
}