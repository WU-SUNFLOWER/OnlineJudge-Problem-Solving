#include <stdio.h>
#include <math.h>

void sortByAbs(int arr[], int length) {
    int temp;
    for (int i = 0; i < length - 1; i++) {
        int flag = 1;
        for (int j = i; j <= length - 2; j++) {
            if (abs(arr[j]) > abs(arr[j + 1])) {
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
                flag = 0;
            }
        }
        if (flag) {
            break;
        }
    }
}

int main() {
    int totalNum;
    int NegativeNumberArr[100];
    while (~scanf("%d", &totalNum)) {
        int temp;
        int flag = 0;  //���Ա��multip�Ƿ�������Чֵ
        int multip;
        int negativeNum = 0;
        //��ȡ���ݣ����������������
        for (int i = 0; i < totalNum; i++) {
            scanf("%d", &temp);
            if (temp > 0 && !flag) {
                flag = 1;
                multip = temp;
            }
            else if (temp > 0) {
                multip *= temp;
            }
            else if (temp < 0) {
                NegativeNumberArr[negativeNum++] = temp;
            }
        }
        //������
        //��һ�������ֻ��һ���������������������֮�������ֱ�ӷ�������
        //�ڶ��������ֻ��һ��������û��������˵Ľ����������Ϊ��
        //�������������ż������������ֱ�ӽ��𰸳������и���
        //�����������������������������ݾ���ֵ��С�����и����������򣬷�������ֵ��С�ĸ���
        if (negativeNum > 1) {
            if (!flag) {
                multip = 1;
                flag = 1;
            }
            if (negativeNum % 2 == 0) {
                while (negativeNum > 0) {
                    multip *= NegativeNumberArr[negativeNum - 1];
                    negativeNum--;
                }
            } else {
                sortByAbs(NegativeNumberArr, negativeNum);
                while (negativeNum > 1) {
                    multip *= NegativeNumberArr[negativeNum - 1];
                    negativeNum--;
                }
            }
        }
        else if (negativeNum == 1 && !flag) {
            flag = 1;
            multip = NegativeNumberArr[0];
        }
        //���
        printf("%d\n", flag ? multip : 0);
    }
}