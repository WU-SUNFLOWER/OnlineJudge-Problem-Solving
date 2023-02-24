#include <stdio.h>

int main() {
    int t;
    char id[100];
    char name[100];
    int score1;
    int score2;
    int score3;
    scanf("%d", &t);
    while (t--) {
        scanf("%s %s %d %d %d", id, name, &score1, &score2, &score3);
        printf("%s,%s,%d,%d,%d\n", id, name, score1, score2, score3);
    }
}