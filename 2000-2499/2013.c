#include <stdio.h>

/*
���һ�������е�ĳһ�Σ�����������Ԫ�أ��ĸ�Ԫ��ֵ����ͬ�����֮Ϊ��ֵ���жΡ�
��ֵ���ж���Ԫ�صĸ���������ֵ���жεĳ��ȡ�

����
��N��Ԫ����ɵ���������A������N<=50)
��������һ�����֣���ʾ��������м���������ɣ�Ȼ��س�
���������������ÿ������(0-9)������һ�����֣��س�һ�¡�


���
A�г����������е�ֵ���жε�ʼĩλ�ã���The longest equal number list is from��ͷ
���û�е�ֵ���жΣ������ No equal number list.
˵����ʼĩλ����ָ�����±꣬��0��ʾ��һ��Ԫ�ء� ����ж��ͬ�ȳ��ȵĵ�ֵ���У�ֻ�����һ����ֵ���е���ʼλ�á� ����һ��LIST�г��������ȳ�����������ʱ�����ǵĴ�Ӧ���ǵ�һ���ȳ�����
*/

/*
���룺
5
1
1
1
2
2
�����
The longest equal number list is from 0 to 2.
*/

int main() {
	int length;
	int arr[50];
	int ansLen = 0;
	int ansLeftBordar;
	int ansRightBordar;
	int tempLen = 1;
	int tempLeftBordar = 0;
	int tempRightBordar;
	scanf("%d", &length);
	for (int i = 0; i < length; i++) {
		scanf("%d", &arr[i]);
		if (i == 0) {
			continue;
		}
		if (arr[i] == arr[i - 1]) {
			tempLen++;
			tempRightBordar = i;
			if (i == length - 1 && tempLen > ansLen) {
				ansLen = tempLen;
				ansLeftBordar = tempLeftBordar;
				ansRightBordar = tempRightBordar;
			}
		}
		else {
			if (tempLen > ansLen) {
				ansLen = tempLen;
				ansLeftBordar = tempLeftBordar;
				ansRightBordar = tempRightBordar;
			}
			tempLen = 1;
			tempLeftBordar = i;
		}
	}
	if (ansLen > 1) {
		printf("The longest equal number list is from %d to %d.\n", ansLeftBordar, ansRightBordar);
	} else {
		printf("No equal number list.");
	}
}