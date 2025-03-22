#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void nomicula(char *nome, char *ra, int nomeLength, int raLength) {
    int totalStrings = nomeLength + raLength;
    char *newString = (char*)malloc((totalStrings + 1) * sizeof(char));

    int count = 0;
    int i = 0;

    while (i < nomeLength || i < raLength) {
        if (i < nomeLength) {
            newString[count++] = nome[i];
        }

        if (i < raLength) {
            newString[count++] = ra[i];
        }

        i++;
    }

    newString[count] = '\0';

    printf("%s\n", newString);

    free(newString);
}

int main() {
    char nome[101];
    char ra[12];

    while(scanf("%100s %11s", nome, ra) != EOF) {
        nomicula(nome, ra, strlen(nome), strlen(ra));
    }

    return 0;
}
