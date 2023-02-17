#include <stdio.h>
#include <string.h>

int main() {
    //读入数据
    int length1;
    int length2;
    char str1[200];
    char str2[200];
    gets(str1);
    gets(str2);
    length1 = strlen(str1);
    length2 = strlen(str2);
    //求解
    int i = 0;
    int j = 0;
    int idx = 0;
    char ans[200];
    //需要保证i、j至少一个指针没有越界
    while (i < length1 || j < length2) {
        if (i < length1 && j < length2 && str1[i] == str2[j]) {
            ans[idx++] = str1[i];
            ans[idx++] = str2[j];
            i++;
            j++;
        }
        //移动单个指针需要考虑两种情况：
        //第一种，其中一个指针越界，则只能移动另外一个指针
        //第二种，两个指针都没有越界，则考虑字典序大小
        else if (i >= length1 || j < length2 && str1[i] > str2[j]) {
            ans[idx++] = str2[j];
            j++;
        }
        //由摩根定律可推知执行else语句的为如下条件：
        //i < length1 && (j >= length2 || str1[i] < str2[j])
        //即当j指针越界，或者两个指针均未越界，字典序str[i]<str2[j]
        //即等价于j >= length2 || i < length1 && str1[i] < str2[j]
        //故所有情况均已讨论完毕，代码是完全正确的
        else {
            ans[idx++] = str1[i];
            i++;
        }
    }
    ans[idx] = '\0';
    puts(ans);
}