#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Find the largest palindrome made from the product of two 3-digit numbers.

#define BUFFER_LEN 8

int is_palindrome(int p) {
    char pstr[BUFFER_LEN];
    snprintf(pstr, BUFFER_LEN, "%d", p);
    int plen = strlen(pstr);
    for(int i = 0; i < plen/2; i++) {
        if(pstr[i] != pstr[plen-1-i]) {
            return 0;
        }
    }
    return 1;
}

int main(int argc, char* argv[]) {
    int a = 0, b = 0;
    for(int i = 999; i > 99; i--) {
        for(int j = i; j > 99; j--) {
            if(is_palindrome(i * j) && (i * j) > (a * b)) {
                a = i;
                b = j;
            }
        }
    }

    printf("Largest palindrome found: %d x %d = %d\n", a, b, a * b);
    return 0;
}
