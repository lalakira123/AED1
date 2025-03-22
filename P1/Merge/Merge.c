#include <stdio.h>
#include <stdlib.h>

void printVetor(int *v, int n) {
    for(int i = 0; i < n; i++) {
        if(i == n -1) {
            printf("%d\n", v[i]);
        } else {
            printf("%d ", v[i]);
        }
    }
}

void intercala(int *v, int e, int m, int d, int n, int *newV) {
    int i = e, j = m, count = 0;

    printVetor(v, n);

    while( i < m || j <= d) {
        if (i < m && (j > d || v[i] <= v[j])) {
            newV[count++] = v[i++];
        }

        if (j <= d && (i >= m || v[j] <= v[i])) {
            newV[count++] = v[j++];
        }
    }

    count = 0;
    for (i = e; i <= d; i++) {
        v[i] = newV[count++];
    }
}

void mergeSort(int *v, int e, int d, int n, int *aux) {
    int meio;
    if (e < d) {
        meio = (d+e)/2;
        mergeSort(v, e, meio, n, aux);
        mergeSort(v, meio + 1, d, n, aux);
        intercala(v, e, meio+1, d, n, aux);
    }
}

int main(){
    int n, *v, *aux;

    scanf("%d", &n);

    v = (int*)malloc(n * sizeof(int));
    aux = (int*)malloc(n * sizeof(int));
    for(int i = 0; i < n; i++){
        scanf("%d", &v[i]);
    }

    printVetor(v, n);
    mergeSort(v, 0, n - 1, n, aux);
    printVetor(v, n);

    free(v);
    free(aux);

    return 0;
}