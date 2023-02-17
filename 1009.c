#include <stdio.h>

void decode(char sentence[], int length) {
	for (int k = length / 2; k >= 1; k--) {
		//奇数位逆序
		//即将第一位移动至最后一位，其他位前移
		if (k % 2 == 1) {
			int point = k;
			char firstChar = sentence[point];
			while (point <= length) {
				point += k;
				sentence[point - k] = sentence[point];
			}
			sentence[point - k] = firstChar;
		}
		//偶数位顺序 
		//即将最后一位移动至第一位，其他位后移
		else {
			int point = length / k * k;
			char lastChar = sentence[point];
			while (point >= 1) {
				point -= k;
				sentence[point + k] = sentence[point];
			}
			sentence[point + k] = lastChar;
		}
	}
}

int main() {
	int length = 0;
	char ch;
	char sentence[1001];
	while ((ch = getchar()) != EOF) {
		if (ch != '\n') {
			sentence[++length] = ch;	
		} else {
			sentence[length + 1] = '\0';
			decode(sentence, length);
			for (int i = 1; i <= length; i++) {
				printf("%c", sentence[i]);
			}
			printf("\n");
			length = 0;
		}
	}
	return 0;
}