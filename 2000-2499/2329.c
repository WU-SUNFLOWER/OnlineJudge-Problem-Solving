#include <stdio.h>

int main() {
    int actionCount;
    while (~scanf("%d", &actionCount)) {
        int targetX;
        int targetY;
        int x = 0;
        int y = 0;
        int step;
        char command;
        for (int i = 0; i < actionCount; i++) {
            getchar();
            scanf("%c%d", &command, &step);
            switch (command) {
                case 'L':
                    x -= step;
                    break;
                case 'R':
                    x += step;
                    break;
                case 'F':
                    y += step;
                    break;
                case 'B':
                    y -= step;
                    break;
            }
        }
        scanf("%d %d", &targetX, &targetY);
        printf(
            targetX == x && targetY == y ?
                "MEME IS SO LUCKY\n" :
                "GPS ERROR\n"
        );
    }
}