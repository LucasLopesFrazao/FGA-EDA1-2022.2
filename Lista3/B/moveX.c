#include <stdio.h>

void isc(char *s)
{
    if(s[0] == '\0') return;
    
    if (s[0] != 'x')
    {
        printf("%c", s[0]);
    }

    isc(&s[1]);
    
    if (s[0] == 'x')
    {
        printf("%c", s[0]);
    }
    
}

int main()
{
    char nome[100];
    scanf("%s", &nome);
    isc(nome);
    return 0;
}