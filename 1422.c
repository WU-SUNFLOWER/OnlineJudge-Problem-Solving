#include <stdio.h>

int c2f(int c) {
    return 32 + c * 9 / 5;
}

int main() {
    for (int c = -100; c <= 150; c++) {
        //c=0->f=32
        printf("c=%d->f=%d\n", c, c2f(c));
    }
}