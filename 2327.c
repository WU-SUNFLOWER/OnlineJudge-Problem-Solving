#include <stdio.h>

char getKey(int ciphertext[], int length) {
    char ans = 'A';
    //枚举可能的密钥
    for (; ans <= 'Z'; ans++) {
        //对当前枚举的密钥进行校验
        int i;
        for (i = 0; i < length; i++) {
            char ch = ciphertext[i] ^ ans;
            if (!('A' <= ch && ch <= 'Z')) {
                break;
            }
        }
        if (i == length) {
            break;
        }
    }
    return ans;
}

void decode(int ciphertext[], char plaintext[], char key, int length) {
    int i;
    for (i = 0; i < length; i++) {
        plaintext[i] = ciphertext[i] ^ key;
    }
    plaintext[i] = '\0';
}

int main() {
    int n;
    int ciphertext[2000];
    char plaintext[2000];
    while (~scanf("%d", &n)) {
        char key;
        for (int i = 0; i < n; i++) {
            scanf("%d", &ciphertext[i]);
        }
        key = getKey(ciphertext, n);
        decode(ciphertext, plaintext, key, n);
        printf("%s\n", plaintext);
    }
}