#include <stdio.h>
#include <math.h>

/*
����֪���������1��2��5��10��20��50��100�⼸����ֵ�� 
���ڸ���n(1��n��250)Ԫ��������㻻����������Щ����ʾ������������100�ţ����м��֡� 
����4Ԫ������4��1Ԫ��2��1Ԫ��1��2Ԫ��2��2Ԫ�����ֱ�ʾ������
*/

int f[251];
int valueData[7] = {1, 2, 5, 10, 20, 50, 100};

void dfs(int completeValue, int leftValue, int lastValueLevel, int leftChance) {
    if (leftValue < 0 || leftChance < 0) {
        return;
    }
    f[completeValue]++;
    for (int i = lastValueLevel; i < 7; i++) {
        dfs(completeValue + valueData[i], leftValue - valueData[i], i, leftChance - 1);
    }
}

int main() {
    int totalValue;
    for (int i = 0; i <= 250; i++) {
        f[i] = 0;
    }
    dfs(0, 250, 0, 100);
    while (scanf("%d", &totalValue) != EOF && totalValue != 0) {
        printf("%d\n", f[totalValue]);
    }
}