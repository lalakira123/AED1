#include <stdio.h>
#include <stdlib.h>

void printaVetor(int *v, int n) {
    for(int i = 0; i < n; i++) {
        printf("%d%s", v[i], i==n-1?"\n":" ");
    }
}

void particiona(int *v, int n, int p) {
    int pm = -1;
    int aux;
    
    aux = v[n-1];
    v[n-1] = v[p];
    v[p] = aux;
    
    p = n-1;

    int i;
    for(i = 0; i < n - 1; i++) {
        if(v[i] <= v[p]) {
            pm++;
            aux = v[i];
            v[i] = v[pm];
            v[pm] = aux;
        } 
    }

    pm++;
    aux = v[i];
    v[i] = v[pm];
    v[pm] = aux;
}

int main() {
    int n, p, *v;

    scanf("%d", &n);
    scanf("%d", &p);

    for(int i = 0; i < n; i++) {
        scanf("%d", &v[i]);
    }

    particiona(v, n, p);
    printaVetor(v, n);

    return 0;
}