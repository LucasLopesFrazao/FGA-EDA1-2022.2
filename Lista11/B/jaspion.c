#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

void buffer(void)
{
    int c = 0;
    while ((c = getchar()) != '\n' && c != EOF)
    {
    }
    return;
}

typedef struct
{
    char japones[82];
    char portugue[82];
} Item;

int compare(const void *a, const void *b)
{
    // Faz o casting dos ponteiros para Item*
    const Item *ia = (const Item *)a;
    const Item *ib = (const Item *)b;

    // Compara os campos japones usando strcmp
    return strcmp(ia->japones, ib->japones);
}

int busca_binaria(Item *dictionary, int n, const char *japones)
{
    int esq = 0;
    int dir = n - 1;

    while (esq <= dir)
    {
        int meio = (esq + dir) / 2;
        int cmp = strcmp(japones, dictionary[meio].japones);

        if (cmp < 0)
        {
            dir = meio - 1;
        }
        else if (cmp > 0)
        {
            esq = meio + 1;
        }
        else
        {
            return meio; // encontrou o elemento
        }
    }

    return -1; // não encontrou o elemento
}

void traduz_frase(Item *dictionary, int n, const char *frase)
{
    char palavra[82];
    int i = 0;
    int j = 0;
    while (frase[i] != '\0')
    {
        // Pula os espaços em branco
        while (isspace(frase[i]))
        {
            putchar(frase[i]);
            i++;
        }

        // Copia a próxima palavra para a variável palavra
        j = 0;
        while (!isspace(frase[i]) && frase[i] != '\0')
        {
            palavra[j] = frase[i];
            j++;
            i++;
        }
        palavra[j] = '\0';

        // Traduz a palavra e imprime a tradução
        int pos = busca_binaria(dictionary, n, palavra);
        if (pos >= 0)
        {
            printf("%s", dictionary[pos].portugue);
        }
        else
        {
            printf("%s", palavra);
        }
    }
}

int main(void)
{
    int m, n, lixo;
    scanf("%d", &lixo);
    
    while (lixo--)
    {
        scanf("%d %d", &m, &n);
        buffer();

        Item dictionary[1000001];

        for (int i = 0; i < m; i++)
        {
            scanf("%[^\n]", dictionary[i].japones); // Lê a string até encontrar um '\n'
            buffer();

            scanf("%[^\n]", dictionary[i].portugue); // Lê a string até encontrar um '\n'
            buffer();
        }

        qsort(dictionary, m, sizeof(Item), compare);

        for (int i = 0; i < n; i++)
        {
            char frase[82];
            scanf("%[^\n]", frase); // Lê a string até encontrar um '\n'
            buffer();

            traduz_frase(dictionary, m, frase);
            putchar('\n');
        }
    }

    return 0;
}