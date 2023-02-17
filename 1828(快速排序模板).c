#include <stdio.h>

void Get(int A[], int MaxSize) {
	int first = 0;
	int last = MaxSize - 1;
	while (first < last) {
		//�������Ԫ��Ϊ�������ұ�����Ԫ��Ϊż��
		//�������Ԫ��<0���ұ�����Ԫ��>0
		
		//A[first]Ϊ������A[last]Ϊż��
		if (A[first] < 0 && A[last] > 0) {
			first++; 
			last--; 
			continue;
		}
		//A[first]Ϊż����A[last]Ϊ����
		if (A[first] > 0 && A[last] < 0)
		{
			int m = A[first];
			A[first] = A[last];
			A[last] = m;
			first++; last--; 
			continue;
		}
		//A[first]��A[last]ͬΪż��
		if (A[first] < 0 && A[last] < 0) {
			first++;
			continue;
		}
		//A[first]��A[last]ͬΪ����
		if (A[first] > 0 && A[last] > 0) {
			last--;
			continue;
		}
	}

}

int main() {
	int n;
	int idx;
	int arr[100];
	while (scanf("%d", &n) != EOF) {
		for (idx = 0; idx < n; idx++) {
			scanf("%d", &arr[idx]);
		}
		Get(arr, n);
		for (idx = 0; idx < n; idx++) {
			printf(idx == n - 1 ? "%d\n" : "%d ", arr[idx]);
		}
	}
}