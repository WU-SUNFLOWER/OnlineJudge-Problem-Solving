#include <stdio.h>
#include <math.h>

int isPrimeNumber(int num) {
    int ans = 1;
	if (num == 1) {
		ans = 0;
	} else {
    	for (int i = 2; i <= sqrt(num); i++) {
    		if (num % i == 0) {
                ans = 0;
    		    break;
    		}
        }
    }
    return ans;
}

int main() {
    //�������
    int primeNumberArr[101];
    int primeNumberCount = 0;
    for (int i = 1; i <= 100; i++) {
        if (isPrimeNumber(i)) {
            primeNumberArr[primeNumberCount++] = i;
        }
    }
    int num;
    while (~scanf("%d", &num)) {
        //���ԶԽ׳�չ��ʽ�е�ÿһ����������ӵķֽ�
        int maxPrimeIdx = 0;
        int bucket[101] = {0}; //ͳ����ʽ�ֽ�����
        for (int i = 2; i <= num; i++) {
            int term = i;
            //�˴��󵨽��зֽ⼴��
            //��Ϊ�κ�һ����Ȼ�������Էֽ�Ϊ�����ĳ˻�
            int j = 0;
            while (term > 1) {
                if (term % primeNumberArr[j] == 0) {
                    term /= primeNumberArr[j];
                    bucket[j] += 1;
                    j > maxPrimeIdx && (maxPrimeIdx = j);
                } else {
                    j++;
                }
            }
        }
        //���
        printf("%d!= ", num);
        for (int i = 0; i <= maxPrimeIdx; i++) {
            printf(i == maxPrimeIdx ? "%d" : "%d ", bucket[i]);
        }
        printf("\n");
    }
}