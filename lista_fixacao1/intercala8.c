#include <stdio.h>
#include <stdlib.h>

#define key(A) (A)
#define lesseq(A, B) (key(A) <= key(B))

int *intercala2(const int *v1, int n1, const int *v2, int n2) {
    int *result = malloc((n1 + n2) * sizeof(int));
    int p1 = 0, p2 = 0, rp = 0;

    while (p1 < n1 && p2 < n2) {
        if (lesseq(v1[p1], v2[p2])) {
            result[rp] = v1[p1];
            p1++;
        } else {
            result[rp] = v2[p2];
            p2++;
        }
        rp++;
    }

    while (p1 < n1) {
        result[rp] = v1[p1];
        p1++;
        rp++;
    }

    while (p2 < n2) {
        result[rp] = v2[p2];
        p2++;
        rp++;
    }

    return result;
}

int *intercala4(int *v1, int n1, int *v2, int n2, int *v3, int n3, int *v4, int n4) {
    int *left = intercala2(v1, n1, v2, n2);
    int tamLeft = n1 + n2;

    int *right = intercala2(v3, n3, v4, n4);
    int tamRight = n3 + n4;

    int *result = intercala2(left, tamLeft, right, tamRight);
    free(left);
    free(right);

    return result;
}

int *intercala8(int *v1, int n1, int *v2, int n2, int *v3, int n3, int *v4, int n4, int *v5, int n5, int *v6, int n6,
                int *v7, int n7, int *v8, int n8) {
    int *left = intercala4(v1, n1, v2, n2, v3, n3, v4, n4);
    int tamLeft = n1 + n2 + n3 + n4;

    int *right = intercala4(v5, n5, v6, n6, v7, n7, v8, n8);
    int tamRight = n5 + n6 + n7 + n8;

    int *result = intercala2(left, tamLeft, right, tamRight);
    free(left);
    free(right);

    return result;
}

int main() {
    int s[8];

    int *n1;

    int **v;

    v = malloc(8 * sizeof(int *));

    for (int i = 0; i < 8; i++) {
        scanf("%d", &s[i]);
        v[i] = malloc(s[i] * sizeof(int));
        for (int j = 0; j < s[i]; j++) {
            scanf("%d", &v[i][j]);
        }
    }

    n1 = intercala8(v[0], s[0], v[1], s[1], v[2], s[2], v[3], s[3], v[4],
                    s[4], v[5], s[5], v[6], s[6], v[7], s[7]);

    printf("%d", n1[0]);
    for (int i = 1; i < s[1] + s[2] + s[3] + s[4] + s[5] + s[6] + s[7] + s[0]; i++) {
        printf(" %d", n1[i]);
    }
    printf("\n");

    return 0;
}