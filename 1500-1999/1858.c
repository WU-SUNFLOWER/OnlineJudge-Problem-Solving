#include <stdio.h>

int main() {
    // ��ȡ����
    char buf[100];
    int ar[100];
    gets(buf);
    char ch;
    int num = 0;
    int idx = 0;
    for (int i = 0; ch = buf[i]; i++) {
        if (ch == ' ') {
            ar[idx++] = num;
            num = 0;
        } else {
            num = num * 10 + (ch - '0');
        }
    }
    ar[idx++] = num;
    // ��ȡҪ��������
    int target;
    scanf("%d", &target);
    // ���
    int i, j;
    int flag = 1;
    for (i = 0; i < idx && flag; i++) {
        for (j = i + 1; j < idx && flag; j++) {
            if (ar[i] + ar[j] == target) {
                printf("%d %d\n", ar[i], ar[j]);
                flag = 0;
            }
        }
    }
}