#include <stdio.h>

int main() {
    //��ǵ�·��ÿ�������״̬
    //0��ʾ�˴�������1��ʾ�˴������ڵ�
    int road[10001] = {0};  
    int length;
    int rangeNum;
    int count;
    scanf("%d %d", &length, &rangeNum);
    count = length + 1;
    for (int i = 1; i <= rangeNum; i++) {
        int left;
        int right;
        scanf("%d %d", &left, &right);
        for (int j = left; j <= right; j++) {
            if (road[j] == 0) {
                count--;
                road[j] = 1;
            }
        }
    }
    printf("%d\n", count);
}