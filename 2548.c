#include <stdio.h>

//把所有的数字从大到小排序后得到a
int getA(int num) {
    int idx = 0;
    int arr[4];
    while (num > 0) {
        arr[idx++] = num % 10;
        num /= 10;
    }
    for (int i = 0; i < idx - 1; i++) {
        for (int j = 0; j <= idx - 2 - i; j++) {
            if (arr[j] < arr[j + 1]) {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
    int ans = 0;
    for (int i = 0; i < idx; i++) {
        ans = ans * 10 + arr[i];
    }
    return ans;
}

//从小到大后得到b
int getB(int num) {
    int idx = 0;
    int arr[4];
    while (num > 0) {
        arr[idx++] = num % 10;
        num /= 10;
    }
    for (int i = 0; i < idx - 1; i++) {
        for (int j = 0; j <= idx - 2 - i; j++) {
            if (arr[j] > arr[j + 1]) {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
    int ans = 0;
    for (int i = 0; i < idx; i++) {
        ans = ans * 10 + arr[i];
    }
    return ans;
}

int main() {
    int lastNum = -1;
    int curNum;
    scanf("%d", &curNum);
    printf("%d", curNum);
    while (curNum != lastNum) {
        lastNum = curNum;
        curNum = getA(lastNum) - getB(lastNum);
        printf("->%d", curNum);
    }
}