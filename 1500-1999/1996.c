#include <stdio.h>
#include <math.h>

/*
��С�����������������m��n��m��6��n��5000��֮����������ԡ�
˵������a��bΪһ������������a�����Ӻ͵���b��b�����Ӻ͵���a����a������b�����磬220��284��һ����������
*/

/*
���룺
100  2000
�����
220 284
1184 1210
*/

int getSubSum(int num) {
	int sum = 1;
	for (int i = 2; i <= sqrt(num); i++) {
		if (num % i == 0) {
			if (i == num / i) {
				sum += i;
			} else {
				sum += i + num / i;
			}
		}
	}
	return sum;
}

int main() {
	int m;
	int n;
	scanf("%d %d", &m, &n);
	for (int x = m; x <= n; x++) {
		/*
		����ֱ����ֱ��ʹ�ñ���ö��Ѱ����x��Ϊ��������y����������Ĵ��룩
		��ȻҲ�ܳ���������ǳ�������س�ʱ
		for (int y = x + 1; y <= n; y++) {
			if (getSubSum(x) == y && getSubSum(y) == x) {
				printf("%d %d\n", x, y);
				break;
			}
		}
		*/
		/*
		�������ȷ������Ϊ�����������������Ѱ�ң�
		����getSubSum(x)=y��֪����x��y��Ϊ��������ǰ���£���x��y�ķ���
		����getSubSum(y)=x��֪�ж�x��y�Ƿ�Ϊ�������ķ���
		*/
		int y = getSubSum(x);
		if (x < y && getSubSum(y) == x) {
			printf("%d %d\n", x, y);
		}
	}
}