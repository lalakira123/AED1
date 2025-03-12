#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void printVetor(char **v, int n) {
    for(int i = 0; i < n; i++) {
        printf("%s%s", v[i], i==n-1?"\n":" ");
    }
}

void bubbleSort(char **v, int n) {
    int count = 0;

    for(int i = 0; i < n-1; i++) {
        for(int j = 0; j < n-1-i; j++) {
            if(strcmp(v[j], v[j+1]) > 0) {
                char *aux = v[j+1];
                v[j+1] = v[j];
                v[j] = aux;
                
                count++;
                printVetor(v, n);
            }
        }
    }

    printf("TROCAS: %d\n", count);
}

int main() {
    int n;
    char **v;

    scanf("%d", &n);

    v = (char**)malloc(n * sizeof(char *));

    for(int i = 0; i < n; i++) {
        v[i] = (char*)malloc(100 * sizeof(char));

        scanf("%s", v[i]);
    }

    bubbleSort(v, n);

    return 0;
}