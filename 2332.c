#include <stdio.h>
#include <string.h>

/*
С������ʦÿ���Ͽ�ǰ��Ҫ�����������������˷�����ʦ���Ͽ�ʱ�䡣
������ʦ��С������ɵ�������С��������ϰ��ʱ��͵��������ʦ����С��������С��ֻҪ�������������ͺ����ǲ��Ǻܼ򵥰���

����:
�����ж������ݣ�ֱ���ļ�������
ÿ��������������У���һ��Ϊ��������m, n��50 >= m >= n����
�ڶ�����m�����֣�����֮���ÿո��������С������ͬѧ��������
������n�����������Ͽε�ͬѧ�����ּ��ÿո���������ֵĳ��Ȳ�����20���ַ���

���:
���յ�һ�е�������ÿ���˶�Ӧ����Ƿ��ˡ����������Yes��û���������No��
*/

/*
���룺
3 2
ͬѧ������Bob Marry Jam
���Ͽε�ͬѧBob Jam
2 2
Limeme Lintianzhi
Limeme Lintianzhi

�����
Yes
No
Yes

Yes
Yes
*/

int main() {
	int totalPeopleNum;
	int realPeopleNum;
	char totalPeopleArr[50][21];
	char realPeopleArr[50][21];
	while (scanf("%d %d", &totalPeopleNum, &realPeopleNum) != EOF) {
		for (int i = 0; i < totalPeopleNum; i++) {
			scanf("%s", &totalPeopleArr[i][0]);
		}
		for (int i = 0; i < realPeopleNum; i++) {
			scanf("%s", &realPeopleArr[i][0]);
		}
        
		for (int i = 0; i < totalPeopleNum; i++) {
			int flag = 1;
			for (int j = 0; j < realPeopleNum; j++) {
				if (strcmp(&totalPeopleArr[i][0], &realPeopleArr[j][0]) == 0) {
					flag = 0;
					printf("Yes\n");
					break;
				}
			}
			flag && printf("No\n");
		}
	}
	return 0;
}