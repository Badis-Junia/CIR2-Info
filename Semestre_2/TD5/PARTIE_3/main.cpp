#include <vector>
#include <string>
#include <iostream>

// Question I
const int TAILLEDUGRAPHE = 6;
const int INFINI = 9999999;

// ---------------------------------------------------------

// Question II
std::vector<std::string> vecSommets;
int arcs [TAILLEDUGRAPHE][TAILLEDUGRAPHE];
int cheminCourt [TAILLEDUGRAPHE][TAILLEDUGRAPHE];
int pointChemin [TAILLEDUGRAPHE][TAILLEDUGRAPHE];

// ---------------------------------------------------------

// Question XI
void afficherChemin (int sommet1, int sommet2, bool & premier) {
    int suivant = pointChemin[sommet1][sommet2];
    if (suivant==-1 || sommet1 == sommet2 || suivant == sommet1 || suivant == sommet2)
        return;
    afficherChemin (sommet1, suivant, premier);
    if (premier) {
        std::cout << " \t\t par ";
        premier = false; }
    else {
        std::cout << " et "; }
    std::cout << vecSommets[suivant];
    afficherChemin (suivant, sommet2, premier);
}

// ---------------------------------------------------------

// Question XIV
void afficherCheminMieux(int sommet1, int sommet2, bool &premier) {
    int suivant = pointChemin[sommet1][sommet2];

    if (suivant == -1 || suivant == sommet1 || suivant == sommet2)
        return;

    afficherChemin(sommet1, suivant, premier);

    if (premier) {
        std::cout << " \t\t par ";
        premier = false;
    } else {
        std::cout << " et ";
    }
    std::cout << vecSommets[suivant];

    afficherChemin(suivant, sommet2, premier);
}

// ---------------------------------------------------------

// Question XV
void affichagePCCh() {
    for (int i = 0; i < TAILLEDUGRAPHE; i++) {
        for (int j = 0; j < TAILLEDUGRAPHE; j++) {
            if (i != j && cheminCourt[i][j] != INFINI) {
                std::cout << "Chemin le plus court de " << vecSommets[i] << " à " << vecSommets[j] << " (distance = " << cheminCourt[i][j] << ")";
                bool premier = true; 
                afficherChemin(i, j, premier); 
                std::cout << std::endl;
            }
        }
    }
}

// ---------------------------------------------------------

int main() {


// Question III
    // Le tableau fait très clairement penser à une matrice d'adjacence car chaque ligne correspond à un sommet, pour les colonnes aussi.

    // ---------------------------------------------------------

// Question IV
    // Je prends les villes de Lille, Paris, Angers, Bordeaux, Toulouse et Marseille
    // Lille    -> Paris
    // Lille    -> Angers
    // Paris    -> Angers
    // Paris    -> Bordeaux
    // Angers   -> Bordeaux
    // Bordeaux -> Toulouse
    // Bordeaux -> Marseille
    // Toulouse -> Marseille

    // ---------------------------------------------------------

// Question V 
    vecSommets.push_back("Lille");
    vecSommets.push_back("Paris");
    vecSommets.push_back("Angers");
    vecSommets.push_back("Bordeaux");
    vecSommets.push_back("Toulouse");
    vecSommets.push_back("Marseille");

    // ---------------------------------------------------------

// Question VI
    for (int i = 0; i < TAILLEDUGRAPHE; i++) {
        for (int j = 0; j < TAILLEDUGRAPHE; j++) {
            arcs[i][j] = 0;
        }
    }

    arcs[0][1] = 220;  // Lille    -> Paris
    arcs[0][2] = 500;  // Lille    -> Angers
    arcs[1][2] = 280;  // Paris    -> Angers
    arcs[1][3] = 600;  // Paris    -> Bordeaux
    arcs[2][3] = 350;  // Angers   -> Bordeaux
    arcs[3][4] = 250;  // Bordeaux -> Toulouse
    arcs[3][5] = 500;  // Bordeaux -> Marseille
    arcs[4][5] = 200;  // Toulouse -> Marseille

    // ---------------------------------------------------------

// Question VII 
    for (int i = 0; i < TAILLEDUGRAPHE; i++) {
        for (int j = 0; j < TAILLEDUGRAPHE; j++) {
            pointChemin[i][j] = -1;
            if (i == j) {
                cheminCourt[i][j] = 0;
            }
            else if (arcs[i][j] != 0) {
                pointChemin[i][j] = i;
                cheminCourt[i][j] = arcs[i][j];
            }
            else {
                cheminCourt[i][j] = INFINI;
            }
        }
    }

    // ---------------------------------------------------------

// Question VIII
    // On cherche à savoir si passer par un sommet intermédiaire k a une distance moins grande que la distance entre i et j.
    // Que ce soit le meilleure chemin en bref.
    // On vérifie si c'est le cas pour un chemin, et si c'est le cas, on change le tableau du chemin court et pointchemin.
    // Exemple : 
    //
    // 0 -> 1 = 5
    // 1 -> 2 = 3
    // 0 -> 2 = 15
    //
    //     0     1     2
    // 0 [ 0     5    15 ]
    // 1 [ inf   0     3 ]
    // 2 [ inf  inf    0 ]
    //
    // 0 -> 1 -> 2 = 5 + 3 = 8. Mais 8 < 15, on peut faire mieux alors comme distance
    // Soit : 
    // cheminCourt[0][2] = 8
    // pointChemin[0][2] = 1
    //
    // Donc : 
    //     0     1     2
    // 0 [ 0     5     8 ]
    // 1 [ inf   0     3 ]
    // 2 [ inf  inf    0 ]
    //
    // S'il existe un intérmédiaire k, alors pointChemin[i][j] = k
    // donc le chemin est chemin(i -> k) + chemin(k -> j) (relation de chasles)

    // ---------------------------------------------------------

// Question IX
    // Nous avons trois boucles imbriqués l'une dans l'autre, ainsi, on a alors n³ comme compléxité. Le nombre maximum d'instructions est n³.

    // ---------------------------------------------------------

// Question X
    for (int sommetIntermediaire = 0; sommetIntermediaire < TAILLEDUGRAPHE; sommetIntermediaire++) {
        for (int origine = 0; origine < TAILLEDUGRAPHE; origine++) {
            for (int destination = 0; destination < TAILLEDUGRAPHE; destination++) {

                if (cheminCourt[origine][sommetIntermediaire] != INFINI && cheminCourt[sommetIntermediaire][destination] != INFINI) {
                    int nouvelleDistance = cheminCourt[origine][sommetIntermediaire] + cheminCourt[sommetIntermediaire][destination];

                    if (nouvelleDistance < cheminCourt[origine][destination]) {
                        cheminCourt[origine][destination] = nouvelleDistance;
                        pointChemin[origine][destination] = sommetIntermediaire;
                    }
                }
            }
        }
    }

    // ---------------------------------------------------------

// Question XI
    // Voir tout en haut la fonction.

    // ---------------------------------------------------------

// Question XII
    // La particularité de cette méthode est qu’elle utilise une récursion divisée en deux appels pour reconstruire le chemin dans le bon ordre, en utilisant la matrice pointChemin qui vient de l’algorithme de Floyd-Warshall. C'est le principe de diviser pour régner, on décompose le problème et on assemble tout à la fin.
    // La fonction appelle d’abord afficherChemin(sommet1, suivant, premier), puis affiche ensuite le sommet intermédiaire et puis appelle afficherChemin(suivant, sommet2, premier).

    // ---------------------------------------------------------

// Question XIII
    // Le graphe est A -> B -> C. L'appel sera afficherChemin(A, C, true);
    // On a alors : 
    // suivant = pointChemin[A][C]
    // Si suivant == -1 ou suivant est égal à A ou C, on retourne.
    // Sinon, on fait récursivement :
    // afficherChemin(A, suivant, premier)
    // afficher le sommet "suivant"
    // afficherChemin(suivant, C, premier)
    //
    // pointChemin[A][C] renvoie B (le chemin intermédiaire de A vers C)
    // pointChemin[B][C] renvoie également B (le code l’indique)
    //
    // Ainsi, 
    // Premier appel : afficherChemin(A, C, true)
    // suivant = B
    // On appelle afficherChemin(A, B, premier)
    // suivant = pointChemin[A][B] = B
    // Comme suivant == B (et sommet2 = B), on retourne directement -> rien affiché.
    // On affiche B maintenant (c’est le sommet intermédiaire)
    // On appelle afficherChemin(B, C, premier)
    // suivant = pointChemin[B][C] = B
    // Comme suivant == B (et sommet1 = B), on retourne -> rien est affiché.
    // Le résultat final sera "par B".
    //

    // ---------------------------------------------------------

// Question XIV
    // Voir le afficherCheminMieux tout en haut du fichier.
    bool premier = true; 
    std::cout << "Chemin de Lille à Marseille";
    afficherChemin(0, 5, premier); 
    std::cout << std::endl;
    // ---------------------------------------------------------

// Question XV
    // La fonction est tout en haut du fichier.
    affichagePCCh();

    // ---------------------------------------------------------


    return 0;
}
