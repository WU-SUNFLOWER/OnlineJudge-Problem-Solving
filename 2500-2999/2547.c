#include <stdio.h>

int main() {
    int length = 0;
    int arr[1000];
    while (~scanf("%d", &arr[length])) {
        if (arr[length] == 0) {
            break;
        }
        length++;
    }
    //ÅÅÐò
    for (int i = 0; i < length / 2 - 1; i++) {
        for (int j = 0; j <= length - 3 - i; j++) {
            if (arr[j] > arr[j + 2]) {
                int temp = arr[j];
                arr[j] = arr[j + 2];
                arr[j + 2] = temp;
            }
        }
    }
    //Êä³ö
    for (int i = 0; i < length; i++) {
        printf(i == length - 1 ? "%d" : "%d ", arr[i]);
    }
}