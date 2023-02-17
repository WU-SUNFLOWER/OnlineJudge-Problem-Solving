#include <stdio.h>

void dfs(int leftUserNum1, int leftUserNum2, int leftChange, int* ans) {
    //��һ������������û��Ѿ��������
    if (leftUserNum1 == 0 && leftUserNum2 == 0) {
        *ans += 1;
        return;
    }
    //�ڶ����������ǰ�û��õ���һ��Ԫ�ĳ�Ʊ������ʮԪ����Ǯ�㹻
    if (leftUserNum2 > 0 && leftChange > 0) {
        dfs(leftUserNum1, leftUserNum2 - 1, leftChange - 1, ans);
    }
    //�������������ǰ�û��õ�����ʮԪ����Ǯ
    if (leftUserNum1 > 0) {
        dfs(leftUserNum1 - 1, leftUserNum2, leftChange + 1, ans);
    }
}

int main() {
    int ans = 0;
    int leftUserNum1;
    int leftUserNum2;
    scanf("%d,%d", &leftUserNum1, &leftUserNum2);
    dfs(leftUserNum1, leftUserNum2, 0, &ans);
    printf("%d\n", ans);
}