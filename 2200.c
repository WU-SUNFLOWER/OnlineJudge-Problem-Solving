#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct {
    char name[100];
    int jin;
    int yin;
    int tong;
} Country;

Country* createCountry(char name[]) {
    Country* p = (Country*)malloc(sizeof(Country));
    strcpy(p->name, name);
    p->jin = 0;
    p->yin = 0;
    p->tong = 0;
    return p;
}

int main() {
    int t;
    int size = 0;
    char tempString[100];
    Country* cnty[500];
    scanf("%d", &t);
    while (t--) {
        int i;
        //查找国家，找不到就创建
        scanf("%s", tempString);
        for (i = 0; i < size; i++) {
            if (strcmp(cnty[i]->name, tempString) == 0) {
                break;
            }
        }
        if (i == size) {
            cnty[size++] = createCountry(tempString);
        }
        //登记奖牌信息
        scanf("%s", tempString);
        switch (tempString[0]) {
            case 'j':
                cnty[i]->jin++;
                break;
            case 'y':
                cnty[i]->yin++;
                break;
            case 't':
                cnty[i]->tong++;
                break;
        }
    }
    //排序
    for (int i = 0; i < size - 1; i++) {
        for (int j = 0; j <= size - 2 - i; j++) {
            if (
                cnty[j]->jin < cnty[j + 1]->jin ||
                cnty[j]->jin == cnty[j + 1]->jin && cnty[j]->yin < cnty[j + 1]->yin ||
                cnty[j]->jin == cnty[j + 1]->jin && cnty[j]->yin == cnty[j + 1]->yin && cnty[j]->tong < cnty[j + 1]->tong
            ) {
                Country* temp = cnty[j];
                cnty[j] = cnty[j + 1];
                cnty[j + 1] = temp;
            }
        }
    }
    //输出
    for (int i = 0; i < size; i++) {
        printf("%s %d %d %d\n", cnty[i]->name, cnty[i]->jin, cnty[i]->yin, cnty[i]->tong);
    }
}