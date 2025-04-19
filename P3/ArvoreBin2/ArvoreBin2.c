#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct tNo {
    int chave;
    struct tNo * pai;
    struct tNo * esquerda;
    struct tNo * direita;
};

struct tArvore {
    struct tNo * raiz;
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

void preOrder(struct tNo *no, int *count) {
    if(no != NULL) {
        if (*count > 0) printf(" ");
        printf("%d", no->chave);
        (*count)++;
        preOrder(no->esquerda, count);
        preOrder(no->direita, count);
    }
}

void inOrder(struct tNo *no, int *count) {
    if(no != NULL) {
        inOrder(no->esquerda, count);
        if (*count > 0) printf(" ");
        printf("%d", no->chave);
        (*count)++;
        inOrder(no->direita, count);
    }
}

void postOrder(struct tNo *no, int *count) {
    if(no != NULL) {
        postOrder(no->esquerda, count);
        postOrder(no->direita, count);
        if (*count > 0) printf(" ");
        printf("%d", no->chave);
        (*count)++;
    }
}

void inserir(struct tArvore *arvore, struct tNo *novo) {
    struct tNo *pai = NULL, *filho = raiz(arvore);

    while(filho != NULL) {
        pai = filho;
        if(filho->chave <= novo->chave) {
            filho = filho->direita;
        } else {
            filho = filho->esquerda;
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
        arvore->raiz = novo;
    }
}

struct tNo * sucessor(struct tNo *no) {
    struct tNo *pai = NULL;
    no = no->direita;
    while(no != NULL) {
        pai = no;
        no = no->esquerda;
    }
    return pai;
}

struct tNo * removerSucessor(struct tNo *no) {
    struct tNo *pai = no->pai;

    if(pai->esquerda == no) {
        pai->esquerda = no->direita;
    } else {
        pai->direita = no->direita;
    }

    if(no->direita != NULL) {
        no->direita->pai = pai;
    }
    no->pai = NULL;
    no->direita = NULL;
    return no;
}

struct tNo * remover(struct tArvore *arvore, int chave) {
    struct tNo *pai = NULL, *filho = raiz(arvore), *subs;

    while(filho != NULL && filho->chave != chave) {
        pai = filho;
        if(filho->chave <= chave) {
            filho = filho->direita;
        } else {
            filho = filho->esquerda;
        }
    }

    if(filho != NULL) { //achou filho
        if(filho->esquerda == NULL && filho->direita == NULL) {
            if(pai != NULL) {
                if(pai->esquerda == filho) {
                    pai->esquerda = NULL;
                } else {
                    pai->direita = NULL;
                }
            } else {
                arvore->raiz = NULL;
            }
        } else if(filho->esquerda != NULL && filho->direita != NULL) {
            subs = removerSucessor(sucessor(filho));

            subs->pai = pai;
            subs->esquerda = filho->esquerda;
            subs->direita = filho->direita;

            if(pai != NULL) {
                if(pai->esquerda == filho) {
                    pai->esquerda = subs;
                } else {
                    pai->direita = subs;
                }
            } else {
                arvore->raiz = subs;
            }

            if(filho->esquerda != NULL) {
                filho->esquerda->pai = subs;
            }
            if(filho->direita != NULL) {
                filho->direita->pai = subs;
            }
        } else {
            if(pai != NULL) {
                if(pai->esquerda == filho) {
                    if(filho->esquerda != NULL) {
                        pai->esquerda = filho->esquerda;
                        filho->esquerda->pai = pai;
                    } else {
                        pai->esquerda = filho->direita;
                        filho->direita->pai = pai;
                    }
                } else {
                    if(filho->esquerda != NULL) {
                        pai->direita = filho->esquerda;
                        filho->esquerda->pai = pai;
                    } else {
                        pai->direita = filho->direita;
                        filho->direita->pai = pai;
                    }
                }
            } else {
                if(filho->esquerda != NULL) {
                    arvore->raiz = filho->esquerda;
                    filho->esquerda->pai = NULL;
                } else {
                    arvore->raiz = filho->direita;
                    filho->direita->pai = NULL;
                }
            }
        }

        filho->pai = NULL;
        filho->esquerda = NULL;
        filho->direita = NULL;
    }

    return filho;
}

int main() {
    char opc[20];
    int chave, count;
    struct tArvore *arvore = criarArvore();
    struct tNo *novo;

    while(scanf("%s", opc) != EOF) {
        if(strcmp(opc, "insert") == 0 || strcmp(opc, "delete") == 0) {
            scanf("%d", &chave);
        }

        if(strcmp(opc, "insert") == 0) {
            novo = criarNo(chave);
            inserir(arvore, novo);
        } else if(strcmp(opc, "delete") == 0) {
            novo = remover(arvore, chave);
            if(novo != NULL) {
                printf("%d\n", novo->chave);
            }
        } else if(strcmp(opc, "pre-order") == 0) {
            count = 0;
            if(!arvoreVazia(arvore)) {
                preOrder(raiz(arvore), &count);
                printf("\n");
            }
        } else if(strcmp(opc, "in-order") == 0) {
            count = 0;
            if(!arvoreVazia(arvore)) {
                inOrder(raiz(arvore), &count);
                printf("\n");
            }
        } else if(strcmp(opc, "post-order") == 0) {
            count = 0;
            if(!arvoreVazia(arvore)) {
                postOrder(raiz(arvore), &count);
                printf("\n");
            }
        }
    }

    return 0;
}