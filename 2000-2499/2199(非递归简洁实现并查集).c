#include <stdio.h>

int vexSet[1000];

int main() {
    int num_node;
    int num_edge;
    while (~scanf("%d %d", &num_node, &num_edge)) {
        if (num_node == 0) break;
        for (int i = 1; i <= num_node; i++) {
            vexSet[i] = i;
        }
        for (int i = 0; i < num_edge; i++) {
           int from, to;
           scanf("%d %d", &from, &to);
           for (int j = 1; j <= num_node; j++) {
               if (vexSet[j] == vexSet[to]) vexSet[j] = vexSet[from];
           }
        }
        int cnt = 0;
        for (int i = 1; i <= num_node; i++) {
            if (vexSet[i] == i) cnt++;
        }
        printf("%d\n", cnt - 1);
    }
}