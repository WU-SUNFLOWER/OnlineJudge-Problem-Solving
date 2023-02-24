#include <stdio.h>

struct Bar {
    int length;
    int diameter;
    int id;
};

int main() {
    int t;
    struct Bar BarArr[1000];
    scanf("%d", &t);
    while (t--) {
        int total;  //棍子总数
        scanf("%d", &total);
        //读取棍子信息
        for (int i = 0; i < total; i++) {
            scanf("%d %d %d", &BarArr[i].length, &BarArr[i].diameter, &BarArr[i].id);
        }
        //查找答案
        struct Bar ans = BarArr[0];
        for (int i = 1; i < total; i++) {
            struct Bar cur = BarArr[i];
            if (
                cur.length > ans.length ||
                cur.length == ans.length && cur.diameter < ans.diameter ||
                cur.length == ans.length && cur.diameter == ans.diameter && cur.id > ans.id
            ) {
                ans = cur;
            }
        }
        //输出答案
        printf("%d\n", ans.id);
    }
}