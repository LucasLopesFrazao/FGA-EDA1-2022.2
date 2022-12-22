#include <stdio.h>
#include <string.h>

void buffer(void)
{
    int c = 0;
    while ((c = getchar()) != '\n' && c != EOF)
    {
    }
    return;
}

int main()
{

    int altura, i, j, k, largura = 12;
    scanf("%d", &altura);
    altura += 2;
    char jogo[altura][largura];
    int galhos[altura][largura];

    for (i = 0; i < altura; i++)
    {
        for (j = 0; j < largura; j++)
        {
            jogo[i][j] = ' ';
            if (i == (altura - 1) || i == 0)
            {
                jogo[i][j] = '~';
            }
            if ((i <= (altura - 2) && i != 0) && (j >= 4 && j <= 6))
            {
                jogo[i][j] = '|';
            }
            if (j == (largura - 1))
            {
                jogo[i][j] = '\n';
            }
        }
    }

    int qtdGalho, alturaGalho;
    char ladoGalho;

    scanf("%d", &qtdGalho);
    buffer();
    for (int k = 0; k < qtdGalho; k++)
    {
        scanf("%c %d", &ladoGalho, &alturaGalho);
        buffer();
        for (i = 0; i < altura; i++)
        {
            for (j = 0; j < largura; j++)
            {
                if (ladoGalho == 'D')
                {
                    if (j >= 7 && j <= 9)
                    {
                        if (i == (altura - (alturaGalho + 1)))
                        {
                            jogo[i][j] = '-';
                        }
                    }
                }
                if (ladoGalho == 'E')
                {
                    if (j >= 1 && j <= 3)
                    {
                        if (i == (altura - (alturaGalho + 1)))
                        {
                            jogo[i][j] = '-';
                        }
                    }
                }
            }
        }
    }

    char ladoJogador;
    scanf("%c", &ladoJogador);
    for (i = 0; i < altura; i++)
    {
        for (j = 0; j < largura; j++)
        {
            if (ladoJogador == 'E')
            {
                if (i == (altura - 2) || i == (altura - 3))
                {
                    if (j == 2)
                    {
                        jogo[i][j] = 'L';
                    }
                }
            }
            if (ladoJogador == 'D')
            {
                if (i == (altura - 2) || i == (altura - 3))
                {
                    if (j == 8)
                    {
                        jogo[i][j] = 'L';
                    }
                }
            }
        }
    }

    int trocou = 0, contador = 1, l, p, morreu = 0, temGalho = 0;
    char acoes[2000];
    buffer();
    fgets(acoes, 2000, stdin);

    for (i = 0; i < altura; i++)
    {
        for (j = 0; j < largura; j++)
        {
            if (i == (altura - 7) && j <= 10)
            {
                printf("~");
                if (j == 10)
                {
                    printf("\n");
                }
            }
            if (i > (altura - 7))
            {
                printf("%c", jogo[i][j]);
            }
        }
    }

    for (k = 0; k < (strlen(acoes) - 1); k++)
    {
        trocou = 0;
        morreu = 0;
        temGalho = 0;
        for (l = 0; l < altura; l++) // ZERANDO O GALHOS
        {
            for (p = 0; p < largura; p++)
            {
                galhos[l][p] = 0;
            }
        }
        for (i = 0; i < altura; i++)
        {
            for (j = 0; j < largura; j++)
            {
                if (acoes[k] == 'T')
                {
                    if (i == (altura - 2))
                    {
                        if (j == 2)
                        {
                            if (jogo[i][j] == 'L')
                            {
                                if (jogo[i][j + 6] == '-' || jogo[i - 1][j + 6] == '-')
                                {
                                    temGalho = 1;
                                }
                                else
                                {
                                    jogo[i][j] = ' ';
                                    jogo[i - 1][j] = ' ';
                                    jogo[i][j + 6] = 'L';
                                    jogo[i - 1][j + 6] = 'L';
                                    trocou = 1;
                                }
                            }
                        }
                        if (j == 8 && trocou == 0)
                        {
                            if (jogo[i][j] == 'L')
                            {
                                if (jogo[i][j - 6] == '-' || jogo[i - 1][j - 6] == '-')
                                {
                                    temGalho = 1;
                                }
                                else
                                {
                                    jogo[i][j] = ' ';
                                    jogo[i - 1][j] = ' ';
                                    jogo[i][j - 6] = 'L';
                                    jogo[i - 1][j - 6] = 'L';
                                }
                            }
                        }
                    }
                }
                if (acoes[k] == 'B')
                {
                    if (i == (altura - 2))
                    {
                        if (j == 2)
                        {
                            if (jogo[i][j] == 'L')
                            {
                                if (jogo[i][j + 2] == '>')
                                {
                                    jogo[i - ((altura - 2) - contador)][j + 2] = ' ';
                                    jogo[i - ((altura - 2) - contador)][j + 3] = ' ';
                                    jogo[i - ((altura - 2) - contador)][j + 4] = ' ';
                                    jogo[i][j + 2] = '|';
                                    jogo[i][j + 3] = '|';
                                    jogo[i][j + 4] = '|';
                                    contador++;
                                    for (l = 0; l < altura; l++)
                                    {
                                        for (p = 0; p < largura; p++)
                                        {
                                            if (jogo[l][p] == '-')
                                            {
                                                jogo[l][p] = ' ';
                                                galhos[l + 1][p] = 1;
                                            }
                                        }
                                    }
                                    for (l = 0; l < altura; l++)
                                    {
                                        for (p = 0; p < largura; p++)
                                        {
                                            if (galhos[l][p] == 1)
                                            {
                                                if (jogo[l][p] == 'L')
                                                {
                                                    morreu = 1;
                                                }
                                                else
                                                {
                                                    jogo[l][p] = '-';
                                                }
                                            }
                                            if (l == (altura - 1))
                                            {
                                                jogo[l][p] = '~';
                                                if(p == largura-1){
                                                    jogo[l][p] = '\n';
                                                }
                                            }
                                        }
                                    }
                                    break;
                                }
                                if (jogo[i - 1][j + 2] == '|')
                                {
                                    jogo[i][j + 2] = '>';
                                    break;
                                }
                            }
                        }
                        if (j == 8)
                        {
                            if (jogo[i][j] == 'L')
                            {
                                if (jogo[i][j - 2] == '<')
                                {
                                    jogo[i - ((altura - 2) - contador)][j - 2] = ' ';
                                    jogo[i - ((altura - 2) - contador)][j - 3] = ' ';
                                    jogo[i - ((altura - 2) - contador)][j - 4] = ' ';
                                    jogo[i][j - 2] = '|';
                                    jogo[i][j - 3] = '|';
                                    jogo[i][j - 4] = '|';
                                    contador++;
                                    for (l = 0; l < altura; l++)
                                    {
                                        for (p = 0; p < largura; p++)
                                        {
                                            if (jogo[l][p] == '-')
                                            {
                                                jogo[l][p] = ' ';
                                                galhos[l + 1][p] = 1;
                                            }
                                        }
                                    }
                                    for (l = 0; l < altura; l++)
                                    {
                                        for (p = 0; p < largura; p++)
                                        {
                                            if (galhos[l][p] == 1)
                                            {
                                                if (jogo[l][p] == 'L')
                                                {
                                                    morreu = 1;
                                                }
                                                else
                                                {
                                                    jogo[l][p] = '-';
                                                }
                                            }
                                            if (l == (altura - 1))
                                            {
                                                jogo[l][p] = '~';
                                                if(p == largura-1){
                                                    jogo[l][p] = '\n';
                                                }
                                            }
                                        }
                                    }
                                    break;
                                }
                                if (jogo[i - 1][j - 2] == '|')
                                {
                                    jogo[i][j - 2] = '<';
                                    break;
                                }
                            }
                        }
                    }
                }
            }
        }
        if (morreu != 1 && temGalho != 1)
        {
            for (i = 0; i < altura; i++)
            {
                for (j = 0; j < largura; j++)
                {
                    if (i == (altura - 7) && j <= 10)
                    {
                        printf("~");
                        if (j == 10)
                        {
                            printf("\n");
                        }
                    }
                    if (i > (altura - 7))
                    {
                        printf("%c", jogo[i][j]);
                    }
                }
            }
        }
        else if (temGalho == 1)
        {
            printf("**beep**\n");
            continue;
        }
        else
        {
            printf("**morreu**\n");
            break;
        }
    }

    return 0;
}