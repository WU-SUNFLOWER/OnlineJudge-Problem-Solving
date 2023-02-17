#include <stdio.h>
#include <string.h>

int main() {
    const int num = 3;
    int index[3];
    char arr[3][100];
    for (int i = 0; i < num; i++) {
        index[i] = i;
        gets(arr[i]);
    }
    for (int i = 0; i < num - 1; i++) {
        for (int j = 0; j <= num - 2 - i; j++) {
            if (strcmp(arr[index[j]], arr[index[j + 1]]) > 0) {
                int t = index[j];
                index[j] = index[j + 1];
                index[j + 1] = t;
            }
        }
    }
    for (int i = 0; i < num; i++) {
        puts(arr[index[i]]);
    }
}