#include <stdio.h>
#include <math.h>

// What is the largest prime factor of the number 600851475143 ?

#define THE_NUMBER 600851475143
#define BUFFER_SIZE 1000000

void sieve_of_erotasthenes(int max, char result[]) {
    char list[max];
    int i = 2, j = 0, p = 2;
    for(; i < max; i++) {
        list[i] = 1;
    }
    while(p < max) {
        printf("Marking out multiples of %d\n", p);
        for(i = 1; i * p < max; i++) {
            list[i*p] = 0;
        }
        for(i = p+1; !list[i]; i++);
        p = i;
    }
    for(i=4; i < max; i++) {
        if(list[i]) {
            result[j++] = i;
        }
    }

    return;
}

int main(int argc, char* argv[]) {
    int top = (int)sqrt(THE_NUMBER);
    char sieve_result[BUFFER_SIZE];
    sieve_of_erotasthenes(top, sieve_result);
    int pf = 0;
    for(int i = 0; i < BUFFER_SIZE; i++) {
        if(sieve_result[i] && sieve_result[i] % THE_NUMBER == 0) {
            pf = sieve_result[i];
            break;
        }
    }
    printf("The largest prime factor is %d\n", pf);
    return 0;
}
