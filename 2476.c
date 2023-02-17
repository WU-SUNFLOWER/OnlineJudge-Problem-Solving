#include <stdio.h>
#include <stdlib.h>
#include <string.h>

const int N = 100;

char* createString(int length) {
    char* p = (char*)malloc(sizeof(char) * (length + 1));
    return p;
}

//����һ������ռ�
//�Ծ����е�Ӣ�ĵ��ʽ��в�⣬��������ĵ��ʴ���ÿռ�
char** deconstruct(char sentence[], int* count) {
    int isNewWord = 1;
    int idx = 0;
    int wordIdx = 0;
    char** words = (char**)malloc(sizeof(char*) * N);
    for (int i = 0; sentence[i]; i++) {
        char ch = sentence[i];
        //��һ���������������µ��ʣ��򿪱��¿ռ����д��
        if (ch != ' ' && isNewWord) {
            wordIdx = 0;
            isNewWord = 0;
            words[idx] = createString(N);
            words[idx][wordIdx++] = ch;
        }
        //�ڶ�����������ڽ��յ���
        else if ('a' <= ch && ch <= 'z') {
            words[idx][wordIdx++] = ch;
        }
        //�����������(��ĩβ��)���ʽ��ս���
        else if (ch == ' ' && !isNewWord) {
            words[idx++][wordIdx] = '\0';
            isNewWord = 1;
        }
    }
    //����ĩβ���յĵ���
    words[idx++][wordIdx] = '\0';
    //��ǽ���λ,����������ĵ�������
    *count = idx;
    words[idx] = NULL;
    return words;
}

void sort(char** words, int n) {
    char* temp;
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j <= n - 2 - i; j++) {
            if (strlen(words[j]) < strlen(words[j + 1])) {
                temp = words[j];
                words[j] = words[j + 1];
                words[j + 1] = temp; 
            }
        }
    }
}

int main() {
    //���վ���
    char sentence1[200];
    char sentence2[200];
    gets(sentence1);
    gets(sentence2);
    //�Ե��ʽ��в��
    int count1;
    int count2;
    char** words1 = deconstruct(sentence1, &count1);
    char** words2 = deconstruct(sentence2, &count2);
    //�Ե��ʰ����Ƚ��н�������
    sort(words1, count1);
    sort(words2, count2);
    //����
    for (int i = 0; i < count1; i++) {
        for (int j = 0; j < count2; j++) {
            if (strcmp(words1[i], words2[j]) == 0) {
                printf("%s\n", words1[i]);
                i = count1;
                break;
            }
        }
    }
    return 0;
} 