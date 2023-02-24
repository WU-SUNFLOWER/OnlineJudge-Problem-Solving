#include <stdio.h>

//��������ʱ��ת���ɿ�����
void translate(int originalTime[], int translatedTime[]) {
    for (int i = 0; i < 4; i++) {
        translatedTime[i] = originalTime[3 - i];
        //�����ֱ�ʱ����Ҫ������6��9����ת��
        if (translatedTime[i] == 6) {
            translatedTime[i] = 9;
        }
        else if (translatedTime[i] == 9) {
            translatedTime[i] = 6;
        }
    }
}

int isVariableTime(int time[]) {
    for (int i = 0; i < 4; i++) {
        if (
            time[i] != 0 && 
            time[i] != 1 && 
            time[i] != 2 && 
            time[i] != 5 && 
            time[i] != 6 && 
            time[i] != 8 && 
            time[i] != 9
        ) {
            return 0;
        }
    }
    return 1;
}

int isValidTime(int time[]) {
    return time[0] * 10 + time[1] <= 23 &&
           time[2] * 10 + time[3] <= 59;
}

int isSameTime(int originalTime[], int translatedTime[]) {
    int ans = 1;
    for (int i = 0; i < 4; i++) {
        if (originalTime[i] != translatedTime[i]) {
            ans = 0;
            break;
        }
    }
    return ans;
}

int main() {
    int count1 = 0;  //ͳ�Ʒ����߼���ʱ��
    int count2 = 0;  //ͳ��������ͬ��ʱ��
    int originalTime[4];
    int translatedTime[4];
    for (int i = 0; i <= 2; i++) {
        for (int j = 0; j <= 9; j++) {
            //���ܳ���24Сʱ��
            if (i == 2 && j > 3) {
                break;
            }
            for (int p = 0; p <= 5; p++) {
                for (int q = 0; q <= 9; q++) {
                    originalTime[0] = i;
                    originalTime[1] = j;
                    originalTime[2] = p;
                    originalTime[3] = q;
                    if (isVariableTime(originalTime)) {
                        translate(originalTime, translatedTime);
                        if (isValidTime(translatedTime)) {
                            count1++;
                            if (isSameTime(originalTime, translatedTime)) {
                                count2++;
                            }
                        }
                    }
                }
            }
        }
    }
    printf("%d,%d\n", count1, count2);
}