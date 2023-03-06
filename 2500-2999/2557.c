#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int weight[200];
int _index[200];
int scores[200];
char names[200][20];

int cmp(const void* p1, const void* p2) {
    int num1 = *(int*)p1;
    int num2 = *(int*)p2;
    int delta = scores[num2] - scores[num1];
    if (delta == 0) {
        return strcmp(names[num1], names[num2]);
    } else {
        return delta;
    }
}

int main() {
    int tot_people;
    int tot_subject;
    scanf("%d %d", &tot_people, &tot_subject);
    for (int i = 0; i < tot_subject; i++) {
        scanf("%d", &weight[i]);
    }
    for (int i = 0; i < tot_people; i++) {
        int temp;
        _index[i] = i;
        scanf("%s", names[i]);
        for (int j = 0; j < tot_subject; j++) {
            scanf("%d", &temp);
            scores[i] += temp * weight[j];
        }
    }
    qsort(_index, tot_people, sizeof(int), cmp);
    for (int i = 0; i < tot_people; i++) {
        puts(names[_index[i]]);
    }
}