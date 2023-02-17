#include <stdio.h>
#include <string.h>

int main() {
    char str1[100];
    char str2[100];
    int length1;
    int length2;
    while (~scanf("%s %s", str1, str2)) {
        length1 = strlen(str1);
        length2 = strlen(str2);
        //≤Â»Î≈≈–Ú
        for (int i = 0; i < length2; i++) {
            int j;
            for (j = length1 - 1 + i; j >= 0; j--) {
                if (str1[j] <= str2[i]) {
                    break;
                }
                str1[j + 1] = str1[j];
            }
            str1[j + 1] = str2[i];
        }
        // ‰≥ˆ
        str1[length1 + length2] = '\0';
        puts(str1);
    }
}