#include <stdio.h>

//�����鲻���ں������ڲ����壬��Ҫ������ȫ�ֻ�����
//��Ϊ����������������ڴ�ռ��С��ȫ�ֻ������þ�̬������������������ڴ�ռ��
int f[1000000] = {0, 1};

int main() {
	int n;
    int k = 3;
    for (int i = 2; i < 1000000; i++) {
    	f[i] = (f[i - 1] + k - 1) % i + 1;
	}
    while (~scanf("%d", &n) && n != 0) {
        printf("%d\n", f[n]);
    }
    return 0;
}