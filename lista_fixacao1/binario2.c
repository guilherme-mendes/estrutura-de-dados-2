#include <stdio.h>
#include <stdlib.h>

typedef int Item;
#define lesseq(A, B) ((A) <= (B))

void merge(Item *V, int l, int m, int r) {
    Item *R = malloc(sizeof(Item) * (r - l + 1));
    int i = l, j = m + 1, k = 0;

    while (i <= m && j <= r) {
        if (lesseq(V[i], V[j]))
            R[k++] = V[i++];
        else
            R[k++] = V[j++];
    }

    while (i <= m)
        R[k++] = V[i++];
    while (j <= r)
        R[k++] = V[j++];


    k = 0;
    for (i = l; i <= r; i++)
        V[i] = R[k++];
    free(R);
}

void mergesort(Item *V, int l, int r) {
    if (l >= r) return;
    int meio = (l + r) / 2;
    mergesort(V, l, meio);
    mergesort(V, meio + 1, r);
    merge(V, l, meio, r);
}

int buscaBinaria(int *v,int n, int x){
    int e,d,m;
    e=-1;
    d=n;
    while(e<d-1){
        m=(e+d)/2;
        if (v[m]==x) return m;
        if(v[m]<x)e=m;
        else d=m;
    }
    return d;
}

int main(void){
    int n,m;
    int *vn,*vm,*aux;
    scanf("%d%d",&n,&m);
    vn = malloc(n * sizeof(int));
    vm = malloc(m * sizeof(int));
    aux = malloc(m * sizeof(int));
    for(int i=0; i<n; i++)
        scanf("%d",&vn[i]);

    for(int i=0; i<m; i++){
        scanf("%d",&vm[i]);
        mergesort(vm, m, m - 1);
        aux[i] = buscaBinaria(vn, n, vm[i]);
        printf("%d\n",aux[i]);
    }
    return 0;
}