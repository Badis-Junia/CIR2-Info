#include <stdio.h>


char minuscule(char c) {
    if (c >= 'A' && c <= 'Z') {
        return c + 32; 
    }
    return c; 
}

int main() {
    printf("%c -> %c\n", 'A', minuscule('A')); 
    return 0;
}
