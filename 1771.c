#include <stdio.h>
#include <string.h>

int main() {
    int len;
    int subLen;
    char str[100];
    char subStr[100];
    scanf("%s %s", str, subStr);
    len = strlen(str);
    subLen = strlen(subStr);
    //��[0, subLen]�����䷶ΧΪ���Բ�ͬ�Ļ���������ʼλ��
    int ans = 0;
    for (int i = 0; i < subLen; i++) {
        //��������
        for (int j = i; j <= len - subLen; j += subLen) {
            //У�黬�����ڿ�ס�������Ƿ�������������ִ�
            int flag = 1;
            for (int k = 0; k < subLen; k++) {
                if (str[j + k] != subStr[k]) {
                    flag = 0;
                    break;
                }
            }
            //���ƥ�䵽�ִ������¼��j�������˳�ѭ��
            if (flag) {
                ans++;
            }
        }
    }
    printf("%d\n", ans);
}