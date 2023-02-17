#include<stdio.h>

/*
男方的分数等于把从自己所站的位置开始一直累加到开头，女方的分数等于从自己所站位置开始一直累加到末尾。
如果某一对新人的得分数是相同的，那你们就获胜。

无论地上的数字填成什么样子，女方站在开头和男方站在末尾就一定可以获奖。
*/

int main() {
	int n;
    int a[20002];
    int sumArr1[20002] = {0};  //用于记录男方站每一格可以获得的总分
    int sumArr2[20002];  //用于记录女方站每一格可以获得的总分
	while (scanf("%d", &n) != EOF && n != 0) {
        int count = 0;
        //获取数组
		for (int i = 1; i <= 2 * n; i++) {
			scanf("%d", &a[i]);
		}
        //打表
        //男方：站的位置一直累加到开头
        for (int i = 1; i <= 2 * n; i++) {
            sumArr1[i] = sumArr1[i - 1] + a[i];
        }
        //女方：站的位置一直累加到末尾
        for (int i = 1; i <= 2 * n; i++) {
            sumArr2[i] = sumArr1[2 * n] - sumArr1[2 * n - i];
        }
        int i = 1;
        int j = 1;
        while (i <= 2 * n && j <= 2 * n) {
            if (sumArr1[i] == sumArr2[j]) {  
    			count++;
                i++;
                j++;
            }
    		else if (sumArr1[i] < sumArr2[j]) { 
                i++;  
            } 
    		else {
    			j++;
    		}
        }
        printf("%d\n", count);
	}
	return 0;
}