#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void printaVetor(char **v, int n) {
    for (int i = 0; i < n; i++) {
        if (i == n - 1) {
            printf("%s\n", v[i]);
        } else {
            printf("%s ", v[i]);
        }
    }
}

void ordenaBubbleString(char **v, int n) {
    int count = 0;

    printaVetor(v, n);

    for(int i = 0; i < n - 1; i++) {
        for(int j = 0; j < n - 1 - i; j++) {
            if (strcmp(v[j], v[j + 1]) > 0) {
                char *aux = v[j + 1];
                v[j + 1] = v[j];
                v[j] = aux;

                count++;
                printaVetor(v, n);
            }
        }
    }

    printaVetor(v, n);
    printf("Trocas: %d\n", count);
}

int main() {
    int n;
    char **v;

    scanf("%d", &n);

    v = (char**)malloc(n * sizeof(char *));

    for(int i = 0; i < n; i++) {
        v[i] = (char *)malloc(100 * sizeof(char));

        scanf("%s", v[i]); 
    }

    ordenaBubbleString(v, n);
    
    return 0;
}