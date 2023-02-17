#include <stdio.h>

int decode(char password[]) {
    int ans = 0;
    for (int i = 0; password[i]; i++) {
        ans = ans * 26 + password[i] - 'A';
    }
    return ans;
}

void encode(int plain, char password[]) {
    int i = 0;
    while (plain > 0) {
        password[i++] = plain % 26 + 'A';
        plain /= 26;
    }
    password[i] = '\0';
    for (int j = 0; j < i / 2; j++) {
        char temp = password[j];
        password[j] = password[i - j - 1];
        password[i - j - 1] = temp;
    }
};

int main() {
    char password1[300];
    char password2[300];
    char password3[300];
    while (~scanf("%s %s", password1, password2)) {
        encode(decode(password1) + decode(password2), password3);
        printf("%s\n", password3);
    }
}