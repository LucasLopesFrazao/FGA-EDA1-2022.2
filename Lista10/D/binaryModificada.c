#include <stdio.h>

int BinarySearch(int *v, int start, int end, int key)
{

    while (start + 1 < end)
    {
        int mid = (start + end) / 2;

        if (key < v[mid])
            end = mid;
        if (key >= v[mid])
            start = mid;
    }

    if (v[start] == key)
        return start;

    if (v[start] != key)
    {
        if (v[start] > key)
        {
            return start;
        }
        else
        {
            return start + 1;
        }
    }
}

int main()
{
    int n, m;

    scanf("%d %d", &n, &m);
    int v[n];

    for (int i = 0; i < n; i++)
    {
        scanf("%d", &v[i]);
    }

    for (int i = 0; i < m; i++)
    {
        int key;
        scanf("%d", &key);
        printf("%d\n", BinarySearch(v, 0, n, key));
    }
    
    return 0;
}