#include <stdio.h>

//����һ�ٷ��Ƴɼ���Ҫ������ɼ��ȼ���A������B������C������D������E���� 90������ΪA 80-89��ΪB 70-79��ΪC 60-69��ΪD 60������ΪE

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