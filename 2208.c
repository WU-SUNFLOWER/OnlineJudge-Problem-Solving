#include <stdio.h>

int main() {
    int len1;
    int len2;
    int arr1[100];
    int arr2[100];
    int arr3[100];
    //读取数据
    scanf("%d", &len1);
    for (int i = 0; i < len1; i++) {
        scanf("%d", &arr1[i]);
    }
    scanf("%d", &len2);
    for (int i = 0; i < len2; i++) {
        scanf("%d", &arr2[i]);
    }
    int i = 0;
    int j = 0;
    int idx = 0;
    while (i < len1 || j < len2) {
        if (i >= len1 && j < len2 || arr2[j] <= arr1[i]) {
            arr3[idx++] = arr2[j++];
        }
        else if (i < len1 && j >= len2 || arr1[i] < arr2[j]) {
            arr3[idx++] = arr1[i++];
        }
    }
    for (int i = 0; i < idx; i++) {
        printf(i == idx - 1 ? "%d\n" : "%d ", arr3[i]);
    }
}