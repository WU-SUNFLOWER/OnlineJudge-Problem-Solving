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
            //���á�ǰ׺�͡��㷨��ʵ�������ļ��㣺
            //�涨������ͬ��ѧ������ͬһ��������
            //sroceStair[idx]��ʾ���ڵ�1����~��idx���ݵ�ѧ����������
            //��ô�������ڵ�idx+1����ѧ����������Ӧ��ΪsroceStair[idx]+1
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
        //����������ǰ׺������
        for (int i = 0; i <= idx; i++) {
            sroceStair[i] = 0;
        }
        t--;
    }
}