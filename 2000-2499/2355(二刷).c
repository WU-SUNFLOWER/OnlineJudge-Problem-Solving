#include <stdio.h>
#define N 100

typedef struct {
    int i;
    int j;
    int value;
} Element;

typedef struct {
    int size;
    Element data[N];
} Matrix;

int getValue(Matrix m, int i, int j) {
    int k;
    for (k = 0; k < m.size; k++) {
        if (m.data[k].i == i && m.data[k].j == j) {
            break;
        }
    }
    return k == m.size ? 0 : m.data[k].value;
}

void setValue(Matrix* m, int i, int j, int value) {
    int k;
    int size = m->size;
    if (value == 0) {
        return;
    }
    for (k = 0; k < size; k++) {
        if (m->data[k].i == i && m->data[k].j == j) {
            m->data[k].value = value;
            break;
        }
    }
    if (k == size) {
        m->data[size].i = i;
        m->data[size].j = j;
        m->data[size].value = value;
        m->size++;
    }
}

int main() {
    int width = 1000;
    Matrix m1, m2, m3;
    m1.size = m2.size = m3.size = 0;
    // 读取m1矩阵
    int i, j, value;
    while (~scanf("%d,%d,%d", &i, &j, &value) && i >= 0) {
        setValue(&m1, i, j, value);
    }
    // 读取m2矩阵
    while (~scanf("%d,%d,%d", &i, &j, &value) && i >= 0) {
        setValue(&m2, i, j, value);
    }
    
    // 作矩阵乘法
    // 参考：https://blog.csdn.net/zhangxiaoduoduo/article/details/81807338
    for (int a = 0; a < width; a++) {
        for (int k = 0; k < width; k++) {
            int ak = getValue(m1, a, k);
            if (ak == 0) continue;
            for (int b = 0; b < width; b++) {
                int kb = getValue(m2, k, b);
                if (kb == 0) continue;
                setValue(&m3, a, b, getValue(m3, a, b) + ak * kb);
            }
        }
    }
    
    // 输出m3
    if (m3.size > 0) {
        for (int k = 0; k < m3.size; k++) {
            printf("%d,%d,%d\n", m3.data[k].i, m3.data[k].j, m3.data[k].value);
        }        
    } else {
        puts("No non-zero number exists!");
    }

}