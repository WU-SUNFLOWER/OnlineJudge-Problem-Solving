#include <stdio.h>

int main() {
    int n;
    int moveStep;
    int arr[100];
    int tempArr[100];
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    scanf("%d", &moveStep);
    //缓存尾部被覆盖的数据
    for (int i = n - moveStep, j = 0; i < n; i++, j++) {
        tempArr[j] = arr[i];
    }
    //向后挪动原数组数据
    for (int i = n - moveStep - 1; i >= 0; i--) {
        arr[i + moveStep] = arr[i];
    }
    //在数组头部重新写入缓存数据
    for (int i = 0; i < moveStep; i++) {
        arr[i] = tempArr[i];
    }
    //输出
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
}