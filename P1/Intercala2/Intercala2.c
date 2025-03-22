#include <stdio.h>
#include <stdlib.h>

void printaVetor(int *v, int n) {
    for(int i = 0; i < n; i++) {
        printf("%d\n", v[i]);
    }
}

void intercala(int *v, int q1, int q2){
    int tam = q1 + q2;
    int i = 0, j = tam - q2, count = 0;
    int *newV = (int*)malloc(tam * sizeof(int));

    while(i < q1 || j < tam) {
        if(i < q1 && (j >= tam || v[i] <= v[j])) {
            newV[count++] = v[i++];
        }

        if(j < tam && (i >= q1 || v[j] <= v[i])) {
            newV[count++] = v[j++];
        }
    }

    printaVetor(newV, tam);

    free(newV);
}

int main(){
    int *v, q1, q2;

    scanf("%d", &q1);
    scanf("%d", &q2);

    v = (int*)malloc((q1+q2) * sizeof(int));

    for(int i = 0; i < (q1+q2); i++) {
        scanf("%d", &v[i]);
    }

    intercala(v, q1, q2);

    return 0;
}