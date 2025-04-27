#include <stdio.h>
#include <stdlib.h>

struct tNo {
    int chave;
    struct tNo *pai;
    struct tNo *esquerda;
    struct tNo *direita;
};

struct tArvore {
    int qtd;
    struct tNo *raiz;
};

struct tNo *raiz(struct tArvore *t) {
    return t->raiz;
}

void inserir(struct tArvore *t, struct tNo *novo) {
    struct tNo *filho = raiz(t), *pai = NULL;

    while(filho != NULL) {
        pai = filho;
        if(filho->chave <= novo->chave) {
            filho = filho->direita;
        } else {
            filho = filho->esquerda;
        }
    }

    t->qtd++;
    if(pai != NULL) { //insere na folha
        novo->pai = pai;
        if(pai->chave < novo->chave) {
            pai->direita = novo;
        } else {
            pai->esquerda = novo;
        }
    } else { //insere na raiz
        t->raiz = novo;
    }
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

    if(pai->direita == no) {
        pai->direita = no->esquerda;
    } else {
        pai->esquerda = no->esquerda;
    }
    
    if(no->esquerda != NULL) {
        no->esquerda->pai = pai;
    }

    no->pai = NULL;
    no->esquerda = NULL;
    return no;
}

struct tNo * remover(struct tArvore *t, int chave) {
    struct tNo *pai = NULL, *filho = raiz(t), *subs = NULL;

    while(filho != NULL && filho->chave != chave) { //filho será o valor a ser removido
        pai = filho;
        if(filho->chave < chave) {
            filho = filho->direita;
        } else {
            filho = filho->esquerda;
        }
    }

    if(filho != NULL) {
        if(filho->direita == NULL && filho->esquerda == NULL) { //folha
            filho->pai = NULL;
            if(pai->direita == filho) {
                pai->direita = NULL;
            } else if(pai->esquerda == filho) {
                pai->esquerda = NULL;
            } else {
                t->raiz = NULL;
            }
        } else if(filho->direita != NULL && filho->esquerda != NULL) { //pai de 2 filhos
            subs = removerAntecessor(antecessor(filho));

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
                t->raiz = subs;
            }

            if(filho->esquerda != NULL) {
                filho->esquerda->pai = subs;
            }

            if(filho->direita != NULL) {
                filho->direita->pai = subs;
            }
        } else { //pai de 1 filho
            if(pai != NULL) {
                if(pai->esquerda == filho) {
                    if(filho->esquerda != NULL) {
                        filho->esquerda->pai = pai;   
                        pai->esquerda = filho->esquerda 
                    } else {    
                        filho->direita->pai = pai;
                        pai->esquerda = filho->direita;
                    }
                } else {
                    if(filho->esquerda != NULL) {
                        filho->esquerda->pai = pai;
                        pai->direita = filho->esquerda;
                    } else {
                        filho->direita->pai = pai;
                        pai->direita = filho->direita;
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
        filho->esquerda = NULL;
        filho->direita = NULL;
        t->qtd--;
    }

    return filho;
}

int main() {
    return 0;
}