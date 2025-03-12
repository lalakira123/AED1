#include <stdio.h>
#include <stdlib.h>

void printaVetor(int *v, int begin, int end) {
    for(int i = begin; i <= end; i++) {
        printf("%d%s", v[i], i == end ? "\n" : " ");
    }
}

void buscaBinaria(int *v, int n, int chave) {
    int e = 0, d = n-1;
    
    while(e <= d) {
        int meio = (e + d) / 2;
        if(v[meio] == chave) {
            printf("VALOR %d LOCALIZADO NA COLECAO\n", chave);
            break;
        } else if(chave > v[meio]){
            printaVetor(v, e, meio);
            e = meio + 1;
        } else if(chave < v[meio]){
            printaVetor(v, meio, d);
            d = meio - 1;
        }
    }

    if(e > d) {
        printf("VALOR %d NAO LOCALIZADO NA COLECAO\n", chave);
    }
}

int main() {
    int n, *v, chave;

    scanf("%d", &n);

    v = (int*)malloc(n * sizeof(int));

    for(int i = 0; i < n; i++) {
        scanf("%d", &v[i]);
    }

    while(scanf("%d", &chave) != EOF) {
        buscaBinaria(v, n, chave);
    }

    return 0;
}