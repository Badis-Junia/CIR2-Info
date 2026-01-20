#include <stdio.h>

int nexclamation_for(int n) {
    int result = 1;
    for(int i = n;i>0;i--) {
        result = result * i;
    }
    return result;
}

int nexclamation_while(int n) {
    int result = 1;
    while(n > 0) {
        result = result * n;
        n--;
    }
    return result;
}

int nexclamation_recursif(int n) {
    if (n <= 1) { 
        return 1;
    }
    return n * nexclamation_recursif(n - 1);  
}

int main() {
    int test = nexclamation_for(5);
    printf("5! -> %d pour la boucle for\n", test);
    int testdeux = nexclamation_while(5);
    printf("5! -> %d pour la boucle while\n", testdeux);
    int testtrois = nexclamation_recursif(5);
    printf("5! -> %d pour la boucle recursif\n", testtrois);
    return 0;
}
