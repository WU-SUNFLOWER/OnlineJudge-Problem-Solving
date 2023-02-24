#include <stdio.h>

//已知小葱班里33个同学，学号是4,6,8,10,12,13,16,18,19,21,32为女生
int isGirl(int id) { 
    return id == 4 || id == 6 || id == 8 || id == 10 ||
           id == 12 || id == 13 || id == 16 || id == 18 ||
           id == 19 || id == 21 || id == 32;
}

int main() {
    int startId;
    int ansCount = 0;
    scanf("%d", &startId);
    //从1~100选取号码进行模拟
    for (int i = 1; i <= 100 && ansCount < 10; i++) {
        int start = 0;
        int end = 100;
        int curId = startId;
        //从第curId个人开始，逐个人进行猜数
        while (ansCount < 10) {
            //跳转到下一个人
            curId = curId % 33 + 1;
            //分男生和女生的不同情况进行猜数
            if (isGirl(curId) || end - start < 3) {
                start += 1;
            } else {
                int newBorder = (end - start) / 3 + start;
                newBorder > i ? (end = newBorder) : (start = newBorder);
            }
            //如果猜到，则本轮游戏结束
            if (start == i) {
                isGirl(curId) && (ansCount++, printf("%-2d %d\n", i, curId));
                break;
            }
        }
    }
    return 0;
}