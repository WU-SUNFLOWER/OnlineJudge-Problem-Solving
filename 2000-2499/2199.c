#include <stdio.h>
#include <string.h>

/*
参考资料：https://blog.csdn.net/hdq1745/article/details/126812623
*/

int record[1001];

int find(int curCity) {
    int rootCity = record[curCity];
    if (rootCity == curCity) {
        return curCity;
    } else {
        return (record[curCity] = find(rootCity));
    }
}

int main() {
    int num_city = 0;
    int num_path = 0;
    while (~scanf("%d %d", &num_city, &num_path) && num_city > 0) {
        // 读取道路信息，初始化record数组
        int from, to;
        // 起初还没连通道路的时候，每个城市节点都隶属于一个仅含自己的独立集合
        for (int i = 1; i <= num_city; i++) {
            record[i] = i;
        }
        for (int i = 0; i < num_path; i++) {
            scanf("%d %d", &from, &to);
            from = find(from);
            to = find(to);
            // 将to城市隶属的集合的"根城市"指向from城市隶属的集合的"根城市"
            // 此处亦可写作record[from] = to;
            record[to] = from;
        }
        // 统计record数组中"根城市"的个数
        int ans = 0;
        for (int i = 1; i <= num_city; i++) {
            if (record[i] == i) ans++;
        }
        printf("%d\n", ans - 1);
    }
}