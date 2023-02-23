#include <stdio.h>

int main() {
    int len1;
    int len2;
    int len3;
    int ar1[100];
    int ar2[100];
    int ar3[100];
    // 读取数据
    scanf("%d", &len1);
    for (int i = 0; i < len1; i++) {
        scanf("%d", &ar1[i]);
    }
    scanf("%d", &len2);
    for (int i = 0; i < len2; i++) {
        scanf("%d", &ar2[i]);
    }
    scanf("%d", &len3);
    for (int i = 0; i < len3; i++) {
        scanf("%d", &ar3[i]);
    }
    // 单调性问题模板
    int i = 0;
    int j = 0;
    int len4 = 0;
    int ar4[100];
    while (i < len1 && j < len2) {
        if (ar1[i] == ar2[j]) {
            ar4[len4++] = ar1[i];
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
    int k = 0;
    int m = 0;
    int idx = 0;
    int ans[100];
    while (k < len3 && m < len4) {
        if (ar3[k] == ar4[m]) {
            ans[idx++] = ar3[k];
            k++;
            m++;
        }
        else if (ar3[k] > ar4[m]) {
            m++;
        } 
        else {
            k++;
        }
    }
    for (int i = 0; i < idx; i++) {
        printf("%d ", ans[i]);
    }
}