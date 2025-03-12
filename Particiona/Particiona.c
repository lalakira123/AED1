#include <stdio.h>
#include <stdlib.h>

void printaVetor(int *v, int n) {
    for(int i = 0; i < n; i++) {
        printf("%d\n", v[i]);
    }
}

void particiona(int *v, int q, int p) {
    int i = 0, pm = -1;

    int aux1 = v[p];
    v[p] = v[q - 1];
    v[q - 1] = aux1; 
    p = q - 1;

    while(i < q - 1) {
        if(v[i] <= v[p]) {
            pm++;
            int aux = v[i];
            v[i] = v[pm];
            v[pm] = aux;
            i++;
        } else {
            i++;
        }
    }

    pm++;
    int aux2 = v[p];
    v[p] = v[pm];
    v[pm] = aux2;

    printaVetor(v, q);
}

int main() {
    int q, p;

    scanf("%d", &q);
    scanf("%d", &p);

    int *v = (int*)malloc(q * sizeof(int));

    for(int i = 0; i < q; i++) {
        scanf("%d", &v[i]);
    }

    particiona(v, q, p);

    return 0;
}