#include <stdio.h>

int main() {
    int t;
    int index[1000];
    int tokenArr[1000];
    int scoreArr[1000];
    int sroceStair[101] = {0};
    scanf("%d", &t);
    while (t > 0) {
        int myToken;
        int studentNum = 0;
        scanf("%d", &myToken);
        while (~scanf("%d %d", &tokenArr[studentNum], &scoreArr[studentNum])) {
            if (tokenArr[studentNum] == 0 && scoreArr[studentNum] == 0) {
                break;
            }
            index[studentNum] = studentNum;
            studentNum++;
        }
        int idx = 0;
        int people = 0;
        for (int i = 0; i < studentNum; i++) {
            int k = i;
            for (int j = i + 1; j < studentNum; j++) {
                if (scoreArr[index[j]] > scoreArr[index[k]]) {
                    k = j;
                }
            }
            if (k != i) {
                int temp = index[k];
                index[k] = index[i];
                index[i] = temp;
            }
            //利用“前缀和”算法来实现排名的计算：
            //规定分数相同的学生处于同一分数阶梯
            //sroceStair[idx]表示处于第1阶梯~第idx阶梯的学生的总人数
            //那么分数处于第idx+1阶梯学生的排名就应当为sroceStair[idx]+1
            if (i > 0 && scoreArr[index[i]] < scoreArr[index[i - 1]]) {
                idx++;
                sroceStair[idx] = sroceStair[idx - 1] + people;
                people = 1;
            } else {
                people += 1;
            }
            if (tokenArr[index[i]] == myToken) {
                break;
            }
        }
        printf("%d\n", sroceStair[idx] + 1);
        //别忘了重置前缀和数组
        for (int i = 0; i <= idx; i++) {
            sroceStair[i] = 0;
        }
        t--;
    }
}