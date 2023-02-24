#include <stdio.h>

void swap(int* a, int* b) {
    int t = *a;
    *a = *b;
    *b = t;
}

// ������ָ����Χ���л��֣������ػ��ֱ߽���±�
// ����������±귶ΧΪ[start, end)
int partition(int ar[], int start, int end) {
    int tail = end - 1;
    int pivot = ar[tail];
    int i = start;
    int j = tail - 1;
    while (1) {
        while (ar[i] < pivot && i < j) {
            i++;
        }
        while (ar[j] > pivot && i < j) {
            j--;
        }
        if (i < j) {
            swap(&ar[i], &ar[j]);
        } else {
            break;
        }
    }
    swap(&ar[i], &ar[tail]);
    return i;
}

int main() {
    int k;
    int len;
    int ar[100];
    scanf("%d %d", &len, &k);
    for (int i = 0; i < len; i++) {
        scanf("%d", &ar[i]);
    }
    int index = partition(ar, 0, len);
    while (1) {
        // ��һ�������������ֱ߽���������k������������
        if (index + 1 == k) {
            break;
        }
        // �ڶ��������������ֱ߽�����k��࣬˵����������
        else if (index + 1 < k) {
            index = partition(ar, index + 1, len);
        }
        // �ڶ��������������ֱ߽�����k�Ҳ࣬˵�����ֶ���
        else if (index + 1 > k) {
            index = partition(ar, 0, index);
        }
    }
    for (int i = 0; i < k; i++) {
        printf(i == k - 1 ? "%d\n" : "%d ", ar[i]);
    }
}