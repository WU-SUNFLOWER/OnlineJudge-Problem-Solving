#include <stdio.h>
#include <string.h>

void removeElem(int ar[], int i, int* length) {
    for (int j = i; j <= *length - 2; j++) {
        ar[j] = ar[j + 1];
    }
    *length -= 1;
}

void insertElem(int ar[], int i, int elem, int* length) {
    for (int j = *length - 1; j >= i; j--) {
        ar[j + 1] = ar[j];
    }
    ar[i] = elem;
    *length += 1;
}

int main() {
    int i, j, len;
    scanf("i=%d,len=%d,j=%d", &i, &len, &j);
    int ar1[100];
    int ar2[100];
    int ar1_new[100];
    int len_ar1 = 0;
    int len_ar2 = 0;
    i--;
    j--;
    // 读取ar1
    while (scanf("%d", ar1 + len_ar1) && ar1[len_ar1] != -1) {
        len_ar1++;
    }
    // 读取ar2
    while (scanf("%d", ar2 + len_ar2) && ar2[len_ar2] != -1) {
        len_ar2++;
    }
    // 从ar1中删除元素
    for (int k = 0; k < len; k++) {
        removeElem(ar1, i, &len_ar1);
    }
    // 向ar2中插入元素
    for (int k = 0; k < len_ar1; k++) {
        insertElem(ar2, j + k, ar1[k], &len_ar2);
    }
    // 打印ar2
    for (int k = 0; k < len_ar2; k++) {
        printf(k == len_ar2 - 1 ? "%d\n" : "%d ", ar2[k]);
    }
}