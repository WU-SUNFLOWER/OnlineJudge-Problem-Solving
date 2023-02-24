#include <stdio.h>

int main() {
    int ans;
    int correctAns;
    int a;
    int b;
    char command;
    while (~scanf("%d %d %c %d", &a, &b, &command, &ans)) {
        switch (command) {
            case '+':
                correctAns = a + b;
                break;
            case '-':
                correctAns = a - b;
                break;
            case '*':
                correctAns = a * b;
                break;
            case '/':
                correctAns = a / b;
                break;
        }
        printf(ans == correctAns ? "Yes\n" : "No\n");
    }
}