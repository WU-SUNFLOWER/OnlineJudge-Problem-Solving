#include <stdio.h>

int main() {
    char ch;
    char str[200];
    int isFirstFinishSymbol = 0;
    gets(str);
    for (int i = 0; str[i]; i++) {
        ch = str[i];
        //��һ������������Ϸ��ַ������
        if (
            'a' <= ch && ch <= 'z' ||
            'A' <= ch && ch <= 'Z' ||
            '0' <= ch && ch <= '9'
        ) {
            putchar(ch);
            isFirstFinishSymbol = 1;
        }
        //�ڶ����������һ�����ض��ַ�����������з�
        else if (isFirstFinishSymbol) {
            putchar('\n');
            isFirstFinishSymbol = 0;
        }
    }
}