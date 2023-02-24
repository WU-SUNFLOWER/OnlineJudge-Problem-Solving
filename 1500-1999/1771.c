#include <stdio.h>
#include <string.h>

int main() {
    int len;
    int subLen;
    char str[100];
    char subStr[100];
    scanf("%s %s", str, subStr);
    len = strlen(str);
    subLen = strlen(subStr);
    //在[0, subLen]的区间范围为尝试不同的滑动窗口起始位置
    int ans = 0;
    for (int i = 0; i < subLen; i++) {
        //滑动窗口
        for (int j = i; j <= len - subLen; j += subLen) {
            //校验滑动窗口框住的区域是否等于欲搜索的字串
            int flag = 1;
            for (int k = 0; k < subLen; k++) {
                if (str[j + k] != subStr[k]) {
                    flag = 0;
                    break;
                }
            }
            //如果匹配到字串，则记录下j，并且退出循环
            if (flag) {
                ans++;
            }
        }
    }
    printf("%d\n", ans);
}