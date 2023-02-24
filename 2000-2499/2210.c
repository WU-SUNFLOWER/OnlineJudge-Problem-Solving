#include <stdio.h>
#include <string.h>

int main() {
    int classNum;
    scanf("%d", &classNum);
    for (int i = 1; i <= classNum; i++) {
        char name[10];
        char winner[10];
        int score;
        int totalScore = 0;
        int maxScore = -1;
        int stduentNum;
        scanf("%d", &stduentNum);
        for (int j = 0; j < stduentNum; j++) {
            scanf("%s %d", &name, &score);
            totalScore += score;
            if (score > maxScore) {
                maxScore = score;
                strcpy(winner, name);
            }
        }
        printf("%d %.2lf %s %d\n", i, totalScore * 1.0 / stduentNum, winner, maxScore);
    }
}