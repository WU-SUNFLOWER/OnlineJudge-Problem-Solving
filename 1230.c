#include <stdio.h>
#include <math.h>

//��ĳ��������������
int getSubCount(int n) {
    int ans = 0;
    for (int i = 1; i <= sqrt(n); i++) {
        if (n % i == 0) {
            ans += n / i == i ? 1 : 2;
        }
    }
    return ans;
}

int main() {
    int num;
    int map[1000];
    //���
    //��ʵ������Ӧ�Ե�ʱ�����������ѡ��
    //��Ϊ��Ŀ��û���ṩ�������ݵ����ݷ�Χ
    //�����ݷ�Χ�������ʺϴ�����ܻ�������ʱ������
    for (int i = 1; i <= 1000; i++) {
        map[i] = getSubCount(i);
    }
    while (~scanf("%d", &num)) {
        int tempNum;
        int ans;
        int ansCount;
        for (int i = 0; i < num; i++) {
            scanf("%d", &tempNum);
            if (i == 0) {
                ans = tempNum;
                ansCount = map[ans];
            } 
            else if (map[tempNum] > ansCount || map[tempNum] == ansCount && tempNum < ans) {
                ans = tempNum;
                ansCount = map[ans];
            }
        }
        printf("%d\n", ans);
    }
}