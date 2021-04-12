#include<stdio.h>

int main() {

  int n;
  scanf("%d", &n);

  int vt[n];
  for(int i = 0; i < n; i++) {
    scanf("%d", &vt[i]);
  }

  for(int i = 0; i < n; i++) {
    if(vt[i] % 2 == 0) 
        printf("Jedi\n");
    if(vt[i] % 2 != 0) 
        printf("Sith\n");
  }

  return 0;
}