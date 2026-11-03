#include <stdio.h>

long long cmp_count = 0;     // taqqoslashlar soni

void swap(int *x, int *y) {
    int t = *x;
    *x = *y;
    *y = t;
}

int partition(int a[], int low, int high) {
    int pivot = a[high];
    int i = low - 1;
    for (int j = low; j < high; j++) {
        cmp_count++;              // a[j] va pivot taqqoslanadi
        if (a[j] < pivot) {
            i++;
            swap(&a[i], &a[j]);
        }
    }
    swap(&a[i + 1], &a[high]);
    return i + 1;
}

int main(void) {
    int a[] = {3, 7, 1, 5};
    int p = partition(a, 0, 3);
    printf("pivot indeksi: %d, taqqoslash: %lld\n", p, cmp_count);
    for (int i = 0; i < 4; i++) printf("%d ", a[i]);
    printf("\n");
    return 0;
}
