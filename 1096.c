#include <stdio.h>

/*
有4个互不相同的数字，输出由其中三个不重复数字组成的排列。
*/

int main() {
	int arr[5];
	scanf("%d %d %d %d", &arr[1], &arr[2], &arr[3], &arr[4]);
	printf("%d %d %d\n", arr[1], arr[2], arr[3]);
	printf("%d %d %d\n", arr[1], arr[3], arr[2]);
	printf("%d %d %d\n", arr[2], arr[1], arr[3]);
	printf("%d %d %d\n", arr[2], arr[3], arr[1]);
	printf("%d %d %d\n", arr[3], arr[1], arr[2]);
	printf("%d %d %d\n", arr[3], arr[2], arr[1]);
	printf("%d %d %d\n", arr[1],  arr[2],  arr[4]);
	printf("%d %d %d\n", arr[1],  arr[4],  arr[2]);
	printf("%d %d %d\n", arr[2],  arr[1],  arr[4]);
	printf("%d %d %d\n", arr[2],  arr[4],  arr[1]);
	printf("%d %d %d\n",arr[4],  arr[1],  arr[2] );
	printf("%d %d %d\n", arr[4],  arr[2],  arr[1]);
	printf("%d %d %d\n", arr[1],  arr[3],  arr[4]);
	printf("%d %d %d\n", arr[1],  arr[4],  arr[3]);
	printf("%d %d %d\n", arr[3],  arr[1],  arr[4]);
	printf("%d %d %d\n", arr[3],  arr[4],  arr[1] );
	printf("%d %d %d\n", arr[4],  arr[1],  arr[3]);
	printf("%d %d %d\n", arr[4],  arr[3],  arr[1]);
	printf("%d %d %d\n", arr[2],  arr[3],  arr[4]);
	printf("%d %d %d\n", arr[2],  arr[4],  arr[3]);
	printf("%d %d %d\n", arr[3],  arr[2],  arr[4]);
	printf("%d %d %d\n", arr[3],  arr[4],  arr[2] );
	printf("%d %d %d\n", arr[4],  arr[2],  arr[3]);
	printf("%d %d %d\n", arr[4],  arr[3],  arr[2]);
}