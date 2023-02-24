#include <stdio.h>

void Get(int A[], int MaxSize) {
	int first = 0;
	int last = MaxSize - 1;
	while (first < last) {
		//左边所有元素为奇数，右边所有元素为偶数
		//左边所有元素<0，右边所有元素>0
		
		//A[first]为奇数且A[last]为偶数
		if (A[first] < 0 && A[last] > 0) {
			first++; 
			last--; 
			continue;
		}
		//A[first]为偶数，A[last]为奇数
		if (A[first] > 0 && A[last] < 0)
		{
			int m = A[first];
			A[first] = A[last];
			A[last] = m;
			first++; last--; 
			continue;
		}
		//A[first]和A[last]同为偶数
		if (A[first] < 0 && A[last] < 0) {
			first++;
			continue;
		}
		//A[first]和A[last]同为奇数
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