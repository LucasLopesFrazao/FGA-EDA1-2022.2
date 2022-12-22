#include <stdio.h>

int main()
{

    int jogo1, jogo2;
    int ganhadores[16];
    int ganhadoresOitavas[16];
    int ganhadoresQuartas[16];
    int ganhadoresSemi[16];
    int ganhador[16];

    for (int i = 0; i < 8; i++)
    {
        scanf("%d %d", &jogo1, &jogo2);
        if (i == 0)
        {
            if (jogo1 > jogo2)
            {
                ganhadores[i] = 0;
                ganhadoresOitavas[i] = 'A';
            }
            else
            {
                ganhadores[i] = 1;
                ganhadoresOitavas[i] = 'B';
            }
        }
        if (i == 1)
        {
            if (jogo1 > jogo2)
            {
                ganhadores[i] = 2;
                ganhadoresOitavas[i] = 'C';
            }
            else
            {
                ganhadores[i] = 3;
                ganhadoresOitavas[i] = 'D';
            }
        }
        if (i == 2)
        {
            if (jogo1 > jogo2)
            {
                ganhadores[i] = 5;
                ganhadoresOitavas[i] = 'E';
            }
            else
            {
                ganhadores[i] = 6;
                ganhadoresOitavas[i] = 'F';
            }
        }
        if (i == 3)
        {
            if (jogo1 > jogo2)
            {
                ganhadores[i] = 7;
                ganhadoresOitavas[i] = 'G';
            }
            else
            {
                ganhadores[i] = 8;
                ganhadoresOitavas[i] = 'H';
            }
        }
        if (i == 4)
        {
            if (jogo1 > jogo2)
            {
                ganhadores[i] = 9;
                ganhadoresOitavas[i] = 'I';
            }
            else
            {
                ganhadores[i] = 10;
                ganhadoresOitavas[i] = 'J';
            }
        }
        if (i == 5)
        {
            if (jogo1 > jogo2)
            {
                ganhadores[i] = 11;
                ganhadoresOitavas[i] = 'K';
            }
            else
            {
                ganhadores[i] = 12;
                ganhadoresOitavas[i] = 'L';
            }
        }
        if (i == 6)
        {
            if (jogo1 > jogo2)
            {
                ganhadores[i] = 13;
                ganhadoresOitavas[i] = 'M';
            }
            else
            {
                ganhadores[i] = 14;
                ganhadoresOitavas[i] = 'N';
            }
        }
        if (i == 7)
        {
            if (jogo1 > jogo2)
            {
                ganhadores[i] = 15;
                ganhadoresOitavas[i] = 'O';
            }
            else
            {
                ganhadores[i] = 16;
                ganhadoresOitavas[i] = 'P';
            }
        }
    }

    for (int i = 0; i < 4; i++)
    {
        scanf("%d %d", &jogo1, &jogo2);
        if (i == 0)
        {
            if (jogo1 > jogo2)
            {
                ganhadoresQuartas[i] = ganhadoresOitavas[0];
            }
            else
            {
                ganhadoresQuartas[i] = ganhadoresOitavas[1];
            }
        }
        if (i == 1)
        {
            if (jogo1 > jogo2)
            {
                ganhadoresQuartas[i] = ganhadoresOitavas[2];
            }
            else
            {
                ganhadoresQuartas[i] = ganhadoresOitavas[3];
            }
        }
        if (i == 2)
        {
            if (jogo1 > jogo2)
            {
                ganhadoresQuartas[i] = ganhadoresOitavas[4];
            }
            else
            {
                ganhadoresQuartas[i] = ganhadoresOitavas[5];
            }
        }
        if (i == 3)
        {
            if (jogo1 > jogo2)
            {
                ganhadoresQuartas[i] = ganhadoresOitavas[6];
            }
            else
            {
                ganhadoresQuartas[i] = ganhadoresOitavas[7];
            }
        }
    }

    for (int i = 0; i < 2; i++)
    {
        scanf("%d %d", &jogo1, &jogo2);
        if (i == 0)
        {
            if (jogo1 > jogo2)
            {
                ganhadoresSemi[i] = ganhadoresQuartas[0];
            }
            else
            {
                ganhadoresSemi[i] = ganhadoresQuartas[1];
            }
        }
        if (i == 1)
        {
            if (jogo1 > jogo2)
            {
                ganhadoresSemi[i] = ganhadoresQuartas[2];
            }
            else
            {
                ganhadoresSemi[i] = ganhadoresQuartas[3];
            }
        }
    }

    for (int i = 0; i < 1; i++)
    {
        scanf("%d %d", &jogo1, &jogo2);
        if (i == 0)
        {
            if (jogo1 > jogo2)
            {
                ganhador[i] = ganhadoresSemi[0];
            }
            else
            {
                ganhador[i] = ganhadoresSemi[1];
            }
        }
    }

    for (int i = 0; i < 1; i++)
    {
        printf("%c\n", ganhador[i]);
    }

    return 0;
}