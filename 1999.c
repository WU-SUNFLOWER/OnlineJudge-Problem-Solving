#include <stdio.h>
#include <string.h>

/*
请编写C程序，输入5个不同的且为字符格式的学生编号，
将其先由大到小排序，再将最大的学生编号和最小的学生编号互换位置，然后输出此时5位学生的编号。

输入：
good1
tiger100
horse2011
mouse 022
21century

输出：
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