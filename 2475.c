#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void sort(char* name[], int n) {
    char* temp;
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j <= n - 2 - i; j++) {
            if (strcmp(name[j], name[j + 1]) > 0) {
                temp = name[j];
                name[j] = name[j + 1];
                name[j + 1] = temp; 
            }
        }
    }
}

void print(char* name[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%s\n", name[i]);
        free(name[i]);
    }
}

int main() {
    int n;
    char* name[100];
    scanf("%d", &n);
    getchar();
    for (int i = 0; i < n; i++) {
        name[i] = (char*)malloc(sizeof(char) * 100);
        gets(name[i]);
    }
    sort(name, n);
    print(name, n);
}