#include <stdio.h>

int parse(char str[], int ar[]) {
    char ch;
    int idx = 0;
    int num = 0;
    int flag = 0;  // ����Ѿ���ʼ��ȡ��������
    for (int i = 0; ch = str[i]; i++) {
        if ('0' <= ch && ch <= '9') {
            flag = 1;
            num = num * 10 + (ch - '0');
        }
        else if (ch == ' ' && flag) {
            ar[idx++] = num;
            num = 0;
        }
    }
    ar[idx++] = num;
    return idx;
}

int main() {
    int ar1[100];
    int ar2[100];
    char str1[100];
    char str2[100];
    gets(str1);
    gets(str2);
    gets(str2);
    int idx1 = parse(str1, ar1);
    int idx2 = parse(str2, ar2);
    int i = 0;
    int ans = 0;
    while (i < idx1) {
        // ƥ������ͷ��
        int pos = -1;
        for (; i < idx1; i++) {
            if (ar1[i] == ar2[0]) {
                pos = i;
                break;
            }
        }
        // �������������A���鶼û�ҵ�ƥ��ͷ������Bһ������A���Ӵ�
        if (i == idx1 && pos == -1) {
            break;
        }
        // �ҵ�����ͷ�������к���У��
        int j;
        for (j = 0; j < idx2; j++) {
            if (ar1[pos + j] != ar2[j]) break;
        }
        // ƥ��ɹ�����¼�𰸲��˳�ѭ��
        if (j == idx2) {
            ans = 1;
            break;
        }
    }
    printf(ans ? "��" : "��");
}