#include <stdio.h>
#include <stdlib.h>

int main() {
	int width;
    int height;
    int matrix[100][100];
    int rowMinArr[100];
    int colMaxArr[100];
    int count = 0;  //ͳ�ƿ��ܵİ�������
	scanf("%d %d", &width, &height);
    //��һ�����������ݣ�ͬʱȷ��ÿ�е���Сֵ
	for(int i = 0; i < height; i++) {
        int min;
		for(int j = 0; j < width; j++) {
			scanf("%d", &matrix[i][j]);
            if (j == 0) {
                min = matrix[i][j];
            } else {
                matrix[i][j] < min && (min = matrix[i][j]);
            }
		}
        rowMinArr[i] = min;
	}
    //�ڶ�����ȷ��ÿ�е����ֵ
    for (int j = 0; j < width; j++) {
        int max = matrix[0][j];
        for (int i = 1; i < height; i++) {
            matrix[i][j] > max && (max = matrix[i][j]);
        }
        colMaxArr[j] = max;
    }
    //����������ʼѰ�Ұ���
	for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            if (matrix[i][j] == rowMinArr[i] && matrix[i][j] == colMaxArr[j]) {
                printf("%d %d\n", i + 1, j + 1);
            }
        }
    }
	return 0;
}