#include <stdio.h>
#include <string.h>

int main() {
    int m;
    int n;
    while (scanf("%d %d", &m, &n) != EOF) {
        int idx = -1;
        char ans[5][9];
        if (m == 0 && n == 0) {
            break;
        }
        if (m <= 6 && 6 <= n) {
            strcpy(ans[++idx], "6");
        }
        if (m <= 28 && 28 <= n) {
            strcpy(ans[++idx], "28");
        }
        if (m <= 496 && 496 <= n) {
            strcpy(ans[++idx], "496");
        }
        if (m <= 8128 && 8128 <= n) {
            strcpy(ans[++idx], "8128");
        }
        if (m <= 33550336 && 33550336 <= n) {
            strcpy(ans[++idx], "33550336");
        }
        if (idx == -1) {
            printf("No\n");
        } else {
            for (int i = 0; i <= idx; i++) {
                printf(i == idx ? "%s\n" : "%s ", ans[i]);
            }            
        }
    }
}