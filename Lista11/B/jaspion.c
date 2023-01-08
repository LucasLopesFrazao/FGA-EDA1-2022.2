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

typedef struct
{
    char japones[80];
    char portugue[80];
    int posicao
} Item;

int main(void)
{
    int m, n;

    scanf("%d %d", &m, &n);

    Item dictionary[m];

    for (int i = 0; i < m; i++)
    {
        dictionary[i].posicao = i;
        scanf("%s", dictionary[i].japones);
        buffer();
        scanf("%s", dictionary[i].portugue);
    }

    for (int i = 0; i < m; i++)
    {
        printf("%s %s\n", dictionary[i].japones, dictionary[i].portugue);
    }

    // // Read the text to be translated
    // char text[n];
    // printf("Enter the text to be translated:\n");
    // scanf("%s", text);

    // // Split the text into words
    // char *word = strtok(text, " ");
    // while (word != NULL)
    // {
    //     // Search for the word in the dictionary
    //     for (int i = 0; i < m; i++)
    //     {
    //         if (strcmp(word, dictionary[i].english) == 0)
    //         {
    //             // If the word is found, print its translation
    //             printf("%s ", dictionary[i].portuguese);
    //             break;
    //         }
    //     }
    //     // Get the next word in the text
    //     word = strtok(NULL, " ");
    // }
    // printf("\n");

    return 0;
}