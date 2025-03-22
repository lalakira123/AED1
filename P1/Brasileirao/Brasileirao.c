#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char *nome;
    int pontos;
    int vitorias;
    int empates;
    int derrotas;
    int gol;
    int golPro;
    int golContra;
} Equipe;

typedef struct {
    char *time1;
    char *time2;
    char x;
    int ponto1;
    int ponto2;
} Jogo;

void printFinal(Equipe *equipes, int n) {
    for (int i = 0; i < n; i++) {
        if ( i == 0) {
            printf("CAMPEAO: %s\n", equipes[i].nome);   
        } else if ( i == 1) {
            printf("VICE-CAMPEAO: %s\n", equipes[i].nome);
        }
    }

    for (int i = n - 1; i > n - 5; i--) {
        if ( i == n - 1) {
            printf("REBAIXADOS: %s", equipes[i].nome);
        } else if (i == n - 4) {
            printf(" e %s\n", equipes[i].nome);
        } else {
            printf(", %s", equipes[i].nome);
        }
    }

    printf("TABELA FINAL:\n");

    for (int i = 0; i < n; i++) {
        printf("%s ", equipes[i].nome);
        printf("%d ", equipes[i].pontos);
        printf("%d ", equipes[i].vitorias);
        printf("%d ", equipes[i].empates);
        printf("%d ", equipes[i].derrotas);
        printf("%d ", equipes[i].gol);
        printf("%d ", equipes[i].golPro);
        printf("%d\n", equipes[i].golContra);
    }
}

void ordenarPlacar(Equipe *equipes, int n) {
    for(int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - 1 - i; j++) {
            if (equipes[j].pontos < equipes[j+1].pontos) {
                Equipe equipeAux = equipes[j];
                equipes[j] = equipes[j+1];
                equipes[j+1] = equipeAux;
            } else if (
                equipes[j].pontos == equipes[j+1].pontos &&
                equipes[j].vitorias < equipes[j+1].vitorias
            ) {
                Equipe equipeAux = equipes[j];
                equipes[j] = equipes[j+1];
                equipes[j+1] = equipeAux;
            } else if (
                equipes[j].pontos == equipes[j+1].pontos &&
                equipes[j].vitorias == equipes[j+1].vitorias &&
                equipes[j].gol < equipes[j+1].gol
            ) {
                Equipe equipeAux = equipes[j];
                equipes[j] = equipes[j+1];
                equipes[j+1] = equipeAux;
            } else if (
                equipes[j].pontos == equipes[j+1].pontos &&
                equipes[j].vitorias == equipes[j+1].vitorias &&
                equipes[j].gol == equipes[j+1].gol &&
                equipes[j].golPro < equipes[j+1].golPro
            ) {
                Equipe equipeAux = equipes[j];
                equipes[j] = equipes[j+1];
                equipes[j+1] = equipeAux;
            }
        }
    }
}

void distribuirPontos (Equipe *equipes, int indice, int ponto1, int ponto2) {
    if (ponto1 > ponto2) {
        equipes[indice].pontos += 3;
        equipes[indice].vitorias += 1;
    } else if (ponto1 == ponto2) {
        equipes[indice].pontos += 1;
        equipes[indice].empates += 1;
    } else {
        equipes[indice].derrotas += 1;
    }

    equipes[indice].gol += ponto1;
    equipes[indice].gol -= ponto2;

    equipes[indice].golPro += ponto1;
    equipes[indice].golContra += ponto2;
}

void busca(Equipe *equipes, int n, char *chave, int ponto1, int ponto2) {
    for (int i = 0; i < n; i++) {
        if (strcmp(equipes[i].nome, chave) == 0) {
            distribuirPontos(equipes, i, ponto1, ponto2);
            return;
        } 
    }
}

void buscarEquipes(Equipe *equipes, Jogo *jogos, int n) {
    for(int i = 0; i < n * (n - 1); i++) {
        busca(equipes, n, jogos[i].time1, jogos[i].ponto1, jogos[i].ponto2);
        busca(equipes, n, jogos[i].time2, jogos[i].ponto2, jogos[i].ponto1);
    }
}

int main() {
    int numeroEquipes;
    Equipe *equipes;
    Jogo *jogos;

    scanf("%d", &numeroEquipes);

    equipes = (Equipe *)malloc(numeroEquipes * sizeof(Equipe));

    for(int i = 0; i < numeroEquipes; i++) {
        equipes[i].nome = (char *)malloc(50 * sizeof(char));

        scanf("%s", equipes[i].nome);

        equipes[i].pontos = 0;
        equipes[i].vitorias = 0;
        equipes[i].empates = 0;
        equipes[i].derrotas = 0;
        equipes[i].gol = 0;
        equipes[i].golPro = 0;
        equipes[i].golContra = 0;
    }

    jogos = (Jogo *)malloc(numeroEquipes * (numeroEquipes-1) * sizeof(Jogo));

    for(int i = 0; i < numeroEquipes * (numeroEquipes - 1); i++) {
        jogos[i].time1 = (char *)malloc(50 * sizeof(char));
        jogos[i].time2 = (char *)malloc(50 * sizeof(char));

        scanf("%s", jogos[i].time1);
        scanf("%d", &jogos[i].ponto1);
        scanf(" %c", &jogos[i].x);
        scanf("%d", &jogos[i].ponto2);
        scanf("%s", jogos[i].time2);
    }

    buscarEquipes(equipes, jogos, numeroEquipes);
    ordenarPlacar(equipes, numeroEquipes);
    printFinal(equipes, numeroEquipes);

    return 0;
}