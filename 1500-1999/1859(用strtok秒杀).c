#include <stdio.h>
#include <string.h>

int main() {
    char str[100];
    char strAr[100][100];
    while (gets(str) != NULL) {
        int idx_ar = 0;
        str[strlen(str) - 1] = '\0';
        char* ptr = strtok(str + 1, " ");
        while (ptr != NULL) {
            strcpy(strAr[idx_ar++], ptr);
            ptr = strtok(NULL, " ");
        }
        printf("\"");
        for (int i = idx_ar - 1; i >= 0; i--) {
            printf(i == 0 ? "%s\"\n" : "%s ", strAr[i]);
        }
    }
}