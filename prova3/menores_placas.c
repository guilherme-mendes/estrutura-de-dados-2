#include<stdio.h>
#include<stdlib.h>
typedef int Item;
#define Key(A) (A)
#define less(A,B) (Key(A)<Key(B))
#define exch(A,B) {int t=A; A=B; B=t;}
#define cmpexch(A,B) {if(less(B,A)) exch(A,B);}
int separaCORMEM(Item *V,int l,int r)
{
  Item c=V[r];
  int j=l;
  for(int k=l;k<r;k++)
    if(less(V[k],c))
    {
      exch(V[k],V[j]);
      j++;
    }
  exch(V[j],V[r]);
  return j;
}
void quicksortM3(Item *V,int l, int r)
{
  if (r<=l) return;
  cmpexch(V[(l+r)/2],V[r]);
    cmpexch(V[l],V[(l+r)/2]);
      cmpexch(V[r],V[(l+r)/2]);
  int j=separaCORMEM(V,l,r);
  quicksortM3(V,l,j-1);
  quicksortM3(V,j+1,r);
}
int separate(int arr[], int l, int r) 
{ 
    int pivot = arr[r];
    int i = (l - 1);
    for (int j = l; j <= r- 1; j++) 
    { 
    if (arr[j] < pivot) 
    { 
        i++;
        exch(arr[i], arr[j]); 
    } 
    } 
    exch(arr[i + 1], arr[r]); 
 return (i + 1); 
} 
void quickSort(int arr[], int l, int r) 
{ 
    if (l < r) 
    { 
        int pi = separate(arr, l, r); 
        quickSort(arr, l, pi - 1); 
        quickSort(arr, pi + 1, r); 
    } 
}
int main() {
    int vt[100];
    int n;
    int o;
    int i = 0;
    while(scanf("%d %d", &o, &n) != EOF) {
        if(o == 1) {
            if(i < 100){
              vt[i] = n;
              i++;
              quicksortM3(vt, 0, i-1);
            }else{
                if(n<vt[i-1]){
                    vt[i-1] = n;
                    quicksortM3(vt, 0, i-1);}
                }
            }
            else {
                for(int j = 0; j < n; j++)
                    printf("%d ", vt[j]);
                printf("\n");
            }
    }
    return 0;
}