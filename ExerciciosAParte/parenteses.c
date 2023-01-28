#include <stdio.h>
#include <string.h>

#define MAX_SIZE 100

typedef struct
{
    char item[MAX_SIZE];
    int top;
} Stack;

void stack_init(Stack *stack)
{
    stack->top = -1;
}

int stack_empty(Stack *stack)
{
    return stack->top == -1;
}

int stack_full(Stack *stack)
{
    return stack->top == MAX_SIZE - 1;
}

void stack_push(Stack *stack, char x)
{
    if (stack_full(stack))
    {
        printf("Stack full!\n");
        return;
    }
    stack->item[++stack->top] = x;
}

char stack_pop(Stack *stack)
{
    if (stack_empty(stack))
    {
        printf("Stack empty!\n");
        return -1;
    }
    return stack->item[stack->top--];
}

int main()
{
    int t;
    scanf("%d", &t);
    while (t--)
    {
        Stack stack;
        stack_init(&stack);
        char s[MAX_SIZE];
        scanf("%s", s);
        int n = strlen(s);
        int valid = 1;
        for (int i = 0; i < n; i++)
        {
            if (s[i] == '(')
                stack_push(&stack, s[i]);
            else if (s[i] == ')')
            {
                if (!stack_empty(&stack))
                    stack_pop(&stack);
                else
                {
                    valid = 0;
                    break;
                }
            }
        }
        if (!stack_empty(&stack))
            valid = 0;
        if (valid)
            printf("YES\n");
        else
            printf("NO\n");
    }
    return 0;
}