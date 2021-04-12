#include <stdio.h>
#include <string.h>
#define min(a, b) ((a) < (b) ? (a) : (b))
int main()
{
    int N;
    int tam;
    int botas[31][2];
    int p = 0;
    
    char foot;
    memset(botas, 0, sizeof(botas));
    
    while(scanf("%d %c", &tam, &foot) != EOF) {
        ++botas[tam - 30][foot == 'E' ? 0 : 1];
    }
    
    for (int i = 0; i < 31; ++i) {
        p += min(botas[i][0], botas[i][1]);
    }

    printf("%d\n", p);
    
    return 0;
}