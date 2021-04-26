#include <stdio.h>
#include <stdlib.h>

typedef struct vel {
    int d;
    int u;
} vel;

typedef vel Item;

#define less(A,B) (Key(A)<Key(B))
#define exch(A,B) {int t=A; A=B; B=t;}
#define cmpexch(A,B) {if(less(B,A)) exch(A,B);}
#define cmpexch2(A,B,C,D) {if(less(B,A)) exch(A,B); exch(C,D);}
#define Key(A) (A.d)
#define KeyUp(A) (A.u)
#define lessUp(A, B) (KeyUp(A) < KeyUp(B))
#define equal(A, B) (Key(A) == Key(B))

int separate(int arr[], int arr2[], int l, int r) 
{ 
    int pivot = arr[r];
    int i = (l - 1);

    for (int j = l; j <= r- 1; j++) 
    { 
    if (arr[j] < pivot) 
    { 
        i++;
        exch(arr[i], arr[j]);
        exch(arr2[i], arr2[j]);
    } 
    } 
    exch(arr[i + 1], arr[r]); 
    exch(arr2[i + 1], arr2[r]); 
	return (i + 1); 
} 

void quickSort(int arr[], int arr2[], int l, int r) 
{ 
    if (l < r) 
    { 
        int pi = separate(arr, arr2, l, r); 

        quickSort(arr, arr2, l, pi - 1); 
        quickSort(arr, arr2, pi + 1, r); 
    } 
}

void interpolate(Item *vec, int left, int m, int right) {
    Item * c = malloc(sizeof(Item) * (right - left + 1));
    int aux1 = left;
    int aux2 = m + 1;
    int count = 0;

    while(aux1 <= m && aux2 <= right) {
        if(less(vec[aux1], vec[aux2])) {
            c[count++] = vec[aux1++];
        } else if(equal(vec[aux1], vec[aux2])) {
            if(lessUp(vec[aux1], vec[aux2])) {
                c[count++] = vec[aux1++];
            } else {
                c[count++] = vec[aux2++];
            }
        } else {
            c[count++] = vec[aux2++];
        }
    }

    while(aux1 <= m)
        c[count++] = vec[aux1++];

    while(aux2 <= right)
        c[count++] = vec[aux2++];

    count = 0;
    for(aux1 = left; aux1 <= right; aux1++)
        vec[aux1] = c[count++];   

    free(c);
}

void mergeSort(Item *vec, int left, int right) {
    if (left >= right) return;

    int m = (left + right) / 2;

    mergeSort(vec, left, m);
    mergeSort(vec, m + 1, right);

    interpolate(vec, left, m, right);
}

int main(void) {

    Item vec[1000000];
    int d, u;
    int l, t;

    scanf("%d%d%d%d",&d, &u,&l, &t);
    
    double fL = (double)l;
    int down[t];
    int up[t];
    double dlimiar = d - (d * (fL/100));
    double ulimiar = u - (u * (fL/100));
    int cnt = 0;

    for(int i=0; i<t; i++){
        int d_aux, u_aux;
        scanf("%d/%d", &d_aux, &u_aux);
        if(d_aux<(int)dlimiar || u_aux<(int)ulimiar){
            vec[cnt].d = d_aux;
            vec[cnt].u = u_aux;
            cnt++;
        }
    }

    mergeSort(vec, 0, cnt-1);

    for(int i=0; i<cnt; i++){
        printf("%d/%d\n", vec[i].d, vec[i].u);
    }

    return 0;
}
