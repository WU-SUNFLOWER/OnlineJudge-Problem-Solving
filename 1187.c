#include <stdio.h>

/*
��ԭ����һȺ��,��һ��������һȺ�����������м�Ⱥ��? ��������˵����Ⱥ���!
Ϊ�˷�ֹ���˽�"һȺ��"�ĸ�������,�ָ��������. 
����ԭ���뻯Ϊһ������ľ���,�ҽ�������Ϊһ��������ĵ�λС����,ÿһС������ǡ��������һͷ��,
������a,����b����aΪͬһȺ��Ӧ������b���ڵ�С�������a���ڵ�С�������ڵ�8������ 
��С������������������С���鱻���Ϊ1,���򱻱��Ϊ0.�ָ���һ�����ε�С��������һ���м�Ⱥ��?
*/

void dfs(char matrix[][100], int weight, int height, int i, int j) {
    if (matrix[i][j] == '0') {
        return;
    }
    //ע�����ø��С��
    matrix[i][j] = '0';
    //���Ϸ�����
    if (i >= 1) {
        dfs(matrix, weight, height, i - 1, j);
    }
    //���·�����
    if (i <= height - 2) {
        dfs(matrix, weight, height, i + 1, j);
    }
    //��������
    if (j >= 1) {
        dfs(matrix, weight, height, i, j - 1);
    }
    //���ҷ�����
    if (j <= weight - 2) {
        dfs(matrix, weight, height, i, j + 1);
    }
    //����������
    if (i >= 1 && j >= 1) {
        dfs(matrix, weight, height, i - 1, j - 1);
    }
    //����������
    if (i >= 1 && j <= weight - 2) {
        dfs(matrix, weight, height, i - 1, j + 1);
    }
    //����������
    if (j >= 1 && i <= height - 2) {
        dfs(matrix, weight, height, i + 1, j - 1);
    }
    //����������
    if (j <= weight - 2 && i <= height - 2) {
        dfs(matrix, weight, height, i + 1, j + 1);
    }
}

int main() {
    int height;
    int weight;
    char matrix[100][100];  //[��][��]
    while (scanf("%d %d", &height, &weight) != EOF) {
        int ans = 0;
        if (height == 0 && weight == 0) {
            break;
        }
        //���վ���
        for (int i = 0; i < height; i++) {
            scanf("%s", &matrix[i]);
        }
        //��������
        for (int i = 0; i < height; i++) {
            for (int j = 0; j < weight; j++) {
                if (matrix[i][j] == '1') {
                    ans++;
                    dfs(matrix, weight, height, i, j);
                }
            }
        }
        //�����
        printf("%d\n", ans);
    }
}