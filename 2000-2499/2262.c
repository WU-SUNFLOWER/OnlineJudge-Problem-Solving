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
            //保存起点坐标，以便计算最后一个点指向起点的向量
            if (i == 1) {
                firstX = curX;
                firstY = curY;
            }
            //获取完2个点之后可以开始创建向量了
            if (i >= 2) {
                //保存上一次的向量坐标
                lastV->x = curV->x;
                lastV->y = curV->y;
                //起先沿顺时针方向每两个点计算向量
                if (i <= PointNum) {
                    curV->x = curX - lastX;
                    curV->y = curY - lastY;                    
                } 
                //最后还要计算最后一个点指向起点的向量
                else {
                    curV->x =  firstX - lastX;
                    curV->y =  firstY - lastY;                    
                }
            }
            //获取完3个点之后，已经得到了两个向量，就可以开始计算叉积了
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