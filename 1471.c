#include <stdio.h>

//给出一百分制成绩，要求输出成绩等级‘A’、‘B’、‘C’、‘D’、‘E’。 90分以上为A 80-89分为B 70-79分为C 60-69分为D 60分以下为E

int foo(int s, int a, int b) {
    return a <= s && s <= b;
}

int main() {
    char ans;
    int score;
    scanf("%d", &score);
    if (foo(score, 90, 100)) {
        ans = 'A';
    }
    else if (foo(score, 80, 89)) {
        ans = 'B';
    }
    else if (foo(score, 70, 79)) {
        ans = 'C';
    }
    else if (foo(score, 60, 69)) {
        ans = 'D';
    }
    else {
        ans = 'E';
    }
    putchar(ans);
}