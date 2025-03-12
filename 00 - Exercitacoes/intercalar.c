#include <stdio.h>
#include <stdlib.h>

void printaVetor(int *v, int n) {
    for(int i = 0 ; i < n ; i++) {
        printf("%d%s", v[i], i==n-1?"\n":" ");
    }
}

void intercalar(int *v, int *newV, int e, int m, int d) {
    int i = e, j = m, count = 0;

    while(i < m || j < d) {
        if(i < m && (j >= d || v[j] >= v[i])) {
            newV[count++] = v[i++];
        }

        if(j < d && (i >= m || v[i] >= v[j])) {
            newV[count++] = v[j++];
        }
    }
}

int main() {
    int q1, q2, *v, *newV;

    scanf("%d", &q1);
    scanf("%d", &q2);

    int n = (q1 + q2);

    v = (int *)malloc(n * sizeof(int));
    newV = (int *)malloc(n * sizeof(int));

    for(int i = 0; i < n; i++){
        scanf("%d", &v[i]);
    }

    intercalar(v, newV, 0, q1, n);
    printaVetor(newV, n);

    return 0;
}