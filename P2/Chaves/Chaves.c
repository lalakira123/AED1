#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct tItem {
    char nome[102];
};

struct tPilha {
    struct tItem *linhas;
    int tamanho;
    int topo;
};

struct tPilha criarPilha(int n) {
    struct tPilha p;
    p.linhas = (struct tItem *)malloc(n * sizeof(struct tItem));
    p.tamanho = n;
    p.topo = 0;
    return p;
}

struct tItem criarItem(char *item) {
    struct tItem it;
    strcpy(it.nome, item);
    return it;
}

int validarChaves(struct tPilha *p) {
    int i, j;

    for(i = 0; i < p->tamanho; i++) {
        for(j = 0; j < strlen(p->linhas[i].nome); j++) {
            if(p->linhas[i].nome[j] == '{') {
                p->topo++;
            } else if(p->linhas[i].nome[j] == '}') {
                p->topo--;
                if(p->topo < 0) {
                    return 0;
                }
            }
        }
    }

    return 1;
}

int main() {
    int n, validacao;
    struct tPilha p;

    scanf("%d", &n);

    getchar();

    p = criarPilha(n);

    int i;
    for(i = 0; i < n; i++) {
        char item[102];
        
        fgets(item, 102, stdin);

        struct tItem it = criarItem(item);

        p.linhas[i] = it;
    }
    
    if(!validarChaves(&p)) {
        printf("N\n");
        return 0;
    }

    printf("%s\n", p.topo==0?"S":"N");

    return 0;
}