#include <stdio.h>
#include <string.h>

int main() {
    char tempString[10];
    int integerArr[4] = {0};
    int floatArr[4] = {0};
    while (~scanf("%s", tempString)) {
        int i = 0;
        int integerLength = 0;  //用于记录数据整形部分的长度
        //第一步：拷贝字符串中的数据到整型
        for (; tempString[i] != '.'; i++) {
            integerArr[i] = tempString[i] - '0';
        }
        integerLength = i;
        for (i = i + 1; tempString[i]; i++) {
            floatArr[i - integerLength - 1] = tempString[i] - '0';
        }
        //第二步：处理小数位
        //首先处理末端的3舍4入
        int carry = floatArr[3] >= 4 ? 1 : 0;
        //然后再处理逢7进1的7进制
        for (i = 2; i >= 0; i--) {
            int ans = floatArr[i] + carry;
            floatArr[i] = ans % 7;
            carry = ans / 7;
        }
        //第三步：处理整数位的逢7进1
        for (i = integerLength - 1; i >= 0; i--) {
            int ans = integerArr[i] + carry;
            integerArr[i] = ans % 7;
            carry = ans / 7;
        }
        //第四步：输出
        for (i = 0; i < integerLength; i++) {
            printf("%c", integerArr[i] + '0');
        }
        putchar('.');
        for (i = 0; i < 3; i++) {
            printf("%c", floatArr[i] + '0');
        }
        putchar('\n');
    }
}