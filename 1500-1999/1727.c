#include <stdio.h>

int main() {
    int ar1[100];
    int ar2[100];
    int len1, len2;
    scanf("%d", &len1);
    for (int i = 0; i < len1; i++) {
        scanf("%d", &ar1[i]);
    }
    scanf("%d", &len2);
    for (int i = 0; i < len2; i++) {
        scanf("%d", &ar2[i]);
    }
    int i = 0;
    int j = 0;
    int idx = 0;
    int ar3[100];
    while (i < len1 || j < len2) {
        // ���i��Խ�磬jδԽ��
        if (i >= len1) {
            for (; j < len2; j++) {
                ar3[idx++] = ar2[j];
            }
        }
        // ���j��Խ�磬iδԽ��
        else if (j >= len2) {
            for (; i < len1; i++) {
                ar3[idx++] = ar1[i];
            }
        }
        // ����������ģ��
        else if (ar1[i] == ar2[j]) {
            ar3[idx++] = ar1[i];
            i++;
            j++;
        }
        else if (ar1[i] > ar2[j]) {
            ar3[idx++] = ar2[j++];
        }
        else {
            ar3[idx++] = ar1[i++];
        }
    }
    for (int i = 0; i < idx; i++) {
        printf("%d ", ar3[i]);
    }
}