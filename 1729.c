#include <stdio.h>
#include <string.h>

int HashMap[50000];

int getCharDValue(char ch) {
    return ch - ('a' <= ch && ch <= 'z' ? 'a' : 'A');
}

int computeHash(char str[]) {
    int hash = 0;
    int length = strlen(str);
    for (int i = 1; i <= length; i++) {
        char ch = str[i - 1];
        hash += i * getCharDValue(ch);
    }
    return hash;
}

void addToHashMap(char str[]) {
    HashMap[computeHash(str)] = 1;
}

int isInHashMap(char str[]) {
    return HashMap[computeHash(str)];
}

char buf[100];

int main() {
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%s", buf);
        if (!isInHashMap(buf)) {
            addToHashMap(buf);
            printf("%s ", buf);
        }
    }
}