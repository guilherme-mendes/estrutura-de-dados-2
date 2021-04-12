#include <stdio.h>
#include <stdlib.h>

#define hash(v, m) ((618033 * (unsigned)v) % m)
#define key(x) (x.chave)
#define less(a, b) (key(a) < key(b))
#define eq(a, b) (a == b)
#define null(a) (key(th[a]) == key(NULLitem))

typedef struct item
{
    int chave;
    int n;
} item;

item NULLitem = {0, 0};

static int N, M;
static item *th;

item isUpper(item upper, item aux){
    if(upper.n < aux.n){
        return aux;
    }

    if(upper.n == aux.n){
        if(upper.chave > aux.chave){
            return upper;
        }else{
            return aux;
        }
    }

    else {
        return upper;
    }
}

void thInit(int max)
{
    int i;
    N = 0, M = max;
    th = malloc(sizeof(item) * M);
    for (i = 0; i < M; i++)
        th[i] = NULLitem;
}

void thInsert(item item)
{
    int v = key(item);
    int i = hash(v, M);

    if(th[i].chave != 0 && th[i].chave != item.chave){
        while (!null(i))
            i = (i + 1) % M;
    }

    th[i].chave = item.chave;
    th[i].n++;
    N++;
}

item thSearch(int v)
{
    int i = hash(v, M);

    while (!null(i))
    {
        if (eq(v, key(th[i])))
            return th[i];
        else
            i = (i + 1) % M;
    }

    return NULLitem;
}


int main()
{
    int n;
    scanf("%d", &n);

    thInit(1000001);

    item upper = {0, 0};

    for(int i = 0; i < n; i++){
        item notas;
        scanf("%d", &notas.chave);

        thInsert(notas);
        if(upper.chave != notas.chave)
            upper = isUpper(upper, thSearch(notas.chave));
    }


    printf("%d\n", upper.chave);    

    return 0;
}