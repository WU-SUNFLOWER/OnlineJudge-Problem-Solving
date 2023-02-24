#include <stdio.h>

int main() {
    for (int x = 1; x <= 4; x++) {
        for (int y = 1; y <= 4; y++) {
            for (int z = 1; z <= 4; z++) {
                if (x != y && y != z && x != z) {
                    printf("%d %d %d\n", x, y, z);
                }
            }
        }
    }
}