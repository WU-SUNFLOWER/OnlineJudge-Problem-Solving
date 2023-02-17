#include <stdio.h>

int main() {
    int index[10];
    int score[10];
    for (int i = 0; i < 10; i++) {
        index[i] = i;
        scanf("%d", &score[i]);
    }
    for (int i = 0; i <= 9; i++) {
        for (int j = 9; j >= 1 + i; j--) {
            if (score[index[j - 1]] < score[index[j]]) {
                int temp = index[j - 1];
                index[j - 1] = index[j];
                index[j] = temp;
            }
        }
        if (score[index[i]] == score[index[0]]) {
            printf("%d\n", index[i]);
        } else {
            break;
        }
    }
}