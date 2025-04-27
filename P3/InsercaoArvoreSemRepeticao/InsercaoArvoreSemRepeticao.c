#include <stdio.h>
#include <stdlib.h>

struct tNo {
    struct tNo *pai;
    struct tNo *esquerda;
    struct tNo *direita;
    int chave;
};

struct tArvore {
    struct tNo *raiz;
};

struct tNo * criarNo(int chave) {
    struct tNo *no = (struct tNo *)malloc(sizeof(struct tNo));
    if(no != NULL) {
        no->chave = chave;
        no->pai = NULL;
        no->esquerda = NULL;
        no->direita = NULL;
    }
    return no;
}

struct tArvore * criarArvore() {
    struct tArvore *arvore = (struct tArvore *)malloc(sizeof(struct tArvore));
    if(arvore != NULL) {
        arvore->raiz = NULL;
    }
    return arvore;
}

struct tNo * raiz(struct tArvore *arvore) {
    return arvore->raiz;
}

int arvoreVazia(struct tArvore *arvore) {
    return raiz(arvore) == NULL;
}

void inserir(struct tArvore *arvore, struct tNo *novo) {
    struct tNo *pai = NULL, *filho = raiz(arvore);

    while(filho != NULL) {
        pai = filho;
        if(filho->chave < novo->chave) {
            filho = filho->direita;
        } else if(filho->chave > novo->chave) {
            filho = filho->esquerda;
        } else {
            printf("Chave %d ja existe na arvore!\n", novo->chave);
            return;
        }
    }

    if(pai != NULL) {
        novo->pai = pai;
        if(pai->chave < novo->chave) {
            pai->direita = novo;
        } else {
            pai->esquerda = novo;
        }
    } else {
        arvore->raiz = novo;
    }
}

int main() {
    int n, chave;
    struct tArvore *arvore = criarArvore();
    struct tNo *novo;
    scanf("%d", &n);

    int i;
    for(i = 0; i < n; i++) {
        scanf("%d", &chave);
        novo = criarNo(chave);
        inserir(arvore, novo);
    }

    return 0;
}