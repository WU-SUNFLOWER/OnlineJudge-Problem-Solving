#include <stdio.h>
#include <string.h>

int main() {
    char tempNum1[101];
    char tempNum2[101];
    while (scanf("%s %s", tempNum1, tempNum2) != EOF) {
        int num1[102];
        int num2[102];
        int ans[102];
        int num1_len = strlen(tempNum1);
        int num2_len = strlen(tempNum2);
        //初始化数组
        for (int i = 0; i < 102; i++) {
            //由于零也可能参与运算，故采用-1标记空位
            num1[i] = num2[i] = -1;
        }
        //转置数组并将字符转换成数字
        for (int i = num1_len - 1; i >= 0; i--) {
            num1[num1_len - i - 1] = tempNum1[i] - '0';
        }
        for (int i = num2_len - 1; i >= 0; i--) {
            num2[num2_len - i - 1] = tempNum2[i] - '0';
        }
        //模拟加法
        int idx = 0;
        int carryNum = 0;
        while (num1[idx] != -1 || num2[idx] != -1 || carryNum != 0) {
            //将值为-1的空位修复为0，以正确参与运算
            num1[idx] == -1 && (num1[idx] = 0);
            num2[idx] == -1 && (num2[idx] = 0);
            int sum = num1[idx] + num2[idx] + carryNum;
            ans[idx] = sum % 10;
            carryNum = sum / 10;
            idx++;
        }
        for (int i = idx - 1; i >= 0; i--) {
            printf("%d", ans[i]);
        }
        printf("\n");
    }
}