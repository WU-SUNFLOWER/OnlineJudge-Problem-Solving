#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <stdlib.h>
#include <ctype.h>
#define N 105

typedef struct stack {
    void* data;
    int size;
    int elemSize;
} *Stack;

Stack createStack(int maxSize, int elemSize) {
    Stack stack = (Stack)malloc(sizeof(struct stack));
    stack->size = 0;
    stack->elemSize = elemSize;
    stack->data = malloc(maxSize * elemSize);
    return stack;
}

void freeStack(Stack stack) {
    free(stack->data);
    free(stack);
}

void pushToStack(Stack stack, void* targetAddr) {
    int elemSize = stack->elemSize;
    memcpy(stack->data + elemSize * stack->size, targetAddr, elemSize);
    stack->size++;
}

void popFromStack(Stack stack, void* targetAddr) {
    int elemSize = stack->elemSize;
    --stack->size;
    if (targetAddr) memcpy(targetAddr, stack->data + elemSize * stack->size, elemSize);
}

void getPeekFromStack(Stack stack, void* targetAddr) {
    int elemSize = stack->elemSize;
    memcpy(targetAddr, stack->data + elemSize * (stack->size - 1), elemSize);
}

bool isEmptyStack(Stack stack) {
    return stack->size == 0;
}

// 优化表达式，便于使用strtok函数
char* optimizeExpr(char str[], char newStr[]) {
    int idx = 0;
    char ch;
    for (int i = 0; ch = str[i]; i++) {
        if (isdigit(ch)) {
            newStr[idx++] = ch;
        } else {
            newStr[idx++] = ' ';
            newStr[idx++] = ch;
            newStr[idx++] = ' ';
        }
    }
    newStr[idx++] = '\0';
    return newStr;
}

void createPostFixExpr(char inFixExpr[], char postFixExpr[]) {
    int idx = 0;
    char* ptr = strtok(inFixExpr, " ");
    Stack stack = createStack(N, sizeof(char));
    int priority[0x7f];
    priority['('] = 0;
    priority['+'] = priority['-'] = 1;
    priority['*'] = priority['/'] = 2;
    while (ptr) {
        char ch = *ptr;
        // 1.碰到数字，直接输出
        if (isdigit(ch)) {
            strcpy(postFixExpr + idx, ptr);
            idx = idx + strlen(ptr);
            postFixExpr[idx++] = ' ';
        }
        // 2.碰到左括号，直接入栈
        else if (ch == '(') {
            pushToStack(stack, &ch);
        }
        // 3.碰到右括号，强制输出内容，直到遇见左括号
        else if (ch == ')') {
            char op;
            while (1) {
                popFromStack(stack, &op);
                if (op == '(') break;
                postFixExpr[idx++] = op;
                postFixExpr[idx++] = ' ';
            }
        }
        // 4.以上皆非，碰到普通运算符
        else {
            char top;
            while (!isEmptyStack(stack)) {
                getPeekFromStack(stack, &top);
                // 如果栈顶操作符的优先级更低，则不进行操作
                if (priority[top] < priority[ch]) break;
                // 否则输出栈顶操作符
                popFromStack(stack, NULL);
                postFixExpr[idx++] = top;
                postFixExpr[idx++] = ' ';
            }
            // 当栈被清空，或者栈顶碰到优先级更低的操作符
            // 则将当前操作符压入栈中待命
            pushToStack(stack, &ch);
        }
        ptr = strtok(NULL, " ");
    }
    // 输出栈中剩余的运算符
    // 这一步相当于为整个表达式最外层打上一对括号
    // 然后执行上面循环语句中的第二种情况
    char op;
    while (!isEmptyStack(stack)) {
        popFromStack(stack, &op);
        postFixExpr[idx++] = op;
        postFixExpr[idx++] = ' ';
    }
    postFixExpr[idx] = '\0';
    freeStack(stack);
}

double compute(char op, double l, double r) {
    switch (op) {
        case '+':
            return l + r;
        case '-':
            return l - r;
        case '*':
            return l * r;
        case '/':
            return l / r;
    }
}

double parsePostFixExpr(char postFixExpr[]) {
    double result;
    Stack stack = createStack(N, sizeof(double));
    char* ptr = strtok(postFixExpr, " ");
    while (ptr) {
        char ch = *ptr;
        if (isdigit(ch)) {
            double num = atof(ptr);
            pushToStack(stack, &num);
        } else {
            double r, l;
            // 从栈中先后弹出右、左操作数
            popFromStack(stack, &r);
            popFromStack(stack, &l);
            // 计算
            result = compute(ch, l, r);
            // 将结果压入栈中
            pushToStack(stack, &result);
        }
        ptr = strtok(NULL, " ");
    }
    popFromStack(stack, &result);
    freeStack(stack);
    return result;
}

int main() {
    char inputStr[N];
    char inFixExpr[2 * N];
    char postFixExpr[2 * N];
    while (gets(inputStr) != NULL) {
        optimizeExpr(inputStr, inFixExpr);
        createPostFixExpr(inFixExpr, postFixExpr);
        puts(postFixExpr);
        printf("%.3lf\n", parsePostFixExpr(postFixExpr));        
    }
}