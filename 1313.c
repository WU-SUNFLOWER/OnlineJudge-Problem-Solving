#include <stdio.h>

void swap(int* a, int* b) {
    int t = *a;
    *a = *b;
    *b = t;
}

int main() {
    int temp;
    int totalMoney;
    int totalType;
    char tempStr[1000];
    int priceArr[1000];
    int maxWeightArr[1000];
    while (~scanf("%d %d", &totalMoney, &totalType)) {
        if (totalMoney == 0 && totalType == 0) {
            break;
        }
        //存入所有菜品的信息
        for (int i = 0; i < totalType; i++) {
            scanf("%s %d %d", tempStr, &priceArr[i], &maxWeightArr[i]);
        }
        //使用贪心之前需要进行排序，把便宜的菜排到前面来
        for (int i = 0; i < totalType - 1; i++) {
            for (int j = 0; j <= totalType - 2 - i; j++) {
                if (priceArr[j] > priceArr[j + 1]) {
                    swap(&priceArr[j], &priceArr[j + 1]);
                    swap(&maxWeightArr[j], &maxWeightArr[j + 1]);
                }
            }
        }
        //开始买菜
        int curTypeIdx = 0;
        double ans = 0;
        //当没钱继续买菜了，或者菜已经全部被买光了，就退出循环
        while (totalMoney > 0 && curTypeIdx < totalType) {
            //第一种情况：当前的钱可以把当前种类的菜全部买下
            if (totalMoney >= priceArr[curTypeIdx] * maxWeightArr[curTypeIdx]) {
                totalMoney -= priceArr[curTypeIdx] * maxWeightArr[curTypeIdx];
                ans += maxWeightArr[curTypeIdx];
                curTypeIdx++;
            }
            //第二种情况：当前的钱只能把当前种类的菜部分买下
            else {
                ans += totalMoney * 1.0 / priceArr[curTypeIdx];
                totalMoney = 0;
            }
        }
        //输出答案，即买到菜的总重量
        printf("%.0lf\n", ans);
    }
}