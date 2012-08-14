#include <stdio.h>

int main(int argc, int *argv[]) {
    int sum = 2;
    for(int a=1, b=2, c=3; c < 4000000; a=b, b=c, c=a+b) {
        sum += c % 2 ? 0 : c;
    }
    printf("Sum is %d\n", sum);
    return 0;
}
