#include <stdio.h>
#include <string.h>

int decode(char password[]) {
    int ans = 0;
    for (int i = 0; password[i]; i++) {
        ans = ans * 26 + password[i] - 'a';
    }
    return ans;
}

int isEndSymbol(char symbol[]) {
    return strlen(symbol) == 1 && symbol[0] == '0';
}

int main() {
    char name1[100];
    char name2[100];
    while (~scanf("%s %s", name1, name2)) {
        if (isEndSymbol(name1) && isEndSymbol(name2)) {
            break;
        }
        if ((decode(name1) + decode(name2)) % 2 == 0) {
            printf("Yes\n");
        } else {
            printf("No\n");
        }
    }
}