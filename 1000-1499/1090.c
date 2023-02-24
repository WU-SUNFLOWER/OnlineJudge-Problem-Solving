#include <stdio.h>
#include <stdlib.h>

int parse(char str[], int nums[]) {
    int length = 0;
    int num = 0;
    int isFirstNum = 1;
    int k = 1;
    int isNewNum = 1;
    for (int i = 0; str[i]; i++) {
        //第一种情况：碰到新数字
        if (isNewNum) {
            isNewNum = 0;
            isFirstNum ? (isFirstNum = 0) : (nums[length++] = num);
            num = 0;
            str[i] == '-' ? (k = -1) : (k = 1, num = str[i] - '0');
        }
        //第二种情况：持续接收数字
        else if ('0' <= str[i] && str[i] <= '9') {
            num = num * 10 + k * (str[i] - '0');
        }
        //第四种情况：碰到空格，则结束接收
        else {
            isNewNum = 1;
        }
    }
    //别忘了接收最后一个数字
    nums[length++] = num;
    return length;
}

int main() {
    char str[1000];
    int nums[1000];
    int length = 0;
    while (gets(str)) {
        if (str[0] == '0' && !str[1]) {
            break;
        }
        //第一步：提取数字
        length = parse(str, nums);
        //第二步：排序
        for (int i = 0; i < length - 2; i++) {
            for (int j = 1; j <= length - 2 - i; j++) {
                if (abs(nums[j]) < abs(nums[j + 1])) {
                    int temp = nums[j];
                    nums[j] = nums[j + 1];
                    nums[j + 1] = temp;
                }
            }
        }
        //第三步：输出答案
        for (int i = 1; i < length; i++) {
            printf(i == length - 1 ? "%d\n" : "%d ", nums[i]);
        }
    }
}