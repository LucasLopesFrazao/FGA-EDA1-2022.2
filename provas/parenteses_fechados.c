#include <stdio.h>
#include <string.h>

int bem_formada(char str[])
{
    int i, top = -1;
    char stack[100];

    for (i = 0; i < strlen(str); i++)
    {
        if (str[i] == '(' || str[i] == '[' || str[i] == '{')
        {
            stack[++top] = str[i];
        }
        else if (str[i] == ')' || str[i] == ']' || str[i] == '}')
        {
            if (top == -1)
            {
                return 0;
            }
            if (str[i] == ')' && stack[top] != '(')
            {
                return 0;
            }
            if (str[i] == ']' && stack[top] != '[')
            {
                return 0;
            }
            if (str[i] == '}' && stack[top] != '{')
            {
                return 0;
            }
            top--;
        }
    }

    if (top == -1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int main()
{
    char string1[] = "So when I die (the [first] I will see in (heaven) is a score list).";
    char string2[] = "([ (([( [ ] ) ( ) (( ))] )) ]).";
    char string3[] = "Help( I[m being held prisoner in a fortune cookie factory).";
    char string4[] = "Half Moon tonight (At least it is better than no Moon at all].";

    printf("%d\n", bem_formada(string1)); // should print 1
    printf("%d\n", bem_formada(string3)); // should print 0
    printf("%d\n", bem_formada(string4)); // should print 0
    printf("%d\n", bem_formada(string2)); // should print 1

    return 0;
}