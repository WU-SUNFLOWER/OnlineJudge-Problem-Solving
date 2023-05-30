#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define N 100

typedef struct stack {
    int size;
    int data[N];
} *Stack;

Stack createStack() {
    Stack s = (Stack)malloc(sizeof(struct stack));
    s->size = 0;
    return s;
}

void Push(Stack s, int element) {
    s->data[s->size++] = element;
}

int Pop(Stack s) {
    return s->data[--s->size];
}

bool isEmpty(Stack s) {
    return s->size == 0;
}

int getPeak(Stack s) {
    return s->data[s->size - 1];
}

int compute(char op, int l, int r) {
    int ans;
    switch (op) {
        case '+':
            ans = l + r;
            break;
        case '-':
            ans = l - r;
            break;
        case '*':
            ans = l * r;
            break;
    }
    return ans;
}

int main() {
    int total;
    char expression[N];
    char precedence[0x7f];
    precedence['*'] = 2;
    precedence['+'] = precedence['-'] = 1;
    scanf("%d", &total);
    getchar();
    while (total-- > 0) {
        char ch;
        Stack s_op = createStack();
        Stack s_num = createStack();
        gets(expression);
        // 扫描表达式
        for (int i = 0; ch = expression[i]; i++) {
            if ('0' <= ch && ch <= '9') {
                Push(s_num, ch - '0');
            } else {
                // 处理栈中优先级比当前运算符高的运算符
                while (!isEmpty(s_op) && precedence[getPeak(s_op)] >= precedence[ch]) {
                    int right = Pop(s_num);  // 右操作数
                    int left = Pop(s_num);  // 左操作数
                    char op = Pop(s_op);
                    Push(s_num, compute(op, left, right));
                }
                // 将当前运算符压入堆栈
                Push(s_op, ch);
            }
        }
        // 清空堆栈中剩余的运算符
        while (!isEmpty(s_op)) {
            int right = Pop(s_num);
            int left = Pop(s_num);
            char op = Pop(s_op);
            Push(s_num, compute(op, left, right));
        }
        // 输出结果
        printf("%d\n", getPeak(s_num));
        free(s_op);
        free(s_num);
    }
}