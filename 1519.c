#include <stdio.h>
#include <stdlib.h>

typedef struct {
    char id[10];
    char name[10];
    double score1;
    double score2;
    double score3;
    double totalScore;
} Student;

Student* createStudent() {
    return (Student*)malloc(sizeof(Student));
}

int main() {
    int studentNum;
    Student* studentArr[50];
    scanf("%d", &studentNum);
    for (int i = 0; i < studentNum; i++) {
        Student* temp = createStudent();
        studentArr[i] = temp;
        scanf("%s %s %lf %lf %lf", &temp->id, &temp->name, &temp->score1, &temp->score2, &temp->score3);
        temp->totalScore = temp->score1 + temp->score2 + temp->score3;
    }
    //统计平均成绩,并求解最高分学生
    Student* topStudent = studentArr[0];
    double averageScore1 = 0;
    double averageScore2 = 0;
    double averageScore3 = 0;
    for (int i = 0; i < studentNum; i++) {
        averageScore1 += studentArr[i]->score1;
        averageScore2 += studentArr[i]->score2;
        averageScore3 += studentArr[i]->score3;
        if (studentArr[i]->totalScore > topStudent->totalScore) {
            topStudent = studentArr[i];
        }
    }
    averageScore1 /= studentNum;
    averageScore2 /= studentNum;
    averageScore3 /= studentNum;
    //输出
    printf("%g %g %g\n", averageScore1, averageScore2, averageScore3);
    printf("%s %s %g %g %g\n", topStudent->id, topStudent->name, topStudent->score1, topStudent->score2, topStudent->score3);
}