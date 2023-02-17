#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct __Map__ {
    int size;
    char key[5];
    char valueArr[100][10];
} *Map;

Map createMap(char key[]) {
    Map p = (Map)malloc(sizeof(struct __Map__));
    p->size = 0;
    strcpy(p->key, key);
    return p;
}

Map addValue(Map map, char newValue[]) {
    strcpy(map->valueArr[map->size++], newValue);
    return map;
}

int min(int a, int b) {
    return a > b ? b : a;
}

int main() {
    char tempString1[50];
    char tempString2[50];
    //建立数组，以保存所有已建立的映射表
    int length = 0;
    Map MapArr[100];
    //录入映射关系
    while (~scanf("%s", tempString1)) {
        if (strcmp(tempString1, "end") == 0) {
            break;
        }
        int i;
        scanf("%s", tempString2);
        for (i = 0; i <= length; i++) {
            if (i == length) {
                length++;
                MapArr[i] = createMap(tempString1);
                break;
            } 
            else if (strcmp(tempString1, MapArr[i]->key) == 0) {
                break;
            }
        }
        addValue(MapArr[i], tempString2);
    }
    //查询数据
    while (~scanf("%s", tempString1)) {
        if (strcmp(tempString1, "end") == 0) {
            break;
        }
        int i;
        int idx;
        scanf("%d", &idx);
        for (i = 0; i < length; i++) {
            if (strcmp(tempString1, MapArr[i]->key) == 0) {
                break;
            }
        }
        if (i < length) {
            printf("%s\n", MapArr[i]->valueArr[min(idx, MapArr[i]->size) - 1]);
        } else {
            printf("NO\n");
        }
    }
}