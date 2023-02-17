#include <stdio.h>

int main() {
    //标记道路上每个坐标的状态
    //0表示此处有树，1表示此处树被挖掉
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