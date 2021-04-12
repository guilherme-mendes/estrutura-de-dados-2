#include <stdio.h>
#include <stdlib.h>

typedef int Item;
#define less(A, B) ((A) < (B))
#define exch(A, B) { int t; t=A;A=B;B=t; }

void quicksort(Item *, int, int);

int separaCORMEM(Item *, int, int);

int separaCORMEM(Item *V, int l, int r) {
    Item c = V[r];
    int j = l;
    for (int k = l; k < r; k++)
        if (less(V[k], c)) {
            exch(V[k], V[j]);
            j++;
        }
    exch(V[j], V[r]);
    return j;
}

void quicksort(Item *V, int l, int r) {
    if (r <= l) return;
    int j = separaCORMEM(V, l, r);
    quicksort(V, l, j - 1);
    quicksort(V, j + 1, r);
}

int binarySearch(int *low, int key, int *high) {
    if (low > high) {
        return 0;
    } else if (key == *(low + (high - low) / 2)) {
        return 1;
    } else if (key > *(low + (high - low) / 2)) {
        if (binarySearch((low + (high - low) / 2) + 1, key, high) == 1) {
            return 1;
        } else {
            return 0;
        }
    } else if (key < *(low + (high - low) / 2)) {
        if (binarySearch(low, key, (low + (high - low) / 2) - 1) == 1) {
            return 1;
        } else {
            return 0;
        }
    }

}

int main() {
    int n, m;
    scanf("%d", &n);
    scanf("%d", &m);

    int *p;
    p = malloc(2 * n * sizeof(int));

    for (int i = 0; i < n + m + 1; i++) {
        scanf("%d", &p[i]);
    }

    quicksort(p, 0, n - 1);

    while (scanf("%d", &prohib) == 1) {
        if (binarySearch(p, prohib, p + n) == 1) {
            isProhib[j++] = 1;
        } else {
            isProhib[j++] = 0;
        }
    }

    return 0;

}