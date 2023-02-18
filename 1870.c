#include <stdio.h>
#include <stdbool.h>
#define N 10

int top[N];

int bottom[N];

void outputAns() {
    for (int i = 0; i < N; i++) {
        printf(i == N - 1 ? "%d\n" : "%d ", bottom[i]);
    }
}

/*
    �����⣬bottom����Ӧ�����������ʣ�
    1. �������е���һԪ��bottom[i]������0 �� bottom[i] ��10;
    2. bottom[0] + bottom[1] + ... + bottom[9] = 10;
    3. bottom[i]��ʾ��Ӧtop[i]��bottom�����г��ֵĴ���
*/
bool dfs(int sum) {
    // ���sum��û��10���ͳ�����������
    if (sum < N) {
        for (int i = 0; i < N; i++) {
            bottom[i]++;
            if (dfs(sum + 1)) return true;
            bottom[i]--;
        }
        return false;
    }
    // ���sum�Ѿ���10����У�鵱ǰ����Ƿ��������
    else if (sum == N) {
        int cnt;
        for (int i = 0; i < N; i++) {
            cnt = 0;
            for (int j = 0; j < N; j++) {
                if (bottom[j] == top[i]) cnt++;
            }
            if (cnt != bottom[i]) return false;
        }
        outputAns();
        return true;
    }
}

int main() {
    for (int i = 0; i < N; i++) {
        scanf("%d", &top[i]);
    }
    dfs(0);
}