#include <stdio.h>
#include <string.h>

//校验是否存在相邻重复子串
int isSimpleString(char str[], int tailIdx) {
    int ans = 0;
    int maxStep = (tailIdx + 1) / 2;
    //外层循环控制校验后缀的间距步长大小
    //内层循环进行后缀的逐个校验
    for (int i = 1; i <= maxStep; i++) {
        int j;
        for (j = tailIdx; j >= tailIdx - i + 1; j--) {
            //发现当前步长下出现不匹配，则停止校验，尝试下一种步长
            if (str[j] != str[j - i]) {
                break;
            }
        }
        if (j == tailIdx - i) {
            ans = 1;
            break;
        }
    }
    return ans;
}

int dfs(int* cntNode, int targetNode, int curLen, int dictSize, char ans[]) {
    if (*cntNode == targetNode) {
        for (int i = 0; i < curLen; i++) {
            printf("%c", ans[i]);
        }
        return 1;
    }
    //按照字典序顺序，从小到大地，枚举字典中的所有字符进行尝试
    for (char i = 'A'; i <= 'A' + (char)dictSize - 1; i++) {
        //先将枚举的字符写入数组，然后进行校验
        //如果校验成功，则说明该搜索节点的创建方案可行，继续往下搜索
        ans[curLen] = i;
        if (!isSimpleString(ans, curLen)) {
            (*cntNode)++;
            if (dfs(cntNode, targetNode, curLen + 1, dictSize, ans)) {
                return 1;
            }
        }
    }
    return 0;
}

int main() {
    int cntNode = 0;  //记录已经查找到的搜索节点数量
    int dictSize;
    int targetNode;
    char ans[10010];
    scanf("%d %d", &targetNode, &dictSize);
    dfs(&cntNode, targetNode, 0, dictSize, ans);
}