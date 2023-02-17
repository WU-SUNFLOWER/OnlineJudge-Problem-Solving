#include <stdio.h>

double covertToByte(double capacity, char unit[], int isNormalized) {
    //首先确定转换次数
    int time = 0;
    switch (unit[0]) {
        case 'T':
            time = 4;
            break;
        case 'G':
            time = 3;
            break;        
        case 'M':
            time = 2;
            break;
        case 'K':
            time = 1;
            break;
    }
    //进行转换
    while (time-- > 0) {
        capacity *= isNormalized ? 1024 : 1000;
    }
    return capacity;
}

int main() {
    double capacity;
    char unit[3];
    while (~scanf("%lf%s", &capacity, unit)) {
        if (capacity == 0) {
            break;
        }
        printf("%.0lf\n", covertToByte(capacity, unit, 1) - covertToByte(capacity, unit, 0));
    }
}