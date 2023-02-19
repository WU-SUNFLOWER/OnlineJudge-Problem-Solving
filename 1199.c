#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define N 110

/* 栈模块 开始 */
typedef struct {
    void* arr;
    int size;
    int maxSize;
    int elemSize;
} Stack;

Stack* createStack(int maxSize, int elemSize) {
    Stack* stack = (Stack*)malloc(sizeof(Stack));
    stack->arr = malloc(elemSize * maxSize);
    stack->size = 0;
    stack->maxSize = maxSize;
    stack->elemSize = elemSize;
    return stack;
}

void freeStack(Stack* stack) {
    free(stack->arr);
    free(stack);
}

Stack* pushToStack(Stack* stack, void* elemAddr) {
    if (stack->size < stack->maxSize) {
        int elemSize = stack->elemSize;
        void* targetAddr = stack->arr + stack->size * elemSize;
        memcpy(targetAddr, elemAddr, elemSize);
        stack->size++;
    }
    return stack;
}

Stack* popFromStack(Stack* stack, void* elemAddr) {
    if (stack->size > 0) {
        stack->size--;
        int elemSize = stack->elemSize;
        void* targetAddr = stack->arr + stack->size * elemSize;
        memcpy(elemAddr, targetAddr, elemSize);
    }
    return stack;
}

int isEmptyStack(Stack* stack) {
    return !(stack->size);
}

Stack* getPeekFromStack(Stack* stack, void* elemAddr) {
    if (stack->size > 0) {
        int elemSize = stack->elemSize;
        void* targetAddr = stack->arr + (stack->size - 1) * elemSize;
        memcpy(elemAddr, targetAddr, elemSize);
    }
    return stack;
}    
/* 栈模块 结束 */

// 优先级表，乘除的优先级高于加减
int priority[0x7f];

// 括号匹配函数，返回指定位置左括号匹配的右括号位置
int findRightBracket(char* str, int start) {
    int index = start;
    Stack* stack = createStack(N, sizeof(char));
    do {
        char ch = str[index++];
        if (ch == '(') {
            pushToStack(stack, &ch);
        }
        else if (ch == ')') {
            popFromStack(stack, &ch);
        }
    } while (!isEmptyStack(stack));
    freeStack(stack);
    return index - 1;
}

double compute(char op, double left, double right) {
    double ans;
    switch (op) {
        case '+':
            ans = left + right;
            break;
        case '-':
            ans = left - right;
            break;
        case '*':
            ans = left * right;
            break;
        case '/':
            ans = left / right;
            break;
    }
    return ans;
}

// 注：start包含在遍历区间内，end不包含在遍历区间内
double solve(char* exp, int start, int end) {
    Stack* stack_digit = createStack(N, sizeof(double));
    Stack* stack_operation = createStack(N, sizeof(char));
    int index = start;
    /* 扫描表达式，初始化堆栈的状态 */
    while (index < end) {
        int curIndex = index;
        char ch = exp[index++];
        // 如果当前字符是左括号，则找出右括号，递归求解
        if (ch == '(') {
            double newDigit;
            index = findRightBracket(exp, curIndex);
            newDigit = solve(exp, curIndex + 1, index);
            pushToStack(stack_digit, &newDigit);
            // 别忘了更新index哨兵，让它指向)右边的第一个字符
            index++;
        }
        // 如果当前字符是数字,就通过遍历提取一个完整的数字出来
        else if ('0' <= ch && ch <= '9') {
            double newDigit = 0;
            // 为方便处理，将索引哨兵退回到第一个数字字符的位置
            index--;
            while (1) {
                if (exp[index] < '0' || exp[index] > '9') break;
                newDigit = newDigit * 10 + (exp[index] - '0');
                index++;
            }
            pushToStack(stack_digit, &newDigit);
        }
        // 如果当前字符是运算符,且栈为空
        else if (isEmptyStack(stack_operation)) {
            pushToStack(stack_operation, &ch);
        }
        // 如果当前字符是运算符,且栈不空
        else {
            char peekOp;
            getPeekFromStack(stack_operation, &peekOp);
            // 当栈顶元素比当前遍历得到的操作符，具有更低的优先级时
            // 例如栈顶是+，现在遍历到的是*
            // 先不急着计算，把新得到的操作符压入堆栈
            if (priority[ch] > priority[peekOp]) {
                pushToStack(stack_operation, &ch);
            } else {
                double a = 0;
                double b = 0;
                double newDigit;
                // 清除掉栈顶元素
                popFromStack(stack_operation, &peekOp);
                // 根据栈顶操作符进行计算
                popFromStack(stack_digit, &a);
                if (!isEmptyStack(stack_digit)) {
                    popFromStack(stack_digit, &b);
                }
                newDigit = compute(peekOp, b, a);
                pushToStack(stack_digit, &newDigit);
                pushToStack(stack_operation, &ch);
            }
        }
    }
    /* 清空操作符堆栈，得出最终结果 */
    while (!isEmptyStack(stack_operation)) {
        char peekOp;
        double a = 0;
        double b = 0;
        double newDigit;
        // 清除掉栈顶元素
        popFromStack(stack_operation, &peekOp);
        // 根据栈顶操作符进行计算
        popFromStack(stack_digit, &a);
        // 处理左操作数不存在的情况，例如+1
        if (!isEmptyStack(stack_digit)) {
            popFromStack(stack_digit, &b);
        }
        newDigit = compute(peekOp, b, a);
        pushToStack(stack_digit, &newDigit);
    }
    /* 释放堆栈，返回最终结果 */
    double ans;
    getPeekFromStack(stack_digit, &ans);
    freeStack(stack_digit);
    freeStack(stack_operation);
    return ans;
}

int main() {
    char expression[N];
    // 初始化优先级表
    priority['+'] = 0;
    priority['-'] = 0;
    priority['*'] = 1;
    priority['/'] = 1;
    while (gets(expression) != NULL) {
        printf("%.3lf\n", solve(expression, 0, strlen(expression)));
    }
}