#include <stdio.h>
#include <string.h>

/*
���дC��������5����ͬ����Ϊ�ַ���ʽ��ѧ����ţ�
�������ɴ�С�����ٽ�����ѧ����ź���С��ѧ����Ż���λ�ã�Ȼ�������ʱ5λѧ���ı�š�

���룺
good1
tiger100
horse2011
mouse 022
21century

�����
21century
mouse 022
horse2011
good1
tiger100
*/

int main() {
    int temp;
    int indexArr[5];
    char arr[5][100];
    for (int i = 0; i < 5; i++) {
        indexArr[i] = i;
        gets(arr[i]);
    }
    for (int i = 0; i < 5; i++) {
        for (int j = i; j < 4 - i; j++) {
            if (strcmp(arr[indexArr[j]], arr[indexArr[j + 1]]) < 0) {
                temp = indexArr[j];
                indexArr[j] = indexArr[j + 1];
                indexArr[j + 1] = temp;
            }
        }
    }
    temp = indexArr[0];
    indexArr[0] = indexArr[4];
    indexArr[4] = temp;
    for (int i = 0; i < 5; i++) {
        printf("%s\n", arr[indexArr[i]]);
    }
}