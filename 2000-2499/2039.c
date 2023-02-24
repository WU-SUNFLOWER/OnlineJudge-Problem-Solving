#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct {
	char* value;
	int length;
} String;

String createString(char* source) {
	int length = strlen(source);
	char* arr = (char*)malloc(sizeof(char) * (length + 1));
	strcpy(arr, source);
	String newString = {arr, length};
	return newString;
}

int main() {
	char tempName[17];
	char* AnsArr[1000];
	String ExeFileNameArr[1000];
	String OtherFileNameArr[1000];
	while (1) {
		int n;
		int AnsIdx = -1;
		int ExeFileIdx = -1;
		int OtherFileIdx = -1;
		scanf("%d", &n);
		if (n <= 0) {
			break;
		}
		for (int i = 0; i < n; i++) {
			scanf("%s", &tempName);
			String fileName = createString(&tempName[0]);
			int len = fileName.length;
			if (strcmp(&tempName[len - 4], ".exe") == 0) {
				ExeFileNameArr[++ExeFileIdx] = fileName;
				OtherFileNameArr[++OtherFileIdx] = fileName;
			} else {
				OtherFileNameArr[++OtherFileIdx] = fileName;
			}
		}
		for (int i = 0; i <= OtherFileIdx; i++) {
			char* otherFileName = OtherFileNameArr[i].value;
			int otherFileName_Len = OtherFileNameArr[i].length;
			for (int j = 0; j <= ExeFileIdx; j++) {
				int flag = 1;
				char* exeFileName = ExeFileNameArr[j].value;
				int exeFileName_Len = ExeFileNameArr[j].length;
				if (exeFileName_Len - 4 == otherFileName_Len) {
					for (int strIdx = 0; strIdx < otherFileName_Len; strIdx++) {
						if (otherFileName[strIdx] != exeFileName[strIdx]) {
							flag = 0;
							break;
						}
					}
				} else {
					flag = 0;
				}
				if (flag) {
					AnsArr[++AnsIdx] = exeFileName;
					break;
				}
			}
		}
		for (int i = 0; i <= AnsIdx; i++) {
			for (int j = AnsIdx; j >= i + 1; j--) {
				if (strcmp(AnsArr[j - 1], AnsArr[j]) > 0) {
					char* temp = AnsArr[j];
					AnsArr[j] = AnsArr[j - 1];
					AnsArr[j - 1] = temp;
				}
			}
			printf("%s\n", AnsArr[i]);
		}
		for (int i = 0; i <= OtherFileIdx; i++) {
			free(OtherFileNameArr[i].value);
		}
	}
}