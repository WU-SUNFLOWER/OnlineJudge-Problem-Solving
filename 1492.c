#include <stdio.h>

int main() {
    int range = 3;
    int matrix[100];
    for (int i = 0; i < range * range; i++) {
        scanf("%d", &matrix[i]);
    }
    //�����Խ���
    int sum1 = 0;
    for (int i = 0; i < range; i++) {
        sum1 += matrix[i * range + i];
    }
    //�󸱶Խ���
    int sum2 = 0;
    for (int i = 0; i < range; i++) {
        sum2 += matrix[i * range + (range - 1 - i)];
    }
    printf("%d %d\n", sum1, sum2);
}