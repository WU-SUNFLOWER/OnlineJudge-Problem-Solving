#include <stdio.h>

int main() {
    int ar1[100];
    int ar2[100];
    int idx1 = 0;
    int idx2 = 0;
    while (~scanf("%d", &ar1[idx1]) && ar1[idx1] != -1) {
        idx1++;
    }
    while (~scanf("%d", &ar2[idx2]) && ar2[idx2] != -1) {
        idx2++;
    }
    int i = 0;
    int j = 0;
    int idx3 = 0;
    int ans[100];
    while (i < idx1 && j < idx2) {
        if (ar1[i] == ar2[j]) {
            ans[idx3++] = ar1[i];
            i++;
            j++;
        } 
        else if (ar1[i] > ar2[j]) {
            j++;
        }
        else {
            i++;
        }
    }
    for (int i = 0; i < idx3; i++) {
        printf("%d ", ans[i]);
    }
}