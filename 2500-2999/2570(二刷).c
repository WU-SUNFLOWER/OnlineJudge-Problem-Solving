#include <stdio.h>
#include <stdbool.h>

int main() {
    int t;
    int target, length;
    int ar[110];
    scanf("%d", &t);
    while (t-- > 0) {
        scanf("%d %d", &target, &length);
        for (int i = 0; i < length; i++) {
            scanf("%d", ar + i);
        }
        int cnt = 0;
        int i = 0;
        int j = length - 1;
        bool flag = false;
        while (i <= j) {
            int mid = (i + j) >> 1;
            cnt++;
            if (ar[mid] == target) {
                flag = true;
                break;
            } else if (target < ar[mid]) {
                j = mid - 1;
            } else {
                i = mid + 1;
            }
        }
        printf(flag ? "%d\n" : "Not Found\n", cnt);
    }
}