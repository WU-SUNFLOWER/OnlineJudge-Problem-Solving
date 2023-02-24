#include <stdio.h>
#include <string.h>

/*
输入：
2
1 2
123456789 987654321

输出：
Case 1:
1 * 2 = 2

Case 2:
123456789 * 987654321 = 121932631112635269
*/

int convertCharToNum(char s) {
	return (int)(s - '0');
}

//假定两个数组空间都充足的情况下，交换两个数组中的各个元素
void exchangeTwoIntArray(int* arr1, int* arr2, int len) {
	for (int i = 0; i < len; i++) {
		int temp = arr1[i];
		arr1[i] = arr2[i];
		arr2[i] = temp;
	}
}

int main() {
	int TotalTestNum;
	int CurTestNum = 1;
	int Num1_Len;
	int Num2_Len;
	char NumStr1[101];
	char NumStr2[101];
	int BigNum1[100];  //默认储存长数字
	int BigNum2[100];  //默认储存短数字
	int BigNum_Ans[201];
	scanf("%d", &TotalTestNum);
	while(CurTestNum <= TotalTestNum) {
		scanf("%s", &NumStr1);
		scanf("%s", &NumStr2);
		Num1_Len = strlen(&NumStr1[0]);
		Num2_Len = strlen(&NumStr2[0]);
		/* 输出答案头部 */
		printf("Case %d:\n", CurTestNum);
		/* 程序核心部分开始 */
        //处理乘数为0的特殊情况
		if ((Num1_Len == 1 && NumStr1[0] == '0') || (Num2_Len == 1 && NumStr2[0] == '0')) {
			printf("%s * %s = 0", NumStr1, NumStr2);
		} else {
            for (int i = 0; i < Num1_Len; i++) {
                BigNum1[i] = convertCharToNum(NumStr1[i]);
            }
            for (int i = 0; i < Num2_Len; i++) {
                BigNum2[i] = convertCharToNum(NumStr2[i]);
            }
            if (Num1_Len < Num2_Len) {
                exchangeTwoIntArray(&BigNum1[0], &BigNum2[0], Num2_Len);
                int temp = Num1_Len;
                Num1_Len = Num2_Len;
                Num2_Len = temp;
            }
            int writePoint; 
            int str1Point;
            int str2Point = Num2_Len - 1;
            int carryBit = 0;
            //初始化答案数组
            for (int i = 0; i < 201; i++) {
                BigNum_Ans[i] = 0;
            }
            //模拟多位数乘法
            while (str2Point >= 0) {
                str1Point = Num1_Len - 1;
                writePoint = Num2_Len - str2Point - 1;
                while (str1Point >= 0) {
                    int CompleteAns = BigNum1[str1Point] * BigNum2[str2Point] + BigNum_Ans[writePoint] + carryBit;
                    BigNum_Ans[writePoint] = CompleteAns % 10;
                    carryBit = CompleteAns / 10;
                    writePoint++;
                    str1Point--;
                }
                if (carryBit != 0) {
                    BigNum_Ans[writePoint++] = carryBit;
                    carryBit = 0;
                }
                str2Point--;
            }
            //输出计算所得结果
            printf("%s * %s = ", NumStr1, NumStr2);
            for (int i = writePoint - 1; i >= 0; i--) {
                printf("%d", BigNum_Ans[i]);
            }
        }
        /* 程序核心部分结束 */
		/* 输出答案尾部换行符 */
		if (CurTestNum != TotalTestNum) {
			printf("\n\n");
		}
		CurTestNum++;
	}
}