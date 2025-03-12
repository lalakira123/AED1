#include <stdio.h>
#include <stdlib.h>

void printaDescartados(int *v, int inicia, int finaliza) {
    for(int i = inicia; i <= finaliza; i++) {
        if (i < finaliza) {
            printf("%d ", v[i]);
        }

        if (i == finaliza) {
            printf("%d", v[i]);
        }
    }
    printf("\n");
}

void buscaBinaria(int *v, int n, int chave) {
    int e = 0, d = n - 1;

    while(e <= d) {
        int m = (d + e) / 2;

        if (v[m] == chave) {
            printf("VALOR %d LOCALIZADO NA COLECAO\n", chave);
            return;
        } else if (v[m] < chave) {
            printaDescartados(v, e, m);
            e = m + 1; 
        } else if (v[m] > chave) {
            printaDescartados(v, m, d);
            d = m - 1;
        }
    }

    if (e > d) {
        printf("VALOR %d NAO LOCALIZADO NA COLECAO\n", chave);
    }
}

int main () {
    int n, *v, chave;

    scanf("%d", &n);

    v = (int*)malloc(n * sizeof(int));

    for (int i = 0; i < n; i++) {
        scanf("%d", &v[i]);
    }

    while(scanf("%d", &chave) != EOF) {
        buscaBinaria(v, n, chave);
    }

    free(v);
    return 0;
}