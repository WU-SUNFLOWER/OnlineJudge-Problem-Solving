#include <stdio.h>
#include <math.h>

/*
在世界的某个角落有这样的一个国家，他们的计数全部是采用二进制的。这样的好处就是他们只需要两个阿拉伯数字就OK了！ 
这个国家对数字是很迷信的。他们很讨厌有两个或两个以上的数字1连在一起，比如000110这个数字就不受人们的欢迎（嘿嘿，就像我们对数字4不是很欢迎一样）。 
这里的人们经常做的一件事情是给你一个数的位数再将它们的所有的排列写出来，再将那些不讨人喜欢的数字全部去掉，再计算出讨人喜欢的数字的个数。 
例如：给你一个数的位数是3，它的所有排列是000 001 010 011 100 101 110 111，很明显受人喜欢的数字是5个！ 
也许你认为这是一件很没价值的事情，但这确是很必要的事情，比如说某一家人要做喜事，那你说选日子是不是很重要呢？ 
有一天这件事情被你知道了，你很乐于助人，决定编一个程序来帮他们解决这个问题！
*/

/*
输入
第一行为测试数据的组数。 每组测试数据为一行，每行只有一个值为二进制数的位数s(s<=40)。

输出
每组测试数据对应一个输出。输出包括两行。第一行为"Scenario #i:"(不包括双引号), 
其中i为测试数据的组数，从1开始。第二行为受人们喜欢的位数为s的数的个数。 每组测试情况以一个空行隔开。

输入样例 1:
2
3
1
输出样例 1:
Scenario #1:
5

Scenario #2:
2
*/

int f[41];

void dfs(int curStep, int maxStep, int curNum) {
    f[curStep] += curNum == 1 ? 1 : 2;
    if (curStep < maxStep) {
        dfs(curStep + 1, maxStep, 0);
        if (curNum != 1) {
            dfs(curStep + 1, maxStep, 1);
        }
    }
}

int main() {
    int n;
    int idx = 0;
    int GroupNum;
    int arr[40];
    scanf("%d", &GroupNum);
    int max = 0;
    while (idx < GroupNum) {
        scanf("%d", &n);
        arr[idx++] = n;
        n > max && (max = n);
    }
    dfs(1, max, 0);
    idx = 0;
    while (idx < GroupNum) {
        printf("Scenario #%d:\n%d\n\n", idx, f[arr[idx++]]);
    }
}