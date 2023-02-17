#include<stdio.h>
int main() {
	int range;
    int a[100][100];
    int sign_1_temp, sign_2_temp;
    int sign_1_ans, sign_2_ans;
    int hasAns = 0;
    int hasRepeatAns = 0;
	scanf("%d", &range);
	for(int i = 0; i < range; i++) {
		for(int j = 0; j < range; j++) {
			scanf("%d", &a[i][j]);
		}
	}
	for(sign_1_temp = 0; sign_1_temp < range && !hasRepeatAns; sign_1_temp++) {
        //鞍点在该行上必须是有效的绝对最大值
        //即该行上不能同时有多个相等的最大值同时存在
        //再校验每列的最小值时需进行类似处理
        int isVaildMax = 1;
        //寻找该行的最大值
        int max = a[sign_1_temp][0];
		for(int j = 1; j < range; j++) {
			if (a[sign_1_temp][j] > max) {
			    max = a[sign_1_temp][j];
                //记录最大值的列数
				sign_2_temp = j;
                //假定当前找到的位置为该行的绝对最大值
                isVaildMax = 1;
			}
            //如果发现先前找到的max有重复，不是绝对最大值
            //则将标记变量重新置为false
            else if (a[sign_1_temp][j] == max) {
                isVaildMax = 0;
            }
		}
        if (isVaildMax) {
            //假设a[sign_1_temp][sign_2_temp]为所要寻找的鞍点
            //再对其进行校验，检查其是否为该行上的绝对最小值
    		int min = a[sign_1_temp][sign_2_temp];
    		for(int j = 0; j < range; j++) {
                //首先遍历到自身时需要跳开校验
                //如果校验发现a[sign_1][sign_2]不是该行的绝对最小值
                //则直接放弃后续操作
    			if (a[j][sign_2_temp] <= min && j != sign_1_temp) {
    				break;
    			}
                //如果遍历到该行最后一个元素后发现，
                //a[sign_1_temp][sign_2_temp]的确是该行上的最小值，则分两种情况
                //1.先前没有发现过鞍点：则先记下该答案，再进一步校验是否有重复鞍点出现；
                //2. 先前已发现过鞍点，则说明答案有重复，直接退出循环并输出NO
                if (j == range - 1) {
                    if (hasAns) {
                        hasRepeatAns = 1;
                    } else {
                        hasAns = 1;
                        sign_1_ans = sign_1_temp;
                        sign_2_ans = sign_2_temp;
                    }
                }
    		}
        }
	}
	if (hasAns && !hasRepeatAns) {
		printf("%d %d", sign_1_ans, sign_2_ans);
	} else {
		printf("NO");
	}
	return 0;
}