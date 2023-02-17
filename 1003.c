#include <stdio.h>
#include <math.h>

int main() {
    //每组数据的输出都只有一行，分别是鸽子的数量和兔子数量。 
	//如果输入的测试数据不能求得结果，那肯定是redraiment这个马大哈数错了，就输出"Error"提示他。
	//这些鸽子和兔子一共有n个头和m只脚
	//1≤n, m≤230
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