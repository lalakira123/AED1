#include <stdio.h>
#include <stdlib.h>

void intercalaStrings(char *s1, int n1, char *s2, int n2) {
    int i = 0, j = 0, count = 0;
    char *newString;

    newString = (char*)malloc((n1 + n2) * sizeof(char));

    while(i < n1 || j < n2) {
        if(i < n1 && (j >= n2 || s1[i] <= s2[j])) {
            newString[count++] = s1[i++];
        }

        if(j < n2 && (i >= n1 || s2[j] <= s1[i])) {
            newString[count++] = s2[j++];
        }
    }

    newString[count] = '\0';

    printf("%s\n", newString);

    free(newString);
}

int main(){
    int n1, n2;
    char *s1, *s2;

    scanf("%d", &n1);
    s1 = (char*)malloc(n1 * sizeof(char));
    scanf("%s", s1);

    scanf("%d", &n2);
    s2 = (char*)malloc(n2 * sizeof(char));
    scanf("%s", s2);

    intercalaStrings(s1, n1, s2, n2);

    free(s1);
    free(s2);

    return 0;
}