#include<stdio.h>

/*
�з��ķ������ڰѴ��Լ���վ��λ�ÿ�ʼһֱ�ۼӵ���ͷ��Ů���ķ������ڴ��Լ���վλ�ÿ�ʼһֱ�ۼӵ�ĩβ��
���ĳһ�����˵ĵ÷�������ͬ�ģ������Ǿͻ�ʤ��

���۵��ϵ��������ʲô���ӣ�Ů��վ�ڿ�ͷ���з�վ��ĩβ��һ�����Ի񽱡�
*/

int main() {
	int n;
    int a[20002];
    int sumArr1[20002] = {0};  //���ڼ�¼�з�վÿһ����Ի�õ��ܷ�
    int sumArr2[20002];  //���ڼ�¼Ů��վÿһ����Ի�õ��ܷ�
	while (scanf("%d", &n) != EOF && n != 0) {
        int count = 0;
        //��ȡ����
		for (int i = 1; i <= 2 * n; i++) {
			scanf("%d", &a[i]);
		}
        //���
        //�з���վ��λ��һֱ�ۼӵ���ͷ
        for (int i = 1; i <= 2 * n; i++) {
            sumArr1[i] = sumArr1[i - 1] + a[i];
        }
        //Ů����վ��λ��һֱ�ۼӵ�ĩβ
        for (int i = 1; i <= 2 * n; i++) {
            sumArr2[i] = sumArr1[2 * n] - sumArr1[2 * n - i];
        }
        int i = 1;
        int j = 1;
        while (i <= 2 * n && j <= 2 * n) {
            if (sumArr1[i] == sumArr2[j]) {  
    			count++;
                i++;
                j++;
            }
    		else if (sumArr1[i] < sumArr2[j]) { 
                i++;  
            } 
    		else {
    			j++;
    		}
        }
        printf("%d\n", count);
	}
	return 0;
}