#include <stdio.h>
#include <string.h>

char tempNum1[10000];
char tempNum2[10000];
    
int num1[10000];
int num2[10000];
int ans[10000];    
    
int main() {
    int n;
    while (~scanf("%d", &n)) {
        while (n > 0) {
            scanf("%s %s", tempNum1, tempNum2);
    		int num1_len = strlen(tempNum1);
    		int num2_len = strlen(tempNum2);
    		//��ʼ������
    		for (int i = 0; i < 10000; i++) {
    			//������Ҳ���ܲ������㣬�ʲ���-1��ǿ�λ
    			num1[i] = num2[i] = -1;
    		}
    		//ת�����鲢���ַ�ת��������
    		for (int i = num1_len - 1; i >= 0; i--) {
    			num1[num1_len - i - 1] = tempNum1[i] - '0';
    		}
    		for (int i = num2_len - 1; i >= 0; i--) {
    			num2[num2_len - i - 1] = tempNum2[i] - '0';
    		}
    		//ģ��ӷ�
    		int idx = 0;
    		int carryNum = 0;
    		while (num1[idx] != -1 || num2[idx] != -1 || carryNum != 0) {
    			//��ֵΪ-1�Ŀ�λ�޸�Ϊ0������ȷ��������
    			num1[idx] == -1 && (num1[idx] = 0);
    			num2[idx] == -1 && (num2[idx] = 0);
    			int sum = num1[idx] + num2[idx] + carryNum;
    			ans[idx] = sum % 10;
    			carryNum = sum / 10;
    			idx++;
    		}
    		for (int i = idx - 1; i >= 0; i--) {
    			printf("%d", ans[i]);
    		}
    		printf("\n");
            n--;
        }        
    }
}