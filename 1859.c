#include <stdio.h>
#include <string.h>

int main() {
    char sentence[100];
    char words[100][20];
    while (gets(sentence) != NULL) {
        int length = strlen(sentence);
        // ���е����и�
        int idx_words = 0;
        int idx_word = 0;
        char buf[100];
        for (int i = 1; i <= length - 2; i++) {
            if (sentence[i] == ' ') {
                strcpy(words[idx_words++], buf);
                idx_word = 0;
            } else {
                buf[idx_word] = sentence[i];
                buf[++idx_word] = '\0';
            }
        }
        strcpy(words[idx_words++], buf);
        // �����ת���
        putchar('"');
        for (int i = idx_words - 1; i >= 0; i--) {
            printf(i == 0 ? "%s" : "%s ", words[i]);
        }
        putchar('"');
        putchar('\n');        
    }
}