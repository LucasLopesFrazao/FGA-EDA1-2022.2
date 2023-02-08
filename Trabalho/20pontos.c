#include <stdio.h>
#include <stdlib.h>
typedef struct Item
{
    unsigned long long atual;
    unsigned long long anterior;
    unsigned long long proximo;
}Item;
int compare_elements(const void *a, const void *b)
{
    struct Item *item_a = (struct Item *)a;
    struct Item *item_b = (struct Item *)b;
    return (item_a->atual > item_b->atual) - (item_a->atual < item_a->atual);
}
int search(Item *v, int n, unsigned long long x)
{
    int l = 0, r = n - 1;
    while (l <= r)
    {
        int m = l + (r - l) / 2;
        if (v[m].atual == x)
            return m;
        else if (v[m].atual < x)
            l = m + 1;
        else
            r = m - 1;
    }
    return -1;
}
int is_sane(Item *v, int n, Item anterior, Item alvo)
{
    if (anterior.proximo == alvo.atual && alvo.anterior == anterior.atual)
        return 1;
    int idx = search(v, n, anterior.proximo);
    if (idx == -1 || v[idx].anterior != anterior.atual)
        return 0;
    return is_sane(v, n, v[idx], alvo);
}
int main()
{
    Item v[100000];
    int n = 0;
    while (scanf(" %llx %llx %llx", &v[n].atual, &v[n].anterior, &v[n].proximo) == 3)
        n++;
    Item ptr1 = v[0], ptr2 = v[1];
    qsort(v, n, sizeof(Item), compare_elements);
    printf("%s\n", (is_sane(v, n, ptr1, ptr2) ? "sana" : "insana"));
    return 0;
}
