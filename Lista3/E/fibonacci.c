#include <stdio.h>
long fibmem[1001] = {[0 ... 1000] = -1};

long int fibonacci(long n)
{

    fibmem[1] = 1;
    fibmem[2] = 1;

    if (fibmem[n] != -1)
    {
        return fibmem[n];
    }


    fibmem[n] = fibonacci(n - 1) + fibonacci(n - 2); 

    return fibmem[n];
}

int main()
{

    long b;

    b = fibonacci(80);

    printf("%ld\n", b);

    return 0;
}