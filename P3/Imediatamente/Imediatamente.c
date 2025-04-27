#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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
    struct tArvore *t = (struct tArvore *)malloc(sizeof(struct tArvore));
    if(t != NULL) {
        t->raiz = NULL;
    }
    return t;
}

struct tNo * raiz(struct tArvore *t) {
    return t->raiz;
}

void inserir(struct tArvore *t, struct tNo *novo) {
    struct tNo *pai = NULL, *filho = raiz(t);

    while(filho != NULL) {
        pai = filho;
        if(filho->chave < novo->chave) {
            filho = filho->direita;
        } else if(filho->chave > novo->chave){
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

struct tNo * buscaNo(struct tArvore *t, int chave) {
    struct tNo *pai = NULL, *filho = raiz(t);

    while(filho != NULL && filho->chave != chave) {
        pai = filho;
        if(filho->chave < chave) {
            filho = filho->direita;
        } else if(filho->chave > chave) {
            filho = filho->esquerda;
        }
    }

    return filho;
}

struct tNo *immediatelyGreater(struct tNo *no) {
    struct tNo *pai = no->pai;

    no = no->direita;
    if(no == NULL) {
        return no;
    }

    while(no != NULL) {
        pai = no;
        no = no->esquerda;
    }

    return pai;
}

struct tNo * immediatelyLess(struct tNo *no) {
    struct tNo *pai = no->pai;
    
    no = no->esquerda;
    if(no == NULL) {
        return no;
    }

    while(no != NULL) {
        pai = no;
        no = no->direita;
    }

    return pai;
}

int main() {
    char opc[20];
    struct tArvore *t = criarArvore();
    int chave;
    struct tNo *noImediatamente;
    struct tNo *noBuscado;

    while(scanf("%s", opc) != EOF) {
        scanf("%d", &chave);

        if(strcmp(opc, "insert") == 0) {
            inserir(t, criarNo(chave));
        } else if(strcmp(opc, "immediately-greater") == 0) {
            noBuscado = buscaNo(t, chave);
            if(noBuscado != NULL) {
                noImediatamente = immediatelyGreater(noBuscado);
                if(noImediatamente != NULL) {
                    printf("%d\n", noImediatamente->chave);
                } else {
                    printf("nao ha imediatamente maior que %d\n", chave);
                }
            }
        } else if(strcmp(opc, "immediately-less") == 0) {
            noBuscado = buscaNo(t, chave);
            if(noBuscado != NULL) {
                noImediatamente = immediatelyLess(noBuscado);
                if(noImediatamente != NULL) {
                    printf("%d\n", noImediatamente->chave);
                } else {
                    printf("nao ha imediatamente menor que %d\n", chave);
                }
            }
        }
    }
}