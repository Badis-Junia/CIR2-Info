#include <stdio.h>
#include <math.h>

void calcul_2nd_degres(int a, int b, int c) {
    if (a == 0) {
        printf("Ce n'est pas une équa diff du 2nd degrès.");
        return;
    }

    int delta = b * b - 4 * a * c;

    if (delta < 0) {
        printf("Pas de solution réelle.\n");
    } 
    else if (delta == 0) {
        float x = -b / (2.0 * a);
        printf("Une solution : x = %.2f\n", x);
    } 
    else {
        float racine_delta = sqrt(delta);
        float x1 = (-b - racine_delta) / (2.0 * a);
        float x2 = (-b + racine_delta) / (2.0 * a);
        printf("Deux solutions : x1 = %.2f et x2 = %.2f\n", x1, x2);
    }
}

int main() {
    int a;
    int b;
    int c;

    printf("Entrez a, b et c : ");
    scanf("%d %d %d", &a, &b, &c);

    calcul_2nd_degres(a, b, c);

    return 0;
}
