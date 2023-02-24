#include <stdio.h>

//Redraiment的老家住在工业区，日耗电量非常大。是政府的眼中钉肉中刺，但又没办法，这里头住的可都是纳税大户呀。 
//今年7月，又传来了不幸的消息，政府要在7、8月对该区进行拉闸限电。但迫于压力，限电制度规则不会太抠门，政府决定从7月1日停电，
//然后隔一天到7月3日再停电，再隔两天到7月6日停电，一次下去，每次都比上一次晚一天。 
//Redraiment可是软件专业的学生，怎么离得开计算机。如果停电，就“英雄无用武之地”了。呵呵。 
//所以他开始盘算起自己回家的日子了，他想知道自己到家后到底要经历多少天倒霉的停电。你能帮他算一算吗？

//输入包括多组数据。 每组数据包括一行:redraiment到家的日期。 输入以0/0结束。

int main() {
	int month;
	int day;
	while(scanf("%d/%d", &month, &day) != EOF) {
		if (month == 0 && day == 0) {
			break;
		}
		int arriveDay = (month - 7) * 31 + day;
		int curDay = 1;
		int step = 2;
		int ans = 0;
		//模拟从7月1日开始停电
		while (curDay <= 62) {
			if (arriveDay <= curDay) {
				ans++;
			}
			curDay += step;
			step += 1;
		}
		printf("%d\n", ans);
	}
}