#include <stdio.h>
#include <stdlib.h>

int max(int a, int b) {
    return a > b ? a : b;
}

int* createIntArray(int length) {
    int* p = (int*)malloc(sizeof(int) * length);
    for (int i = 0; i < length; i++) {
        p[i] = 0;
    }
    return p;
}

int main() {
    char NumString1[401];
    char NumString2[401];
    int ans[402];
    while (~scanf("%s %s", NumString1, NumString2)) {
        //第一步
        //分别获取num1和num2整数和小数部分的最大长度
        int num1_integer_len = 0;
        int num1_float_len = 0;
        int num2_integer_len = 0;
        int num2_float_len = 0;
        int flag = 0;
        for (int i = 0; NumString1[i]; i++) {
            if (NumString1[i] == '.') {
                flag = 1;
                continue;
            }
            flag ? (num1_float_len++) : (num1_integer_len++);
        }
        flag = 0;
        for (int i = 0; NumString2[i]; i++) {
            if (NumString2[i] == '.') {
                flag = 1;
                continue;
            }
            flag ? (num2_float_len++) : (num2_integer_len++);
        }
        int integer_len = max(num1_integer_len, num2_integer_len);
        int float_len = max(num1_float_len, num2_float_len);
        //第二步
        //创建临时数组进行数据拷贝
        int* num1_integer = createIntArray(integer_len);
        int* num1_float = createIntArray(float_len);
        int* num2_integer = createIntArray(integer_len);
        int* num2_float = createIntArray(float_len);
        flag = 0;
        int idx = integer_len - 1;
        for (int i = 0; NumString1[i]; i++) {
            if (NumString1[i] == '.') {
                idx = 0;
                flag = 1;
                continue;
            }
            //处理小数部分(左对齐)
            if (flag) {
                num1_float[idx++] = NumString1[i] - '0';
            } 
            //处理整数部分（右对齐)
            else {
                num1_integer[idx--] = NumString1[i] - '0';
            }
        }
        flag = 0;
        idx = integer_len - 1;
        for (int i = 0; NumString2[i]; i++) {
            if (NumString2[i] == '.') {
                idx = 0;
                flag = 1;
                continue;
            }
            //处理小数部分(左对齐)
            if (flag) {
                num2_float[idx++] = NumString2[i] - '0';
            } 
            //处理整数部分（右对齐)
            else {
                num2_integer[idx--] = NumString2[i] - '0';
            }
        }
        //第二步
        //处理小数加法
        int sum;
        int carry = 0;
        for (int i = float_len - 1; i >= 0; i--) {
            sum = num1_float[i] + num2_float[i] + carry;
            num1_float[i] = sum % 10;
            carry = sum / 10;
        }
        //第三步
        //处理整数加法
        for (int i = integer_len - 1; i >= 0; i--) {
            sum = num1_integer[i] + num2_integer[i] + carry;
            num1_integer[i] = sum % 10;
            carry = sum / 10;
        }
        //第四步
        //输出结果
        carry > 0 && printf("%d", carry);
        for (int i = 0; i < integer_len; i++) {
            printf("%d", num1_integer[i]);
        }
        //对小数部分的结束位置进行修正,再输出
        while (num1_float[float_len - 1] == 0) {
            float_len--;
        }
        if (float_len > 0) {
            printf(".");
            for (int i = 0; i < float_len; i++) {
               printf("%d", num1_float[i]);
            }
        }
        printf("\n");
        //第五步
        //释放内存
        free(num1_integer);
        free(num2_integer);
        free(num1_float);
        free(num2_float);
    }
}