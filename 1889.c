#include <stdio.h>

int main() {
    //i����ÿ�����������һ�е���ʼ����
    for (int i = 1; i <= 3; i++) {
        //j���Ƶ�ǰ��������ǰ�е���ʼ����
        for (int j = 0; j < 3; j++) {
            int p = (i + j - 1) % 3 + 1;
            //k���Ƶ�ǰ��������ǰ�е����
            for (int k = 0; k < 3; k++) {
                printf("%d", p);
                p = p % 3 + 1;
            }
            printf("\n");
        }
        printf("\n");
    }
}