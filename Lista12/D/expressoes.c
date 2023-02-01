#include <stdio.h>
#include <string.h>

#define MAX_LEN 100000

char stack[MAX_LEN];
int top = -1;

void push(char c) {
    stack[++top] = c;
}

char pop() {
    if (top == -1) return '\0';
    return stack[top--];
}

int main() {
    int t;
    scanf("%d", &t);

    while (t--) {
        char str[MAX_LEN];
        scanf("%s", str);
        int len = strlen(str);

        top = -1;
        int flag = 1;
        for (int i = 0; i < len; i++) {
            if (str[i] == '(' || str[i] == '[' || str[i] == '{')
                push(str[i]);
            else {
                char c = pop();
                if (str[i] == ')' && c != '(') {
                    flag = 0;
                    break;
                }
                if (str[i] == ']' && c != '[') {
                    flag = 0;
                    break;
                }
                if (str[i] == '}' && c != '{') {
                    flag = 0;
                    break;
                }
            }
        }
        if (flag && top == -1) printf("S\n");
        else printf("N\n");
    }

    return 0;
}
