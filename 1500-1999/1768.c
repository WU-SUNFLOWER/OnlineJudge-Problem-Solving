#include <stdio.h>

int main() {
    int len;
    int subLen;
    char str[100];
    char subStr[100];
    scanf("%d %d", &len, &subLen);
    scanf("%s %s", str, subStr);
    //��[0, subLen]�����䷶ΧΪ���Բ�ͬ�Ļ���������ʼλ��
    int ans = 0;
    int flag = 1;
    for (int i = 0; i < subLen && flag; i++) {
        //��������
        for (int j = i; j <= len - subLen && flag; j += subLen) {
            //У�黬�����ڿ�ס�������Ƿ�������������ִ�
            flag = 0;
            for (int k = 0; k < subLen; k++) {
                if (str[j + k] != subStr[k]) {
                    flag = 1;
                    break;
                }
            }
            //���ƥ�䵽�ִ������¼��j�������˳�ѭ��
            if (!flag) {
                ans = j + 1;
            }
        }
    }
    printf("%d\n", ans);
}