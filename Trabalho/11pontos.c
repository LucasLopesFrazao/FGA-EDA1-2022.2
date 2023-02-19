#include <stdio.h>

int area_visivel = 0;

void mostrar_area_visivel(int linha_torre, int coluna_torre, int visibilidade, int l, int c, char terreno[l][c])
{
    // linha_torre e coluna_torre == coordenadas da torre na matriz
    for (int i = linha_torre - visibilidade; i <= linha_torre + visibilidade; i++)
    {
        for (int j = coluna_torre - visibilidade; j <= coluna_torre + visibilidade; j++)
        {
            if (i >= 0 && i < l && j >= 0 && j < c)
            {
                if (terreno[i][j] == '#')
                {
                    terreno[i][j] = '.';
                    area_visivel++;
                }
            }
        }
    }
}

int main(void)
{
    int linha, coluna;
    scanf("%d %d", &linha, &coluna);
    char terreno[linha][coluna];

    for (int i = 0; i < linha; i++)
    {
        for (int j = 0; j < coluna; j++)
        {
            scanf(" %c", &terreno[i][j]);
        }
    }

    for (int j = 0; j < linha; j++)
    {
        for (int k = 0; k < coluna; k++)
        {
            if (terreno[j][k] == 't')
            {
                int visibilidade;
                scanf("%d", &visibilidade);
                mostrar_area_visivel(j, k, visibilidade, linha, coluna, terreno);
            }
        }
    }

    printf("%d\n", area_visivel);

    for (int i = 0; i < linha; i++)
    {
        for (int j = 0; j < coluna; j++)
        {
            printf("%c", terreno[i][j]);
        }
        printf("\n");
    }

    return 0;
}