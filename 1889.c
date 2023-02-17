#include <stdio.h>

int main() {
    //i控制每个拉丁矩阵第一行的起始数字
    for (int i = 1; i <= 3; i++) {
        //j控制当前拉丁矩阵当前行的起始数字
        for (int j = 0; j < 3; j++) {
            int p = (i + j - 1) % 3 + 1;
            //k控制当前拉丁矩阵当前行的输出
            for (int k = 0; k < 3; k++) {
                printf("%d", p);
                p = p % 3 + 1;
            }
            printf("\n");
        }
        printf("\n");
    }
}