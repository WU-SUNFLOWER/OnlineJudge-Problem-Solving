#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/*

//创建比赛
CREATE CONTEST 比赛编号 NAMED 比赛名称

//创建题目
CREATE PROBLEM 题号 NAMED 题目名称

//添加题目到比赛
INSERT PROBLEM 题号 INTO CONTEST 比赛编号

//从比赛中移除题目
DELETE PROBLEM 题号 FROM CONTEST 比赛编号

//删除比赛
DROP CONTEST 比赛编号

//删除题目
DROP PROBLEM 题号

//对账号授予管理员权限
GRANT ADMIN TO USER 账号名称


//查询题目，显示题目名称
//若当前题目被安排进比赛，提示NO PRIVILEGE
//若查询不到，提示NO RESULT
用户名称
SELECT PROBLEM 题号

//查询比赛，显示比赛名后按添加顺序显示所有题目号（不需要空格间隔）
//若为普通账号，则在比赛中的题目不可被查询，不可显示比赛题，只显示比赛名
//若查询不到，提示NO RESULT
用户名称
SELECT CONTEST 题号

*/

typedef struct {
    int id;
    char name[50];
    int problemNum;
    int problemIdArr[10000];
} Contest;

typedef struct {
    int id;
    int referCount;  //记录当前题目被引用的次数
    char name[50];
} Problem;

Contest* ContestMap[10000] = {NULL};
Problem* ProblemMap[10000] = {NULL};

Contest* createContest(int id, char name[]) {
    Contest* p = (Contest*)malloc(sizeof(Contest));
    p->id = id;
    p->problemNum = 0;
    strcpy(p->name, name);
    ContestMap[id] = p;
    return p;
}

Problem* createProblem(int id, char name[]) {
    Problem* p = (Problem*)malloc(sizeof(Problem));
    p->id = id;
    p->referCount = 0;
    strcpy(p->name, name);
    ProblemMap[id] = p;
    return p;
}

int main() {
    int cmdNum1;
    int cmdNum2;
    char tempString[60];
    char tempString2[60];
    char RootUserArr[60][100];
    while (~scanf("%d", &cmdNum1)) {
        //初始化
        int rootUserNum = 0;
        for (int i = 0; i < 10000; i++) {
            if (ContestMap[i] != NULL) {
                free(ContestMap[i]);
                ContestMap[i] = NULL;
            }
            if (ProblemMap[i] != NULL) {
                free(ProblemMap[i]);
                ProblemMap[i] = NULL;
            }
        }
        //处理第一部分命令
        for (int i = 0; i < cmdNum1; i++) {
            scanf("%s %s", tempString, tempString2);
            strcat(tempString, tempString2);
            //创建比赛
            if (strcmp("CREATECONTEST", tempString) == 0) {
                int id;
                scanf("%d NAMED %s", &id, tempString);
                createContest(id, tempString);
            }
            //创建题目
            else if (strcmp("CREATEPROBLEM", tempString) == 0) {
                int id;
                scanf("%d NAMED %s", &id, tempString);
                createProblem(id, tempString);
            }
            //添加题目到比赛
            else if (strcmp("INSERTPROBLEM", tempString) == 0) {
                int problemId;
                int contestId;
                Contest* contest;
                scanf("%d INTO CONTEST %d", &problemId, &contestId);
                contest = ContestMap[contestId];
                contest->problemIdArr[contest->problemNum++] = problemId;
                ProblemMap[problemId]->referCount += 1;
            }
            //从比赛中移除题目
            else if (strcmp("DELETEPROBLEM", tempString) == 0) {
                int problemId;
                int contestId;
                Contest* contest;
                scanf("%d FROM CONTEST %d", &problemId, &contestId);
                contest = ContestMap[contestId];
                for (int j = 0; j < contest->problemNum; j++) {
                    if (contest->problemIdArr[j] == problemId) {
                        contest->problemIdArr[j] = -1;
                        ProblemMap[problemId]->referCount -= 1;
                        break;
                    }
                }
            }
            //删除比赛
            else if (strcmp("DROPCONTEST", tempString) == 0) {
                int contestId;
                Contest* contest;
                scanf("%d", &contestId);
                contest = ContestMap[contestId];
                //别忘了与所有添加的比赛解除绑定
                for (int j = 0; j < contest->problemNum; j++) {
                    int problemId = contest->problemIdArr[j];
                    if (problemId != -1 && ProblemMap[problemId] != NULL) {
                        ProblemMap[problemId]->referCount -= 1;
                    }
                }
                free(contest);
                ContestMap[contestId] = NULL;
            }
            //删除题目
            else if (strcmp("DROPPROBLEM", tempString) == 0) {
                int problemId;
                scanf("%d", &problemId);
                free(ProblemMap[problemId]);
                ProblemMap[problemId] = NULL;
            }
            //设置管理员
            else if (strcmp("GRANTADMIN", tempString) == 0) {
                scanf("%s", tempString);
                scanf("%s", tempString);
                scanf("%s", tempString);
                strcpy(RootUserArr[rootUserNum++], tempString);
            }
        }
        //处理第二部分命令
        scanf("%d", &cmdNum2);
        for (int i = 0; i < cmdNum2; i++) {
            int isRootUser = 0;
            //首先校验执行操作的是不是root用户
            scanf("%s", tempString);
            for (int j = 0; j < rootUserNum; j++) {
                if (strcmp(tempString, RootUserArr[j]) == 0) {
                    isRootUser = 1;
                    break;
                }
            }
            scanf("%s %s", tempString, tempString2);
            strcat(tempString, tempString2);
            //查询题目，显示题目名称
            if (strcmp("SELECTPROBLEM", tempString) == 0) {
                int id;
                Problem* problem;
                scanf("%d", &id);
                problem = ProblemMap[id];
                //若查询不到，提示NO RESULT
                if (problem == NULL) {
                    printf("NO RESULT\n");
                }
                //若当前题目被安排进比赛，且为普通用户，提示NO PRIVILEGE
                else if (!isRootUser && problem->referCount > 0) {
                    printf("NO PRIVILEGE\n");
                }
                else {
                    printf("%s\n", problem->name);
                }
            }
            else if (strcmp("SELECTCONTEST", tempString) == 0) {
                int id;
                Contest* contest;
                scanf("%d", &id);
                contest = ContestMap[id];
                //若查询不到，提示NO RESULT
                if (contest == NULL) {
                    printf("NO RESULT\n");
                    continue;
                }
                printf("%s", contest->name);
                //若为管理员用户，则显示题号
                if (isRootUser) {
                    for (int j = 0; j < contest->problemNum; j++) {
                        int problemId = contest->problemIdArr[j];
                        if (problemId != -1 && ProblemMap[problemId] != NULL) {
                            printf("%d", problemId);
                        }
                    }
                }
                putchar('\n');
            }
        }
    }
    return 0;
}