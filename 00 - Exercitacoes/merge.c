#include <stdio.h>
#include <stdlib.h>

void printVetor(int *v, int n) {
    for(int i = 0; i < n; i++) {
        printf("%d%s", v[i], i==n-1?"\n":" ");
    }
}

void intercala(int *v, int *newV, int e, int m, int d) {
    int i = e, j = m, count = 0;

    while(i < m || j <= d) {
        if(i < m && (j > d || v[j] >= v[i])) {
            newV[count++] = v[i++];
        }
        
        if(j <= d && (i >= m || v[i] >= v[j])) {
            newV[count++] = v[j++];
        }
    }

    count = 0;
    for(int k = e; k <= d; k++) {
        v[k] = newV[count++];
    }
}

void mergeSort(int *v, int *newV, int e, int d) {
    int meio;

    if(e < d) {
        meio = (e+d) / 2;
        mergeSort(v, newV, e, meio);
        mergeSort(v, newV, meio+1, d);
        intercala(v, newV, e, meio+1, d);
    }
}

int main() {
    int n, *v, *newV;

    scanf("%d", &n);

    v = (int*)malloc(n * sizeof(int));
    newV = (int*)malloc(n * sizeof(int));

    for(int i = 0; i < n; i++) {
        scanf("%d", &v[i]);
    }

    printVetor(v, n);
    mergeSort(v, newV, 0, n-1);
    printVetor(v, n);

    return 0;
}