#include <stdio.h>
#include <string.h>

int main() {
    int i;
    int j;
    int Anemone_Len;
    int Crab_Len;
    int Anemone[100000];
    int Crab[100000];
    char tempStr[100000];
    while (1) {
        //处理海葵数据
        scanf("%s", tempStr);
        if (tempStr[0] == '0')  {
            break;
        }
        for (i = 0; tempStr[i]; i++) {
            Anemone[i] = (int)(tempStr[i] - 'A');
        }
        Anemone_Len = i;
        //处理寄居蟹数据
        scanf("%s", tempStr);
        for (i = 0; tempStr[i]; i++) {
            Crab[i] = (int)(tempStr[i] - 'A');
        }
        Crab_Len = i;
        //处理海葵无法保护寄居蟹的情况
        if (Anemone_Len < Crab_Len) {
            printf("No\n");
            continue;
        }
        //匹配外壳
        i = 0;
        j = 0;
        int flag = 0;
        while (i < Anemone_Len && j < Crab_Len) {
            //情况一：两者当前褶皱匹配
            if (Anemone[i] + Crab[j] == 25) {
                i++;
                j++;
                if (j == Crab_Len) {
                    flag = 1;
                    break;
                }
            }
            //情况二：两者当前褶皱不匹配
            //则尝试用海葵的下一个褶皱进行匹配
            else {
                i++;
            }
        }
        if (flag) {
            printf("Yes\n");
        } else {
            printf("No\n");
        }
    }
}
