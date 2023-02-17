#include <stdio.h>
#include <stdlib.h>
#include <string.h>

const int N = 100;

char* createString(int length) {
    char* p = (char*)malloc(sizeof(char) * (length + 1));
    return p;
}

//创建一块数组空间
//对句子中的英文单词进行拆解，并将拆解后的单词存入该空间
char** deconstruct(char sentence[], int* count) {
    int isNewWord = 1;
    int idx = 0;
    int wordIdx = 0;
    char** words = (char**)malloc(sizeof(char*) * N);
    for (int i = 0; sentence[i]; i++) {
        char ch = sentence[i];
        //第一种情况：如果遇见新单词，则开辟新空间进行写入
        if (ch != ' ' && isNewWord) {
            wordIdx = 0;
            isNewWord = 0;
            words[idx] = createString(N);
            words[idx][wordIdx++] = ch;
        }
        //第二种情况：正在接收单词
        else if ('a' <= ch && ch <= 'z') {
            words[idx][wordIdx++] = ch;
        }
        //第三种情况：(非末尾的)单词接收结束
        else if (ch == ' ' && !isNewWord) {
            words[idx++][wordIdx] = '\0';
            isNewWord = 1;
        }
    }
    //处理末尾接收的单词
    words[idx++][wordIdx] = '\0';
    //标记结束位,并保存拆解出的单词总数
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
    //接收句子
    char sentence1[200];
    char sentence2[200];
    gets(sentence1);
    gets(sentence2);
    //对单词进行拆解
    int count1;
    int count2;
    char** words1 = deconstruct(sentence1, &count1);
    char** words2 = deconstruct(sentence2, &count2);
    //对单词按长度进行降序排序
    sort(words1, count1);
    sort(words2, count2);
    //查找
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