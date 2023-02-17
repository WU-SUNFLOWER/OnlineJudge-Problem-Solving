#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int x;
    int y;
} Vector;

Vector* createVector() {
    return (Vector*)malloc(sizeof(Vector));
}

int getCross(Vector* a, Vector* b) {
    return (a->x) * (b->y) - (a->y) * (b->x);
}

int main() {
    int PointNum;
    while (~scanf("%d", &PointNum) && PointNum != 0) {
        int flag = 1;
        int firstX, firstY;
        int lastX, lastY;
        int curX, curY;
        Vector* curV = createVector();
        Vector* lastV = createVector();
        for (int i = 1; i <= PointNum + 1; i++) {
            lastX = curX;
            lastY = curY;
            i <= PointNum && scanf("%d %d", &curX, &curY);
            //����������꣬�Ա�������һ����ָ����������
            if (i == 1) {
                firstX = curX;
                firstY = curY;
            }
            //��ȡ��2����֮����Կ�ʼ����������
            if (i >= 2) {
                //������һ�ε���������
                lastV->x = curV->x;
                lastV->y = curV->y;
                //������˳ʱ�뷽��ÿ�������������
                if (i <= PointNum) {
                    curV->x = curX - lastX;
                    curV->y = curY - lastY;                    
                } 
                //���Ҫ�������һ����ָ����������
                else {
                    curV->x =  firstX - lastX;
                    curV->y =  firstY - lastY;                    
                }
            }
            //��ȡ��3����֮���Ѿ��õ��������������Ϳ��Կ�ʼ��������
            if (i >= 3 && getCross(lastV, curV) < 0) {
                flag = 0;
                printf("concave\n");
                break;
            }
        }
        if (flag) {
            printf("convex\n");
        }
        free(curV);
        free(lastV);
    }
}