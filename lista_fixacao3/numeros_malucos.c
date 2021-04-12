#include <stdio.h>

typedef int item;
#define key(a) (a)
#define less(a, b) (key(a) < key(b))
#define exch(a, b) {item t = a; a = b; b = t;}
#define cmpexch(a, b) {if (less(b,a)) exch(a,b);}

void quick_sort(item *v, int l, int r);

int separa(item *v, int l, int r);

int remove_dupl(int arr[], int n);

int main(void) {

    int n;
    int vn[131074];

    scanf("%d", &n);
    // vn = malloc(n * sizeof(int));

    for (int i = 0; i < n; i++) {
        scanf("%d", &vn[i]);
    }

    quick_sort(vn, 0, n - 1);

    int arr_size = 0;

    arr_size = remove_dupl(vn, n);

    if (arr_size % 2 != 0) {
        vn[arr_size] = 1000000000;
        arr_size++;
    }

    int mnu_arr[arr_size / 2];

    int mnu_count = 0;

    int arr_size2 = arr_size;

    for (int i = 0; i < arr_size; i += 2) {
        mnu_arr[mnu_count] = vn[i] + vn[i + 1];
        mnu_count++;
        vn[arr_size2] = vn[i] + vn[i + 1];
        arr_size2++;
        // printf("%d ", vn[i]);
    }

    // for(int i = 0; i < mnu_count; i++) {
    //     printf("%d\n", mnu_arr[i]);
    // }

    quick_sort(vn, 0, arr_size2 - 1);

    arr_size = remove_dupl(vn, arr_size2);

    for (int i = 0; i < arr_size; i += 4) {
        printf("%d\n", vn[i]);
    }

    printf("Elementos: %d\n", arr_size);

    return 0;
}

void quick_sort(item *v, int l, int r) {

    int j;

    if (r <= l) return;

    exch (v[(l + r) / 2], v[r - 1]);
    cmpexch (v[l], v[r - 1]);
    cmpexch (v[l], v[r]);
    cmpexch (v[r - 1], v[r]);

    j = separa(v, l, r);
    quick_sort(v, l, j - 1);
    quick_sort(v, j + 1, r);
}

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

int remove_dupl(int arr[], int n) {
    if (n == 0 || n == 1)
        return n;

    int temp[n];

    int j = 0;
    int i;
    for (i = 0; i < n - 1; i++)
        if (arr[i] != arr[i + 1])
            temp[j++] = arr[i];
    temp[j++] = arr[n - 1];

    for (i = 0; i < j; i++)
        arr[i] = temp[i];

    return j;
}