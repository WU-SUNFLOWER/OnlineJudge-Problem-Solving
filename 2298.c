#include <stdio.h>
#include <string.h>

int main() {
    int t;
    int typeNum;  //������������
    int indexArr[50];
    int lengthArr[50];
    int needNumArr[50];
    scanf("%d", &t);
    while (~scanf("%d", &typeNum)) {
        //����ÿ�ּ��ĳ��Ⱥ�������
        for (int i = 0; i < typeNum; i++) {
            indexArr[i] = i;
            scanf("%d %d", &lengthArr[i], &needNumArr[i]);
        }
        //���ռ��ĳ��Ƚ�������
        for (int i = 0; i < typeNum - 1; i++) {
            for (int j = 0; j <= typeNum - 2 - i; j++) {
                if (lengthArr[indexArr[j]] > lengthArr[indexArr[j + 1]]) {
                    int t = indexArr[j];
                    indexArr[j] = indexArr[j + 1];
                    indexArr[j + 1] = t;
                }
            }
        }
        //���ɼ�
        for (int i = 0; i < typeNum; i++) {
            for (int j = 0; j < needNumArr[indexArr[i]]; j++) {
                printf(">+");
                for (int k = 0; k < lengthArr[indexArr[i]] - 2; k++) {
                    printf("-");
                }
                printf("+>\n");
            }
            printf("\n");
        }
    }
}