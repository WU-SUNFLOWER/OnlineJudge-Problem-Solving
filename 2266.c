#include<stdio.h>
#include<stdlib.h>

void sort(int* s[], int len) {
	int i, j;
	for (i = 0; i < len; i++) {
		for (j = i; j < len; j++) {
            //s[i]����sָ�������е�i��Ԫ�ر����һ��ָ�룬�ٴν����þ������յ����ݿռ�
			if (*(s[i]) > *(s[j])) {
				int tmp = *(s[i]); //ָ��ĺô�����ֱ��ͨ����ֵ���Ըı�ָ��
				*(s[i]) = *(s[j]);  //ֻҪ�������ַ����ĵ�ַ��ʵ�����ַ����Ľ���
				*(s[j]) = tmp;//���ͨ��ָ��ָ��Ľ������ܹ�ʵ���������ַ���������
			}
		}
	}
}

int main() {
	int count;
    while (~scanf("%d", &count)) {
        //����int�������ڴ����������
    	int* integers = (int*)malloc(count * sizeof(int));
    	//����int*�������ڴ��������ÿ��Ԫ�ص�ָ��
        int** p = (int**)malloc(count * sizeof(int*));
    	for (int i = 0; i < count; i++) {
    		p[i] = integers + i; //��������ÿ��intԪ�ؿռ���׵�ַ��ֵ��ָ�������еĸ���Ԫ��
    		scanf("%d", p[i]);//p[i]�ͱ���ʱ��i�����ݵĵ�ַ��������ﲻ��ȡ��ַ
    	}
    	sort(p, count);
    	for (int i = 0; i < count; i++) {
    		printf(i == count - 1 ? "%d\n" : "%d ", integers[i]);
    	}
    	free(integers);
    	free(p);        
    }
	return 0;
}