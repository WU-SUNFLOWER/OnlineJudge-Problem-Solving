#include <stdio.h>
#include <string.h>

/*
���ʵ�ֽ��ַ�������̵ĵ�����������������������ַ�����
��дһ�����������̵��ʵĲ��ң�����ж����ͬ���ȵ��ʣ���ֻ�����һ����̵��ʡ�
���赥��֮���ÿո�ָ���һ�������ո񣩣�findshort(s1,s2)�������s1������̵��ʵĲ��ң��ҵ�����̵��ʴ洢��s2�С�

����:
Happy new year

���:
new
*/

int main() {
    char ch;
    char ansWord[20] = {'\0'};
    char tempWord[20] = {'\0'};
    int tempLen = 0;
    int ansLen;
    int isValidWordsMeeted = 0;
    int isAnsLenInitialized = 0;
    while (1) {
        ch = getchar();
        if (isValidWordsMeeted) {
            if (ch == ' ' || ch == EOF || ch == '\n') {
                if (tempLen < ansLen || !isAnsLenInitialized) {
                    ansLen = tempLen;
                    strcpy(ansWord, tempWord);
                    ansWord[ansLen] = '\0';
                    isAnsLenInitialized = 1;
                }
                isValidWordsMeeted = 0;
                if (ch == EOF || ch == '\n') {
                    break;
                }
            } 
            else {
                tempWord[tempLen++] = ch;
            }
        }
        else if ('a' <= ch && ch <= 'z'|| 'A' <= ch && ch <= 'Z') {
            tempLen = 1;
            tempWord[tempLen - 1] = ch;
            isValidWordsMeeted = 1;
        }
        else if (ch == EOF || ch == '\n') {
            break;
        }
    }
    printf("%s\n", ansWord);
}