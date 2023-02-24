#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct {
    char* name;
    char* sex;
    char* date;
} User;

int UserNum = 0;
User* UserArr[100];

char* createCharArray(int length) {
    return (char*)malloc(sizeof(char) * length);
}

void add(char name[], char sex[], char date[]) {
    //处理日期格式
    for (int i = 0; date[i]; i++) {
        if (date[i] == ' ') {
            date[i] = '-';
        }
    }
    //复制字符串
    char* _name = createCharArray(20);
    char* _sex = createCharArray(20);
    char* _date = createCharArray(20);
    strcpy(_name, name);
    strcpy(_sex, sex);
    strcpy(_date, date);
    //创建结构体
    UserArr[UserNum] = (User*)malloc(sizeof(User));
    UserArr[UserNum]->name = _name;
    UserArr[UserNum]->sex = _sex;
    UserArr[UserNum]->date = _date;
    UserNum++;
}

void printUserInfo(User* user) {
    printf("%s %s %s\n", user->name, user->sex, user->date);
}

void queryByName(char name[]) {
    for (int i = 0; i < UserNum; i++) {
        if (strcmp(UserArr[i]->name, name) == 0) {
            printUserInfo(UserArr[i]);
        }
    }
}

void queryBySex(char sex[]) {
    for (int i = 0; i < UserNum; i++) {
        if (strcmp(UserArr[i]->sex, sex) == 0) {
            printUserInfo(UserArr[i]);
        }
    }
}

int main() {
    char command[5];
    char tempName[20];
    char tempSex[20];
    char tempDate[20];
    while (~scanf("%s", command)) {
        if (strcmp(command, "add") == 0) {
            scanf("%s %s", tempName, tempSex);
            getchar();
            gets(tempDate);
            add(tempName, tempSex, tempDate);
        }
        else if (strcmp(command, "name") == 0) {
            scanf("%s", tempName);
            queryByName(tempName);
        }
        else if (strcmp(command, "sex") == 0) {
            scanf("%s", tempSex);
            queryBySex(tempSex);
        }
        else {
            break;
        }
    }
}