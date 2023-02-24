#include <stdio.h>

//²Î¿¼×ÊÁÏ£ºhttps://blog.csdn.net/qq_43628835/article/details/105837883

int main() {
    int n;
    int f[202];
    f[1] = 1;
    for (int i = 2; i <= 201; i++) {
        f[i] = 1;
        for (int j = 1; j <= i / 2; j++) {
            f[i] += f[j];
        }
    }
    while (scanf("%d", &n) != EOF) {
        printf("%d\n", f[n]);
    }
}