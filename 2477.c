#include <stdio.h>
#include <string.h>
#include <math.h>

int isNumber(char ch) {
    return '0' <= ch && ch <= '9';
}

int charToNum(char ch) {
    return ch - '0';
}

int main() {
    int length;
    char str[100];
    gets(str);
    length = strlen(str);
    for (int i = 0; i <= length - 3; i++) {
        if (!isNumber(str[i])) {
            continue;
        }
        double integerNum = 0;
        double floatNum = 0;
        //提取整数
        do {
            integerNum = charToNum(str[i]) + integerNum * 10;
            i++;
        } while (isNumber(str[i]));
        //处理碰到小数点的情况
        if (str[i] == '.' && isNumber(str[i + 1])) {
            int deep = 1;
            i++;
            do {
                floatNum += pow(0.1, deep++) * charToNum(str[i]);
                i++;
            } while (isNumber(str[i]));
        }
        //判断是否出现科学计数法的标志
        if (str[i] == 'e' && str[i + 1] == '+' && isNumber(str[i + 2])) {
            i += 2;
        } else {
            i--;
            continue;
        }
        //提取指数
        int expNum = 0;
        do {
            expNum = expNum * 10 + charToNum(str[i]);
            i++;
        } while (isNumber(str[i]));
        //计算结果
        printf("%.6lf\n", pow(10, expNum) * (integerNum + floatNum));
        break;
    }
}