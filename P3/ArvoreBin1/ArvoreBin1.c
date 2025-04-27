#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct tNo {
    int chave;
    struct tNo *pai;
    struct tNo *esquerda;
    struct tNo *direita;
};

struct tArvore {
    struct tNo *raiz;
};

struct tNo * criarNo(int chave) {
    struct tNo *no = (struct tNo *)malloc(sizeof(struct tNo));
    if (no != NULL) {
        no->chave = chave;
        no->pai = NULL;
        no->esquerda = NULL;
        no->direita = NULL;
    }
    return no;
}

struct tArvore * criarArvore() {
    struct tArvore *arvore = (struct tArvore *)malloc(sizeof(struct tArvore));
    if (arvore != NULL) {
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

void preOrder(struct tNo *no) {
    if(no != NULL) {
        printf("%d\n", no->chave);
        preOrder(no->esquerda);
        preOrder(no->direita);
    }
}

void inOrder(struct tNo *no) {
    if(no != NULL) {
        inOrder(no->esquerda);
        printf("%d\n", no->chave);
        inOrder(no->direita);
    }
}

void postOrder(struct tNo *no) {
    if(no != NULL) {
        postOrder(no->esquerda);
        postOrder(no->direita);
        printf("%d\n", no->chave);
    }
}

void inserir(struct tArvore *arvore, struct tNo *novo) {
    struct tNo *pai = NULL, *filho = raiz(arvore);

    while(filho != NULL) {
        pai = filho;
        if(filho->chave <= novo->chave) { //se for repetido inclui na subarvore da direita
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

    if(pai->esquerda == no) { // caso que conseguiu percorrer após a primeira direita até o final esquerda
        pai->esquerda = no->direita; //o valor atribuido só pode ser o filho da direita, pois nó já é o ultimo da esquerda
    } else { //caso que percorreu só uma casa para direita e esse é o sucessor e não há filhos a esquerda
        pai->direita = no->direita; //portanto o filho a ser atribuido só pode ser o da direita do nó
    }

    if(no->direita != NULL) { //caso o filho da direita do nó não seja nulo, precisa atribuir o pai a esse nó
        no->direita->pai = pai;
    }
    no->pai = NULL; //exclusao
    no->direita = NULL;
    return no;
}

struct tNo * remover(struct tArvore *arvore, int chave) {
    struct tNo *pai = NULL, *filho = raiz(arvore), *subs = NULL;

    while(filho != NULL && filho->chave != chave) { //para na que encontrou primeiro
        pai = filho;
        if(filho->chave <= chave) {
            filho = filho->direita;
        } else {
            filho = filho->esquerda;
        }
    }

    if(filho != NULL) { //achou filho
        if(filho->esquerda == NULL && filho->direita == NULL) { //folha
            if(pai != NULL) { //nao eh raiz/
                if(pai->esquerda == filho) { //filho esta na esquerda do pai
                    pai->esquerda = NULL;
                } else { //filho esta na direita do pai
                    pai->direita = NULL;
                }
            } else { // raiz
                arvore->raiz = NULL;
            }
        } else if(filho->esquerda != NULL && filho->direita != NULL) { //pai 2 filhos
            subs = removerSucessor(sucessor(filho));

            subs->pai = pai;
            subs->esquerda = filho->esquerda;
            subs->direita = filho->direita;

            if(pai != NULL) {// nao eh raiz
                if(pai->esquerda == filho) {
                    pai->esquerda = subs;
                } else {
                    pai->direita = subs;
                }
            } else {// eh raiz
                arvore->raiz = subs;
            }

            if(filho->esquerda != NULL) { //caso os filhos do filho exista, precisam ser referenciados o sub como pai
                filho->esquerda->pai = subs;
            }
            if(filho->direita != NULL) {
                filho->direita->pai = subs;
            }
        } else { //pai 1 filho
            if(pai != NULL) { //nao eh raiz
                if(pai->esquerda == filho) { //geralmente pais que tem 1 filho, os filhos só podem ter 1 filho
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
    int chave;
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
            preOrder(raiz(arvore));
        } else if(strcmp(opc, "in-order") == 0) {
            inOrder(raiz(arvore));
        } else if(strcmp(opc, "post-order") == 0) {
            postOrder(raiz(arvore));
        }
    }

    return 0;
}