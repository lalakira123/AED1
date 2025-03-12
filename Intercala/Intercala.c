#include <stdio.h>
#include <stdlib.h>

void printaVetor(int *v, int n) {
    for(int i = 0; i < n; i++) {
        printf("%d\n", v[i]);
    }
}

void intercala(int *v1, int q1, int *v2, int q2){
    int i = 0, j = 0, count = 0;
    int *newV = (int*)malloc((q1 + q2) * sizeof(int));

    while(i < q1 || j < q2) {
        if(i < q1 && (j >= q2 || v1[i] <= v2[j])) {
            newV[count++] = v1[i++]; 
        }
        
        if (j < q2 && (i >= q1 || v2[j] <= v1[i])){
            newV[count++] = v2[j++];
        }
    }

    printaVetor(newV, q1+q2);

    free(newV);
}

int main(){
    int *v1, *v2, q1, q2;

    scanf("%d", &q1);
    scanf("%d", &q2);

    v1 = (int*)malloc(q1 * sizeof(int));
    v2 = (int*)malloc(q2 * sizeof(int));

    for(int i = 0; i < q1; i++) {
        scanf("%d", &v1[i]);
    }

    for(int i = 0; i < q2; i++) {
        scanf("%d", &v2[i]);
    }

    intercala(v1, q1, v2, q2);

    return 0;
}