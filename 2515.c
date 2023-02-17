#include <stdio.h>
#include <string.h>

struct homework {
    int score;
    int ddl;
    int isScheduled;
};

void sort(struct homework HwArr[], int length) {
    struct homework temp;
    for (int i = 0; i < length - 1; i++) {
        for (int j = 0; j <= length - 2 - i; j++) {
            if (HwArr[j].score < HwArr[j + 1].score) {
                temp = HwArr[j];
                HwArr[j] = HwArr[j + 1];
                HwArr[j + 1] = temp;
            }
        }
    }
}

int main() {
    int hwNum;
    //schedule�������ڼ�¼��ҵ�ճ�
    //schedule[i]=1��ʾ��i���Ѱ�����ҵ������������
    int schedule[100];
    struct homework HwArr[100];
    while (~scanf("%d", &hwNum)) {
        memset(schedule, 0, sizeof(schedule));
        //������ҵ��ddl
        for (int i = 0; i < hwNum; i++) {
            HwArr[i].isScheduled = 0;
            scanf("%d", &HwArr[i].ddl);
        }
        //������ҵ�Ŀ���ֵ
        for (int i = 0; i < hwNum; i++) {
            scanf("%d", &HwArr[i].score);
        }
        //���տ���ֵ����ҵ���н�������ȷ����������ҵ����ֵ���
        sort(HwArr, hwNum);
        //�ӿ���ֵ������ҵ��ʼ��������ҵ�ճ�
        for (int i = 0; i < hwNum; i++) {
            for (int j = HwArr[i].ddl; j >= 1; j--) {
                if (!schedule[j]) {
                    schedule[j] = 1;
                    HwArr[i].isScheduled = 1;
                    break;
                }
            }
        }
        //ͳ����Ȼ�޷���ɵ���ҵ�������
        int ans = 0;
        for (int i = 0; i < hwNum; i++) {
            if (!HwArr[i].isScheduled) {
                ans += HwArr[i].score;
            }
        }
        printf("%d\n", ans);
    }
}