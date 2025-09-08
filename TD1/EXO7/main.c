#include <stdio.h>
#include <stdlib.h>
#include <time.h>


void tri_selection(int tab[], int n) {
    int i, j, min_index, temp;
    for (i = 0; i < n - 1; i++) {
        min_index = i;
        for (j = i + 1; j < n; j++) {
            if (tab[j] < tab[min_index]) {
                min_index = j;
            }
        }
        temp = tab[i];
        tab[i] = tab[min_index];
        tab[min_index] = temp;
    }
}


void affichertab(int tab[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%d", tab[i]);
        if (i < n - 1) {
            printf(", ");
        }
    }
    printf("]\n");
}

int main() {
    int n;
    int *tab;
    printf("Entrez le nombre d'elements du tab : ");
    scanf("%d", &n);
    tab = (int*)malloc(n * sizeof(int));
    if (tab == NULL) {
        return 1;
    }

    for (int i = 0; i < n; i++) {
        tab[i] = rand() % 101; 
    }

    printf("\nAvant le tri :\n");
    affichertab(tab, n);
    tri_selection(tab, n);
    printf("\nApres le tri :\n");
    affichertab(tab, n);
    return 0;
}
