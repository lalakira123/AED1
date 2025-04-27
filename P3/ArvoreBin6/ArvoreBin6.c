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

int arvoreVazia(struct tArvore *t) {
    return t->raiz == NULL;
}

void preOrder(struct tNo *no, int *count) {
    if(no != NULL) {
        if(*count > 0) printf(" ");
        printf("%d", no->chave);
        (*count)++;
        preOrder(no->esquerda, count);
        preOrder(no->direita, count);
    }
}

void inOrder(struct tNo *no, int *count) {
    if(no != NULL) {
        inOrder(no->esquerda, count);
        if(*count > 0) printf(" ");
        printf("%d", no->chave);
        (*count)++;
        inOrder(no->direita, count);
    }
}

void postOrder(struct tNo *no, int *count) {
    if(no != NULL) {
        postOrder(no->esquerda, count);
        postOrder(no->direita, count);
        if(*count > 0) printf(" ");
        printf("%d", no->chave);
        (*count)++;
    }
}

void inserir(struct tArvore *t, struct tNo *novo) {
    struct tNo *pai = NULL, *filho = raiz(t);

    while(filho != NULL) {
        pai = filho;
        if(filho->chave < novo->chave) { //inclui na esquerda se valor repetido
            filho = filho->direita;
        } else {
            filho = filho->esquerda;
        }
    }

    if(pai != NULL) {
        novo->pai = pai;
        if(pai->chave < novo->chave) { //inclui na esquerda se valor repetido
            pai->direita = novo;
        } else {
            pai->esquerda = novo;
        }
    } else {
        t->raiz = novo;
    }
}

struct tNo *sucessor(struct tNo *no) {
    struct tNo *pai = no->pai;

    no = no->direita;
    while(no != NULL) {
        pai = no;
        no = no->esquerda;
    }

    return pai;
}

struct tNo * removerSucessor(struct tNo *no) {
    struct tNo *pai = no->pai;

    if(pai->direita == no) {
        pai->direita = no->direita;
    } else {
        pai->esquerda = no->direita;;
    }

    if(no->direita != NULL) {
        no->direita->pai = pai;
    }

    no->pai = NULL;
    no->direita = NULL;
    return no;
}

struct tNo * antecessor(struct tNo *no) {
    struct tNo *pai = no->pai;
    
    no = no->esquerda;
    while(no != NULL) {
        pai = no;
        no = no->direita;
    }

    return pai;
}

struct tNo * removerAntecessor(struct tNo *no) {
    struct tNo *pai = no->pai;

    if(pai->esquerda == no) {
        pai->esquerda = no->esquerda;
    } else {    
        pai->direita = no->esquerda;
    }

    if(no->esquerda != NULL) {
        no->esquerda->pai = pai;
    }

    no->esquerda = NULL;
    no->pai = NULL;
    return no;
}

struct tNo * remover(struct tArvore *t, int chave) {
    struct tNo *pai = NULL, *filho = raiz(t), *subs = NULL;

    while(filho != NULL && filho->chave != chave) {
        pai = filho;
        if(filho->chave <= chave) {
            filho = filho->direita;
        } else {
            filho = filho->esquerda;
        }
    }

    if(filho != NULL) {
        if(filho->esquerda == NULL && filho->direita == NULL) {
            if(pai != NULL) {
                if(pai->esquerda == filho) {
                    pai->esquerda = NULL;
                } else {
                    pai->direita = NULL;
                }
            } else {
                t->raiz = NULL;
            }
        } else if(filho->esquerda != NULL && filho->direita != NULL) {
            subs = removerSucessor(sucessor(filho));

            subs->pai = filho->pai;
            subs->esquerda = filho->esquerda;
            subs->direita = filho->direita;

            if(pai != NULL) {
                if(pai->esquerda == filho) {
                    pai->esquerda = subs;
                } else {
                    pai->direita = subs;
                }
            } else {    
                t->raiz = subs;
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
                    t->raiz = filho->esquerda;
                    filho->esquerda->pai = NULL;
                } else {
                    t->raiz = filho->direita;
                    filho->direita->pai = NULL;
                }
            }
        }

        filho->pai = NULL;
        filho->direita = NULL;
        filho->esquerda = NULL;
    }

    return filho;
}

int main() {
    char opc[20];
    struct tArvore *t = criarArvore();
    struct tNo *novo;
    int chave, count = 0;

    while(scanf("%s", opc) != EOF) {
        if(strcmp("insert", opc) == 0 || strcmp("delete", opc) == 0) {
            scanf("%d", &chave);
        }

        if(strcmp(opc, "insert") == 0) {
            novo = criarNo(chave);
            inserir(t, novo);
        } else if(strcmp(opc, "delete") == 0) {
            novo = remover(t, chave);
            if(novo != NULL) {
                printf("%d\n", novo->chave);
            }
        } else if(strcmp(opc, "pre-order") == 0) {
            count = 0;
            if(!arvoreVazia(t)) {
                preOrder(raiz(t), &count);
                printf("\n");
            }
        } else if(strcmp(opc, "in-order") == 0) {
            count = 0;
            if(!arvoreVazia(t)) {
                inOrder(raiz(t), &count);
                printf("\n");
            }
        } else if(strcmp(opc, "post-order") == 0) {
            count = 0;
            if(!arvoreVazia(t)) {
                postOrder(raiz(t), &count);
                printf("\n");
            }
        }
    }
}