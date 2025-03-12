#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void intercalaSubstrings2(char *str1, int n1, int n2) {
    int tam = n1 + n2;
    int i = 0, j = tam - n2, count = 0;

    char newString[tam + 1];

    while (i < n1 || j < tam) {
        if(i < n1 && (j >= tam || str1[i] <= str1[j])) {
            newString[count++] = str1[i++];
        } else {
            newString[count++] = str1[j++];
        }
    }

    newString[count] = '\0';

    printf("%s\n", newString);
}

int main() {
    char stringEntrada[20000];
    int n, m;

    scanf("%20000s", stringEntrada);
    scanf("%d", &n);
    scanf("%d", &m);

    intercalaSubstrings2(stringEntrada, n, m);

    return 0;
}