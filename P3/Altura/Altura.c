#include <stdio.h>
#include <stdlib.h>

struct tNo {
    int chave;
    struct tNo *pai;
    struct tNo *direita;
    struct tNo *esquerda;
};

struct tArvore {
    struct tNo *raiz;
};

struct tNo * criarNo(int chave) {
    struct tNo *no = (struct tNo*)malloc(sizeof(struct tNo));
    if(no != NULL) {
        no->chave = chave;
        no->pai = NULL;
        no->esquerda = NULL;
        no->direita = NULL;
    }
    return no;
}

struct tArvore * criarArvore() {
    struct tArvore *t = (struct tArvore*)malloc(sizeof(struct tArvore));
    if(t != NULL) {
        t->raiz = NULL;
    }
    return t;
}

struct tNo * raiz(struct tArvore *t) {
    return t->raiz;
}

int altura(struct tNo* no) {
    int altEsq, altDir;
    if(no != NULL) {
      altEsq = altura(no->esquerda);
      altDir = altura(no->direita);
      return (altEsq > altDir ? altEsq : altDir) + 1;
    }
    return -1;
};

void inserir(struct tArvore *t, struct tNo *novo) {
    struct tNo *pai = NULL, *filho = raiz(t);

    while(filho != NULL) {
        pai = filho;
        if(filho->chave < novo->chave) {
            filho = filho->direita;
        } else if(filho->chave > novo->chave) {
            filho = filho->esquerda;
        } else {
            return;
        }
    }

    if(pai != NULL) {
        novo->pai = pai;
        if(pai->chave <= novo->chave) {
            pai->direita = novo;
        } else {
            pai->esquerda = novo;
        }
    } else {
        t->raiz = novo;
    }
}

int main() {
    int n, valor;
    struct tArvore *t = criarArvore();

    scanf("%d", &n);

    int i;
    for(i = 0; i < n; i++) {
        scanf("%d", &valor);
        inserir(t, criarNo(valor));
    }

    printf("%d\n", altura(raiz(t)));

    return 0;
}