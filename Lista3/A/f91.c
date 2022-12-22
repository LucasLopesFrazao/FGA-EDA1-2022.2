#include <stdio.h>

int f91(int n)
{
    if (n >= 101)
    {
        return n - 10;
    }

    if(n <= 100){
        f91(f91(n + 11));
    }
}

int main()
{
    int b;
    while(scanf("%d", &b)){
        if(b == 0){
            return 0;
        }
        else {
            printf("f91(%d) = %d\n", b, f91(b));
        }
    }
    return 0;
}