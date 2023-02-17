#include <stdio.h>
#include <string.h>

int main() {
    char type;
    int input_d;
    char input_b[15];
    int output_b[15];
    while (~scanf("%c", &type)) {
        if (type == 'D') {
            scanf("%d", &input_d);
            int idx = 0;
            while (input_d > 0) {
                output_b[++idx] = input_d % 2;
                input_d /= 2;
            }
            for (int i = 8; i >= 1; i--) {
                putchar(i > idx ? '0' : output_b[i] + '0');
            }
            putchar('\n');
        } 
        else if (type == 'B') {
            int ans = 0;
            scanf("%s", input_b);
            for (int i = 0; input_b[i]; i++) {
                ans = ans * 2 + (input_b[i] - '0');
            }
            printf("%d\n", ans);
        }
    }
}