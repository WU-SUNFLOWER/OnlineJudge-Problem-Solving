#include <stdio.h>
#include <math.h>

int main() {
    int arr[10];
    for (int i = 0; i < 10; i++) {
        scanf("%d", &arr[i]);
    }
    int tempIdx = 0;
    int tempVal = abs(arr[0]);
    for (int i = 1; i < 10; i++) {
        if (abs(arr[i]) < tempVal) {
            tempVal = abs(arr[i]);
            tempIdx = i;
        }
    }
    int t = arr[9];
    arr[9] = tempVal;
    arr[tempIdx] = t;
    for (int i = 0; i < 10; i++) {
        printf(i <= 8 ? "%d " : "%d\n", arr[i]);
    }
}