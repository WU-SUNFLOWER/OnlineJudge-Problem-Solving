#include <stdio.h>

int main() {
    int temp;
    int box[1000] = {0};
    for (int i = 0; i < 3; i++) {
        scanf("%d", &temp);
        box[temp] = 1;
    }
    for (int i = 0; i < 1000; i++) {
        if (box[i]) {
            printf("%d ", i);
        }
    }
}