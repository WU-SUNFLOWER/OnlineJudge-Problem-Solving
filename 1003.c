#include <stdio.h>
#include <math.h>

int main() {
    //ÿ�����ݵ������ֻ��һ�У��ֱ��Ǹ��ӵ����������������� 
	//�������Ĳ������ݲ�����ý�����ǿ϶���redraiment������������ˣ������"Error"��ʾ����
	//��Щ���Ӻ�����һ����n��ͷ��mֻ��
	//1��n, m��230
	//n=35 m=94 => 23 12
	//1 3 => Error
	//0 0
	int headNum;
	int footNum;
	while (scanf("%d %d", &headNum, &footNum) != EOF) {
		if (headNum == 0 && footNum == 0) {
			break;
		}
		int x = 2 * headNum - footNum / 2;
		int y = footNum / 2 - headNum;
		if (footNum % 2 != 0 || x < 0 || y < 0) {
			printf("Error\n");
		} else {
			printf("%d %d\n", x, y);
		}
	}
	
	return 0;

}