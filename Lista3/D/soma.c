#include <stdio.h>
long soma_digito(long num)
{
    long a, b;
    a = num % 10;
    b = (num - a) / 10;
    if (b <= 0)
    {
        return a;
    }
    else
    {
        return a + soma_digito(b);
    }
}
void main()
{
    long n;
    scanf("%ld", &n);
    printf("%ld\n", soma_digito(n));
}