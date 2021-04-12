#include <stdio.h>
#include <stdlib.h>

typedef int item;
#define key(a) (a)
#define less(a, b) (key(a) < key(b))
#define exch(a, b) {item t = a; a = b; b = t;}
#define cmpexch(a, b) {if (less(b,a)) exch(a,b);}

int separa(item *v, int l, int r) {

    int pivo = v[r];
    int j = l;

    for (int k = l; k < r; k++)
        if (less(v[k], pivo)) {
            exch (v[k], v[j]);
            j++;
        }
    exch (v[j], v[r]);

    return j;
}

void quick_select(int *v, int l, int r, int k)
{
    if (l >= r)
        return;
    int i = separa(v, l, r);
    if (i > k)
        quick_select(v, l, i - 1, k);
    if (i < k)
        quick_select(v, i + 1, r, k);
}

void quick_sort(int *v, int l, int r)
{
    if (r <= l)
        return;

    int j = separa(v, l, r);

    quick_sort(v, l, j - 1);
    quick_sort(v, j + 1, r);
}

int main()
{
    int n, p, x;
    scanf("%d %d %d", &n, &p, &x);

    int *v = malloc(n*sizeof(int));
    for(int i=0; i<n; i++){
        int id;
        scanf("%d", &id);
        v[i] = id;
    }

    int l, r;
    l = x*p;
    if (l > n) return 0;

    r = l + x - 1;
    if(r >= n) r = n-1;
    
    quick_select(v, 0, n-1, l);
    quick_select(v, l, n-1, r);
    quick_sort  (v, l, r);


    for(int i = l; i <=r; i++)
        printf("%d\n", v[i]);

    return 0;
}
