#include <stdio.h>

//��֪С�а���33��ͬѧ��ѧ����4,6,8,10,12,13,16,18,19,21,32ΪŮ��
int isGirl(int id) { 
    return id == 4 || id == 6 || id == 8 || id == 10 ||
           id == 12 || id == 13 || id == 16 || id == 18 ||
           id == 19 || id == 21 || id == 32;
}

int main() {
    int startId;
    int ansCount = 0;
    scanf("%d", &startId);
    //��1~100ѡȡ�������ģ��
    for (int i = 1; i <= 100 && ansCount < 10; i++) {
        int start = 0;
        int end = 100;
        int curId = startId;
        //�ӵ�curId���˿�ʼ������˽��в���
        while (ansCount < 10) {
            //��ת����һ����
            curId = curId % 33 + 1;
            //��������Ů���Ĳ�ͬ������в���
            if (isGirl(curId) || end - start < 3) {
                start += 1;
            } else {
                int newBorder = (end - start) / 3 + start;
                newBorder > i ? (end = newBorder) : (start = newBorder);
            }
            //����µ���������Ϸ����
            if (start == i) {
                isGirl(curId) && (ansCount++, printf("%-2d %d\n", i, curId));
                break;
            }
        }
    }
    return 0;
}