#include <stdio.h>
#include <string.h>

int main() {
    char tempString[10];
    int integerArr[4] = {0};
    int floatArr[4] = {0};
    while (~scanf("%s", tempString)) {
        int i = 0;
        int integerLength = 0;  //���ڼ�¼�������β��ֵĳ���
        //��һ���������ַ����е����ݵ�����
        for (; tempString[i] != '.'; i++) {
            integerArr[i] = tempString[i] - '0';
        }
        integerLength = i;
        for (i = i + 1; tempString[i]; i++) {
            floatArr[i - integerLength - 1] = tempString[i] - '0';
        }
        //�ڶ���������С��λ
        //���ȴ���ĩ�˵�3��4��
        int carry = floatArr[3] >= 4 ? 1 : 0;
        //Ȼ���ٴ����7��1��7����
        for (i = 2; i >= 0; i--) {
            int ans = floatArr[i] + carry;
            floatArr[i] = ans % 7;
            carry = ans / 7;
        }
        //����������������λ�ķ�7��1
        for (i = integerLength - 1; i >= 0; i--) {
            int ans = integerArr[i] + carry;
            integerArr[i] = ans % 7;
            carry = ans / 7;
        }
        //���Ĳ������
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