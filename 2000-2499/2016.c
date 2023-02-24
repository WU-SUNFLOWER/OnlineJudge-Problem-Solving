#include <stdio.h>
#include <math.h>

/*
��6��������ȵ�������a��b��c��d��e��f�ֳ����飬������������������������������:  
a+b+c=d+e+f=s��a^2+b^2+c^2=d^2+e^2+f^2=s2�����ǰ���������(a,b,c)��(d,e,f)��Ϊ����3Ԫ���顣

��Ƴ����������s����������3Ԫ���飨Լ��a<b<c, d<e<f, a<d����
���磬(1,5,6)��(2,3,7)����s=12������3Ԫ���飺1+5+6=2+3+7=12��1^2+5^2+6^2=2^2+3^2+7^2=62��
*/

/*
���룺
18
�����
(1,7,10):(2,5,11)
(1,8,9):(3,4,11)
(2,7,9):(3,5,10)
(3,7,8):(4,5,9)
*/

struct magicalArray {
	int arr[3];
	int sqrtSum;
};

int main() {
	int num;
	int idx = -1;
	struct magicalArray Data[100];
	scanf("%d", &num);
	for (int x = 1; x < num; x++) {
		for (int y = x + 1; y < num; y++) {
			for (int z = y + 1; z < num; z++) {
				if (x + y + z == num) {
					struct magicalArray tempArray = {
						{x, y, z},
						pow(x, 2) + pow(y, 2) + pow(z, 2)
					};
					Data[++idx] = tempArray;
				}
			}
		}
	}
	for (int i = 0; i < idx; i++) {
		for (int j = i + 1; j <= idx; j++) {
			if (Data[i].sqrtSum == Data[j].sqrtSum) {
				printf("(%d,%d,%d):(%d,%d,%d)\n", Data[i].arr[0], Data[i].arr[1], Data[i].arr[2], Data[j].arr[0], Data[j].arr[1], Data[j].arr[2]);
				break;
			}
		}
	}
}