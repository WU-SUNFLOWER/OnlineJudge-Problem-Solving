#include <stdio.h>
#include <math.h>

double min(double a, double b) {
    return a > b ? b : a;
}

/*
�ؼ��㣺
1.ţ��ֻ���Ǵ�������0��ϲȵ����Ϊ����>0��ϲȵҪô�ٶ�ƫС��û��Ҫ���ˣ�Ҫô�ٶ�ƫ��׷��׷���ϡ�
2.û�б�Ҫ����ţ���ȳ����򷴷����˶���ϲȵ���Ի����ٶȸ�����������˶���ϲȵ��
ʵ�����������κ�ţ�ɳ����˶�������ϲȵ���ȴ��ٶȸ����ϲȵ׷�ϣ����ĵ�ʱ������ȫ��ȵġ�
3.ʵ����ţ��û�б�Ҫ���ǻ���ϲȵ��
��Ȼţ�ɿ�������ѡ����ϲȵ��ʱ������ֻҪ�ȵ������0��ϲȵ�еִ�Ŀ�ĵ�ʱ����̵�ϲȵ�ִ�����ԭ�㣬ֱ�Ӵ���һ·�����׼��ɣ�
*/

int main() {
    int width;
    int num;
    while (~scanf("%d %d", &width, &num)) {
        if (width == 0 && num == 0) {
            break;
        }
        width *= 1000;
        double pos;
        double speed;
        double ans = pow(2, 31) - 1;
        for (; num > 0; num--) {
            scanf("%lf %lf", &pos, &speed);
            if (pos <= 0 && speed > 0) {
                ans = min(ans, (width - pos) / speed);
            }
        }
        if (ans == pow(2, 31) - 1) {
            printf("Can't Solve\n");
        } else {
            printf("%d\n", (int)ans);
        }
    }
}