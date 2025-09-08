#include <stdio.h>
#include <stdlib.h>

int** allouer_tab_2d(int n, int m) {
    int** tab = (int**)malloc(n * sizeof(int*));
    if (tab == NULL) {
        printf("Erreur d'allocation mémoire\n");
        exit(1);
    }
    for (int i = 0; i < n; i++) {
        tab[i] = (int*)malloc(m * sizeof(int));
        if (tab[i] == NULL) {
            printf("Erreur d'allocation mémoire\n");
            exit(1);
        }
    }    
    return tab;
}

void remplir_aleatoire(int** tab, int n, int m) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            tab[i][j] = rand() % 100; 
        }
    }
}

void afficher_tab(int** tab, int n, int m) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            printf("%3d ", tab[i][j]);
        }
        printf("\n");
    }
}

int comparer(const void* a, const void* b) {
    return (*(int*)a - *(int*)b);
}

void trier_colonnes(int** tab, int n, int m) {
    int* colonne = (int*)malloc(n * sizeof(int));
    if (colonne == NULL) {
        printf("Erreur d'allocation mémoire\n");
        exit(1);
    }
    for (int j = 0; j < m; j++) {
        for (int i = 0; i < n; i++) {
            colonne[i] = tab[i][j];
        }
        qsort(colonne, n, sizeof(int), comparer);
        for (int i = 0; i < n; i++) {
            tab[i][j] = colonne[i];
        }
    }
}

int main() {
    int n, m;
    printf("Entrez le nombre de lignes (n): ");
    scanf("%d", &n);
    printf("Entrez le nombre de colonnes (m): ");
    scanf("%d", &m);
    int** tab = allouer_tab_2d(n, m);
    remplir_aleatoire(tab, n, m);
    printf("\ntab avant le tri:\n");
    afficher_tab(tab, n, m);
    trier_colonnes(tab, n, m);
    printf("\ntab après tri des colonnes:\n");
    afficher_tab(tab, n, m);
    return 0;
}
