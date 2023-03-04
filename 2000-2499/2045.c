#include <stdio.h>
#include <string.h>

int main() {
    char str1[1000];
    char str2[1000];
    while (gets(str1)) {
        int length1 = strlen(str1);
        int length2 = 0;
        int cnt = 0;
        for (int i = length1 - 1; i >= 0; i--) {
            if (str1[i] != ',') {
                str2[length2++] = str1[i];
                //别忘了如果数字长度如果正好是3的倍数，
                //当第一个数字读取完毕后，前面不需要再加,符号
                if (++cnt % 3 == 0 && i != 0) {
                    str2[length2++] = ',';
                }
            }
        }
        for (int i = length2 - 1; i >= 0; i--) {
            printf("%c", str2[i]);
        }
        putchar('\n');
    }
}