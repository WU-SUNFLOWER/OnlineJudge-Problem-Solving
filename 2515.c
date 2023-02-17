#include <stdio.h>
#include <string.h>

struct homework {
    int score;
    int ddl;
    int isScheduled;
};

void sort(struct homework HwArr[], int length) {
    struct homework temp;
    for (int i = 0; i < length - 1; i++) {
        for (int j = 0; j <= length - 2 - i; j++) {
            if (HwArr[j].score < HwArr[j + 1].score) {
                temp = HwArr[j];
                HwArr[j] = HwArr[j + 1];
                HwArr[j + 1] = temp;
            }
        }
    }
}

int main() {
    int hwNum;
    //schedule数组用于记录作业日程
    //schedule[i]=1表示第i天已安排作业，否则该天空闲
    int schedule[100];
    struct homework HwArr[100];
    while (~scanf("%d", &hwNum)) {
        memset(schedule, 0, sizeof(schedule));
        //接收作业的ddl
        for (int i = 0; i < hwNum; i++) {
            HwArr[i].isScheduled = 0;
            scanf("%d", &HwArr[i].ddl);
        }
        //接收作业的开心值
        for (int i = 0; i < hwNum; i++) {
            scanf("%d", &HwArr[i].score);
        }
        //依照开心值对作业进行降序排序，确保先做的作业开心值最大
        sort(HwArr, hwNum);
        //从开心值最大的作业开始，安排作业日程
        for (int i = 0; i < hwNum; i++) {
            for (int j = HwArr[i].ddl; j >= 1; j--) {
                if (!schedule[j]) {
                    schedule[j] = 1;
                    HwArr[i].isScheduled = 1;
                    break;
                }
            }
        }
        //统计仍然无法完成的作业，计算答案
        int ans = 0;
        for (int i = 0; i < hwNum; i++) {
            if (!HwArr[i].isScheduled) {
                ans += HwArr[i].score;
            }
        }
        printf("%d\n", ans);
    }
}