#include <stdio.h>

void swap(int* a, int* b) {
    int t = *a;
    *a = *b;
    *b = t;
}

int main() {
    int size;
    int ar[12][12];
    scanf("%d", &size);
    int value_min = 1 << 15;
    int i_min, j_min;
    int value_min2 = 1 << 16;
    int i_min2, j_min2;
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            scanf("%d", &ar[i][j]);
            // 先检查元素是不是比最小元素小
            // 再检查元素是不是比次小元素小（放宽要求）
            if (ar[i][j] < value_min) {
                // 别忘了把最小降级为次小
                value_min2 = value_min;
                i_min2 = i_min;
                j_min2 = j_min;
                // 更新最小
                value_min = ar[i][j];
                i_min = i;
                j_min = j;
            }
            else if (ar[i][j] < value_min2) {
                value_min2 = ar[i][j];
                i_min2 = i;
                j_min2 = j;
            }
        }
    }
    // 交换左上角元素和最小元素
    // 如果左上角元素恰好是次小元素的话，更新次小元素的位置
    swap(&ar[0][0], &ar[i_min][j_min]);
    if (i_min2 == 0 && j_min2 == 0) {
        i_min2 = i_min;
        j_min2 = j_min;
    }
    // 交换右下角元素和次小元素
    swap(&ar[size - 1][size - 1], &ar[i_min2][j_min2]);
    // 输出
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            printf(j == size - 1 ? "%d\n" : "%d ", ar[i][j]);
        }
    }
}