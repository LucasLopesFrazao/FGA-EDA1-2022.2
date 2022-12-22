#include <stdio.h>
#include <stdlib.h>

int main()
{
    // VARIAVÉIS
    char *time1, *time2;
    int rodadas, i, partidas = 0, time1Gols = 0, time2Gols = 0, t1Partidas, t2Partidas;

    scanf("%d", &rodadas);

    //ALOCAÇÃO DINAMICA DE VETOR
    time1 = malloc((rodadas * sizeof(char)) + 1);
    time2 = malloc((rodadas * sizeof(char)) + 1);

    t1Partidas = rodadas; t2Partidas = rodadas;

    scanf(" %s", time1);
    scanf(" %s", time2);

    for (i = 0; i < rodadas; i++)
    {
        partidas++;
        if (time1[i] == 'o')
        {
            time1Gols++;
        }
        t1Partidas--;
        if (time1Gols + t1Partidas < time2Gols || time2Gols + t2Partidas < time1Gols)
        {
            break;
        }

        partidas++;
        if (time2[i] == 'o')
        {
            time2Gols++;
        }
        t2Partidas--;
        if (time1Gols + t1Partidas < time2Gols || time2Gols + t2Partidas < time1Gols)
        {
            break;
        }
    }

    if (time1Gols == time2Gols)
    {
        printf("Empate\n");
    }
    else
    {
        printf("%d\n", partidas);
    }

   return 0;
}