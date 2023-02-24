#include <stdio.h>
#include <math.h>

/*
����һ��������m��1��m��6����m�׷���A�е�Ԫ�أ����A�������Ǿ����������YES�������������NO��
�������Ǿ������Խ������µ�Ԫ�ض�Ϊ0�ľ������Խ���Ϊ�Ӿ�������Ͻ������½ǵ����ߣ���
*/

/*
���룺
3
1 2 3
0 1 2
0 0 1
�����
YES
*/

/*
���룺
4
1 2 3 4
0 1 1 3
0 0 1 2
1 0 0 1
�����
NO
*/

int main() {
	int range;
	int flag = 1;
	scanf("%d", &range);
	for (int i = 1; i <= range * range; i++) {
		int ele;
		int col = (i - 1) % range + 1;
		int row = ceil(i / (double)range);
		scanf("%d", &ele);
		if (col < row && ele != 0) {
			flag = 0;
		}
	}
	printf(flag ? "YES\n" : "NO\n");
	return 0;
}