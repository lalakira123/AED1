#include <stdio.h>
#include <stdlib.h>

void printVetor(int *v, int n) {
    for(int i = 0; i < n; i++) {
        printf("%d\n", v[i]);
    }
}

void intercala(int *v, int *newV, int q1, int q2) {
    int i = 0, count = 0, tam = q1+q2;
    int j = q1;

    while(i < q1 || j < tam) {
        if(i < q1 && (j >= tam || v[i] <= v[j])){
            newV[count++] = v[i++];
        }

        if(j < tam && (i >= q1 || v[j] <= v[i])){
            newV[count++] = v[j++];
        }
    }

    printVetor(newV, tam);
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

    intercala(v, newV, q1, q2);

    return 0;
}