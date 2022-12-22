#include <stdio.h>

int main()
{

    int num;
    int x;

    while (scanf("%x", &num))
    {
        char *p = &num;

        for (int i = 0; i < 4; i++)
        {

            if (p[i] == 0)
            {
                return 0;
            }

            printf("%c", p[i]);
        }
    }

    return 0;
}