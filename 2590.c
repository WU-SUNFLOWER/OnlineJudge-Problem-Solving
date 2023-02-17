#include <stdio.h>
/*
明明是一个水鬼，非常爱喝矿泉水，一瓶矿泉水m元钱，三个空瓶子可以兑换一瓶矿泉水，
七个瓶盖也可以兑换一瓶矿泉水，现在有n元钱，求最多可以喝到多少瓶矿泉水？

输入
输入包括多组测试数据。
每组测试数据包括一行：正整数m，表示矿泉水的价格；非负整数n，表示初始钱数。

输出
最多可以喝到的矿泉水瓶数。
*/

/*
输入样例 1 
3 2
3 3
3 10

输出样例 1
0
1
4
*/

int main()
{
	int money,cap,price,water,bottle;
	cap=0; bottle=0; water=0;
	while (scanf("%d%d",&price,&money) != EOF )
	{ 
		while (cap >= 7 || bottle >= 3 ||  money >= price)
		{
			if ( cap >= 7)
			{
				cap -= 7;
			}
			else if( bottle >= 3)
			{
				bottle -= 3;
			}
			else if ( money >= price)
			{
				money -= price;
			}
			bottle++; cap++; water++;
		}
    	printf("%d\n",water);
	}
	return 0;
}
