#include <stdio.h>
#include <math.h>

/*
�ο����ϣ�https://www.bilibili.com/video/BV14t411r7cT?spm_id_from=333.337.search-card.all.click
*/

int main() {
    int n;
    int f[14][14];
    double ans[101];
    f[1][1] = f[2][1] = f[2][2] = 1;
    //��Ȼn<=12���������Ľ���������������13��
    //����Ҫ���������ǵĵ�13��
    for (int i = 2; i <= 13; i++) {
        f[i][1] = f[i][i] = 1;
        for (int j = 2; j < i; j++) {
            f[i][j] = f[i - 1][j - 1] + f[i - 1][j];
        }
    }
    while (~scanf("%d", &n)) {
        int idx;
        double mum = pow(2, n);
        for (int i = 1; i <= n + 1; i++) {
            scanf("%d", &idx);
            ans[idx] = f[n + 1][i] / mum;
        }
        scanf("%d", &idx);
        printf("%lf\n", ans[idx]);
    }
}