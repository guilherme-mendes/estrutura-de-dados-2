#include <stdio.h>
#include <stdlib.h>

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
        aux[i] = buscaBinaria(vn, n, vm[i]);
        printf("%d\n",aux[i]);
    }
    return 0;
}