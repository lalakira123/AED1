#include <stdio.h>
#include <stdlib.h>

int main() {
    int n, *v, maior = 0, segundoMaior = 0;

    scanf("%d", &n);

    v = (int*)malloc(n * sizeof(int));

    for(int i = 0; i < n; i++) {
        scanf("%d", &v[i]);
    }

    for(int i = 0; i < n; i++) {
        if(v[i] > v[maior]) {
            maior = i;
        } 
    }

    if(maior == segundoMaior) {
        segundoMaior++;
    }

    for(int i = 0; i < n; i++) {
        if(v[i] > v[segundoMaior] && v[i] <= v[maior] && maior != i) {
            segundoMaior = i;
        }
    }

    printf("%d %d\n", segundoMaior, v[segundoMaior]);

    return 0;
}