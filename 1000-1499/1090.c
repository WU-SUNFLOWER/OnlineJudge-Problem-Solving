#include <stdio.h>
#include <stdlib.h>

int parse(char str[], int nums[]) {
    int length = 0;
    int num = 0;
    int isFirstNum = 1;
    int k = 1;
    int isNewNum = 1;
    for (int i = 0; str[i]; i++) {
        //��һ�����������������
        if (isNewNum) {
            isNewNum = 0;
            isFirstNum ? (isFirstNum = 0) : (nums[length++] = num);
            num = 0;
            str[i] == '-' ? (k = -1) : (k = 1, num = str[i] - '0');
        }
        //�ڶ��������������������
        else if ('0' <= str[i] && str[i] <= '9') {
            num = num * 10 + k * (str[i] - '0');
        }
        //����������������ո����������
        else {
            isNewNum = 1;
        }
    }
    //�����˽������һ������
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
        //��һ������ȡ����
        length = parse(str, nums);
        //�ڶ���������
        for (int i = 0; i < length - 2; i++) {
            for (int j = 1; j <= length - 2 - i; j++) {
                if (abs(nums[j]) < abs(nums[j + 1])) {
                    int temp = nums[j];
                    nums[j] = nums[j + 1];
                    nums[j + 1] = temp;
                }
            }
        }
        //�������������
        for (int i = 1; i < length; i++) {
            printf(i == length - 1 ? "%d\n" : "%d ", nums[i]);
        }
    }
}