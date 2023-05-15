#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <ctype.h>
#define N 100

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
    memcpy(targetAddr, stack->data + elemSize * --stack->size, elemSize);
}

bool isEmptyStack(Stack stack) {
    return stack->size == 0;
}

bool isoperator(char ch) {
    return ch == '+' || ch == '-' || ch == '*' || ch == '/';
}

int compute(int nums[], int length, char op) {
    int result = 0;
    if (length > 0) {
        result = nums[length - 1];
        for (int i = length - 2; i >= 0; i--) {
            switch (op) {
                case '+':
                    result += nums[i];
                    break;
                case '-':
                    result -= nums[i];
                    break;
                case '*':
                    result *= nums[i];
                    break;
                case '/':
                    result /= nums[i];
                    break;
            }
        }
    }
    return result;
}

int main() {
    char lispExpr[N];  // 储存lisp表达式
    gets(lispExpr);
    // 对字符串进行修正，以便于使用strtok函数
    char ch;
    int idx = 0;
    char fixedExpr[2 * N] = {0};
    for (int i = 0; ch = lispExpr[i]; i++) {
        if (ch == '(' || ch == ')' || isoperator(ch)) {
            fixedExpr[idx++] = ' ';
            fixedExpr[idx++] = ch;
            fixedExpr[idx++] = ' ';
        } else {
            fixedExpr[idx++] = ch;
        }
    }
    // 计算表达式
    char* ptr = strtok(fixedExpr, " ");
    Stack stack = createStack(N, sizeof(int));
    Stack flagStack = createStack(N, sizeof(bool));
    while (ptr) {
        char ch = *ptr;
        // 碰到左括号(，则什么都不做
        // 碰到运算符或数字，入栈，并做好标记
        // 碰到右括号，则刷新堆栈并进行计算
        if (isdigit(ch)) {
            bool flag = false;
            int num = atoi(ptr);
            pushToStack(stack, &num);
            pushToStack(flagStack, &flag);
        }
        else if (isoperator(ch)) {
            bool flag = true;
            int num = (int)ch;
            pushToStack(stack, &num);
            pushToStack(flagStack, &flag);
        }
        else if (ch == ')') {
            int elem;
            char op;
            bool flag;
            int nums[N];
            int cnt_num = 0;
            while (1) {
                popFromStack(stack, &elem);
                popFromStack(flagStack, &flag);
                // 碰到操作符则停止出栈操作
                if (flag) {
                    op = elem;
                    break;
                } else {
                    nums[cnt_num++] = elem;
                }
            }
            // 计算结果，并将其放回堆栈中
            int result = compute(nums, cnt_num, op);
            flag = false;
            pushToStack(stack, &result);
            pushToStack(flagStack, &flag);
        }
        // 更新ptr，读取下一个元素
        ptr = strtok(NULL, " ");
    }
    int ans;
    popFromStack(stack, &ans);
    printf("%d", ans);
}