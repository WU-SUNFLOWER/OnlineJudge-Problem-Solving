#include <stdio.h>
#include <string.h>

int isEnglishLetter(char ch) {
	return 'a' <= ch && ch <= 'z' || 'A' <= ch && ch <= 'Z';
}

int min(int a, int b) {
	return a < b ? a : b;
}

int max(int a, int b) {
	return a > b ? a : b;
}

char toLowerCase(char letter) {
	if ('A' <= letter && letter <= 'Z') {
		letter = letter + ('a' - 'A');
	}
	return letter;
}

int getWordsFromSentence(char Sentence[], char WordArr[][25]) {
	int wordIdx = -1;
	int wordCharIdx;
	int isValidWordMeeted = 0;
	for (int i = 0; Sentence[i]; i++) {
		if (isValidWordMeeted) {
			if (isEnglishLetter(Sentence[i])) {
				WordArr[wordIdx][++wordCharIdx] = toLowerCase(Sentence[i]);
				WordArr[wordIdx][wordCharIdx + 1] = '\0';
			} else {
				isValidWordMeeted = 0;
			}
		}
		else if (isEnglishLetter(Sentence[i])) {
			isValidWordMeeted = 1;
			wordCharIdx = -1;
			WordArr[++wordIdx][++wordCharIdx] = toLowerCase(Sentence[i]);
			WordArr[wordIdx][wordCharIdx + 1] = '\0';
		}
	}
	return wordIdx;
}

void sortByStrlen(char WordArr[][25], int idxArr[], int wordEndIdx) {
	int temp;
	for (int i = 0; i < wordEndIdx; i++) {
		int flag = 1;
		for (int j = 0; j <= wordEndIdx - 1 - i; j++) {
			if (strlen(&WordArr[idxArr[j]][0]) < strlen(&WordArr[idxArr[j + 1]][0])) {
				temp = idxArr[j];
				idxArr[j] = idxArr[j + 1];
				idxArr[j + 1] = temp;
				flag = 0;
			}
		}
		if (flag) {
			break;
		}
	}
}

int main() {
	int idxArr1[300];
	int idxArr2[300];
	char Sentence1[400];
	char Sentence2[400];
	int wordEndIdx1;
	int wordEndIdx2;
	char WordArr1[300][25];
	char WordArr2[300][25];
	while (gets(Sentence1) != NULL) {
		//读取字符,并提取单词
		//初始化索引数组
		wordEndIdx1 = getWordsFromSentence(Sentence1, WordArr1);
		gets(Sentence2);
		wordEndIdx2 = getWordsFromSentence(Sentence2, WordArr2);
		int wordEndIdx_Max = max(wordEndIdx1, wordEndIdx2);
		for (int i = 0; i <= wordEndIdx_Max; i++) {
			idxArr1[i] = i;
			idxArr2[i] = i;
		}
		//排序
		sortByStrlen(WordArr1, idxArr1, wordEndIdx1);
		sortByStrlen(WordArr2, idxArr2, wordEndIdx2);
		//查询结果
		int flag = 1;
		for (int i = 0; i <= wordEndIdx1; i++) {
			for (int j = 0; j <= wordEndIdx2; j++) {
				if (strcmp(WordArr1[idxArr1[i]], WordArr2[idxArr2[j]]) == 0) {
					flag = 0;
					printf("%s\n", WordArr1[idxArr1[i]]);
				}
			}
		}
		flag && printf("No common word!\n");		
	}
	return 0;
}