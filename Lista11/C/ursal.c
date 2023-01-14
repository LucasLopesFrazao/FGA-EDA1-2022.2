#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define less(a, b) (a.total_votos_candidato == b.total_votos_candidato ? a.numero_candidato > b.numero_candidato : a.total_votos_candidato > b.total_votos_candidato)

typedef struct
{
    int numero_candidato, total_votos_candidato;
} Voto;

int separa(Voto *v, int l, int r)
{
    Voto pivot = v[r];
    int j = l;
    for (int k = l; k < r; k++)
        if (less(v[k], pivot))
        {
            Voto temp = v[k];
            v[k] = v[j];
            v[j] = temp;
            j++;
        }
    Voto temp = v[j];
    v[j] = v[r];
    v[r] = temp;
    return j;
}

void quicksort(Voto *v, int l, int r)
{
    if (r <= l)
        return;

    int mid = (l + r) / 2;
    if (less(v[mid], v[r]))
    {
        Voto temp = v[mid];
        v[mid] = v[r];
        v[r] = temp;
    }
    if (less(v[l], v[mid]))
    {
        Voto temp = v[l];
        v[l] = v[mid];
        v[mid] = temp;
    }
    if (less(v[mid], v[r]))
    {
        Voto temp = v[mid];
        v[mid] = v[r];
        v[r] = temp;
    }

    int m = separa(v, l, r);
    quicksort(v, l, m - 1);
    quicksort(v, m + 1, r);
}

Voto ps[91], ss[901], dfs[9001], des[90001];

int main()
{
    int s, f, e;
    scanf("%d %d %d", &s, &f, &e);

    int valid = 0, invalid = 0, totalp = 0;
    ;
    int x;
    while (scanf("%d", &x) == 1)
    {
        if (x < 0)
        {
            invalid++;
            continue;
        }
        if (x < 100)
        {
            ps[x - 10].numero_candidato = x;
            ps[x - 10].total_votos_candidato++;
            totalp++;
        }
        else if (x < 1000)
        {
            ss[x - 100].numero_candidato = x;
            ss[x - 100].total_votos_candidato++;
        }
        else if (x < 10000)
        {
            dfs[x - 1000].numero_candidato = x;
            dfs[x - 1000].total_votos_candidato++;
        }
        else
        {
            des[x - 10000].numero_candidato = x;
            des[x - 10000].total_votos_candidato++;
        }
        valid++;
    }

    int aux_presidente = 0, aux_senador = 0, aux_federal = 0, aux_estadual = 0;
    int sizes[] = {91, 901, 9001, 90001};
    for (int j = 0; j < 4; j++)
    {
        for (int i = 0; i < sizes[j]; i++)
        {
            if (j == 0 && ps[i].total_votos_candidato)
            {
                ps[aux_presidente++] = ps[i];
            }
            else if (j == 1 && ss[i].total_votos_candidato)
            {
                ss[aux_senador++] = ss[i];
            }
            else if (j == 2 && dfs[i].total_votos_candidato)
            {
                dfs[aux_federal++] = dfs[i];
            }
            else if (j == 3 && des[i].total_votos_candidato)
            {
                des[aux_estadual++] = des[i];
            }
        }
    }

    printf("%d %d\n", valid, invalid);

    quicksort(ps, 0, aux_presidente - 1);
    quicksort(ss, 0, aux_senador - 1);
    quicksort(dfs, 0, aux_federal - 1);
    quicksort(des, 0, aux_estadual - 1);

    if ((double)ps[0].total_votos_candidato / totalp >= 0.51)
    {
        printf("%d\n", ps[0].numero_candidato);
    }
    else
    {
        printf("Segundo turno\n");
    }

    for (int i = 0; i < s; i++)
    {
        printf("%d", ss[i].numero_candidato);
        if (i != s - 1)
        {
            printf(" ");
        }
        else
        {
            printf("\n");
        }
    }
    for (int i = 0; i < f; i++)
    {
        printf("%d", dfs[i].numero_candidato);
        if (i != f - 1)
        {
            printf(" ");
        }
        else
        {
            printf("\n");
        }
    }
    for (int i = 0; i < e; i++)
    {
        printf("%d", des[i].numero_candidato);
        if (i != e - 1)
        {
            printf(" ");
        }
        else
        {
            printf("\n");
        }
    }

    return 0;
}