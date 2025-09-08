#include <stdio.h>
#include <string.h>
#include <ctype.h> 

#define MaxLettres 50
#define Essaies 10

int main() {
    char motSecret[MaxLettres];
    char motAffiche[MaxLettres];
    char lettresProposees[26] = {0};
    int lettresTrouvees = 0;
    int tentativesRestantes = Essaies;
    int longueurMot;
    char lettre;
        
    printf("Entrez le mot secret : ");
    scanf("%s", motSecret);

    longueurMot = strlen(motSecret);
    for (int i = 0; i < longueurMot; i++) {
        motSecret[i] = tolower(motSecret[i]);
        motAffiche[i] = '_';
    }
    motAffiche[longueurMot] = '\0';

    printf("Le mot contient %d lettres.\n", longueurMot);
    printf("Vous avez %d essaies.\n\n", Essaies);

    while (tentativesRestantes > 0 && lettresTrouvees < longueurMot) {
        int lettreTrouvee = 0;
        printf("Mot : %s\n", motAffiche);
        printf("Essaies restants : %d\n", tentativesRestantes);
        printf("Lettres proposées : ");
        for (int i = 0; i < 26; i++) {
            if (lettresProposees[i]) {
                printf("%c ", 'a' + i);
            }
        }
        printf("\n\n");

        printf("Donnez une lettre : ");
        scanf(" %c", &lettre);
        lettre = tolower(lettre);  


        if (lettre < 'a' || lettre > 'z') {
            printf("Caractère invalide, entrez une lettre a-z.\n\n");
            continue;
        }

        if (lettresProposees[lettre - 'a']) {
            printf("Vous avez déjà donné la lettre '%c' !\n\n", lettre);
            continue;
        }

        lettresProposees[lettre - 'a'] = 1;

        for (int i = 0; i < longueurMot; i++) {
            if (motSecret[i] == lettre) {
                motAffiche[i] = lettre;
                lettresTrouvees++;
                lettreTrouvee = 1;
            }
        }

        if (lettreTrouvee) {
            printf("Good tu as trouvé une lettre !\n\n");
        } else {
            printf("La lettre '%c' n'est pas dans le mot.\n\n", lettre);
            tentativesRestantes--;
        }
    }

    printf("Mot secret : %s\n", motSecret);
    printf("Votre résultat : %s\n\n", motAffiche);
    
    if (lettresTrouvees == longueurMot) {
        printf("Bravo ! Vous avez trouvé le mot.\n");
    } else {
        printf("Perdu ! Vous n'avez plus de tentatives.\n");
    }
    
    return 0;
}
