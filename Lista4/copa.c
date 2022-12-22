#include <stdio.h>

int main()
{

    int qtdTimes, qtdJogos, pontos;
    char times[10];

    while (scanf("%d %d", &qtdTimes, &qtdJogos))
    {
        int pontuacao = 0;
        int empates = 0, maiorPossivel = 0, menorPossivel = 0, grandeza = 0, valor = 0;

        if (qtdTimes == 0)
        {
            return 0;
        }

        for (int i = 0; i < qtdTimes; i++)
        {
            scanf("%s %d", times, &pontos);
            pontuacao += pontos;
        }

        maiorPossivel = 3 * qtdJogos;
        menorPossivel = 2 * qtdJogos;

        grandeza = maiorPossivel - menorPossivel;

        for (int i = maiorPossivel; i >= menorPossivel; i--)
        {
            if (i == pontuacao)
            {
                printf("%d\n", valor);
                break;
            }
            valor++;

        }
    }

    return 0;
}