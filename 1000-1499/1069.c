#include <stdio.h>
#include <stdlib.h>

char* createCharArray(int length) {
	char* arr = (char*)malloc(sizeof(char) * (length + 1));
	for (int i = 0; i <= length; i++) {
		arr[i] = '\0';
	}
	return arr;
}

int main() {
	int height;
	char* LineAnsArr[100];
    while (scanf("%d", &height) != EOF && height != 0) {
        int n = 1;  //行号
    	//生成头部
        for (; n <= height / 2; n++) {
            int idx = 0;
            char* curLine = createCharArray(height);
            //生成空格
            for (int i = 1; i <= height / 2 - n + height % 2; i++) {
                curLine[idx++] = ' ';
            }
            //生成*号
            for (int i = 1; i <= 2 * n - 1; i++) {
                curLine[idx++] = '*';
            }
            LineAnsArr[n] = curLine;
            printf("%s\n", curLine);
        }
        //奇数高度需要生成中部
        if (height % 2 == 1) {
            int idx = 0;
            char* curLine = createCharArray(height);
            for (int i = 1; i <= 2 * n - 1; i++) {
                curLine[idx++] = '*';
            }
            printf("%s\n", curLine);
            free(curLine);
            n++;
        }
        //生成尾部
        for (; n <= height; n++) {
            printf("%s\n", LineAnsArr[height - n + 1]);
            free(LineAnsArr[height - n + 1]);
        }
    }
}