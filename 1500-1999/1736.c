#include <stdio.h>

typedef struct student {
    char name[30];
    double score1;
    double score2;
    double score3;
} Student;

int main() {
    int total;
    int idx = 0;
    int idx_pass = 0;
    int idx_notPass = 0;
    int idx_good = 0;
    Student allStudents[30];
    Student passStudents[30];
    Student notPassStudents[30];
    Student goodStudents[30];
    scanf("%d", &total);
    while (
        ~scanf("%s %lf %lf %lf", allStudents[idx].name, &allStudents[idx].score1, &allStudents[idx].score2, &allStudents[idx].score3)
    ) {
        Student cur = allStudents[idx];
        double tot = cur.score1 + cur.score2 + cur.score3;
        if (tot >= 300) {
            goodStudents[idx_good++] = cur;
        }
        if (tot >= 180) {
            passStudents[idx_pass++] = cur;
            
        } else {
            notPassStudents[idx_notPass++] = cur;
        }
        idx++;
    }
    for (int i = 0; i < idx_pass; i++) {
        Student cur = passStudents[i];
        printf("%s -- pass exam\n", cur.name);
    }
    for (int i = 0; i < idx_notPass; i++) {
        Student cur = notPassStudents[i];
        printf("%s -- not pass exam\n", cur.name);
    }
    for (int i = 0; i < idx_good; i++) {
        Student cur = goodStudents[i];
        printf("%s -- 3 x 100.0\n", cur.name);
    }
}