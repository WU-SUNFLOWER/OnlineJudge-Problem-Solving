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

// 注：start包含在遍历区间内，end不包含在遍历区间内
int solve(char* exp, char* exp_prefix, int start, int end, int start_prefix) {
    Stack* stack_operation = createStack(N, sizeof(char));
    int index = start;
    int index_prefix = start_prefix;
    char peekOp;
    /* 扫描表达式，初始化堆栈的状态 */
    while (index < end) {
        int curIndex = index;
        char ch = exp[index++];
        // 如果当前字符是左括号，则找出右括号，递归求解
        if (ch == '(') {
            index = findRightBracket(exp, curIndex);
            int subExpSize = solve(exp, exp_prefix, curIndex + 1, index, index_prefix);
            // 更新index哨兵
            index_prefix += subExpSize;
            index++;
        }
        // 如果当前字符是数字,就通过遍历提取一个完整的数字出来
        else if ('0' <= ch && ch <= '9') {
            // 为方便处理，将索引哨兵退回到第一个数字字符的位置
            index--;
            while (1) {
                if (exp[index] < '0' || exp[index] > '9') break;
                exp_prefix[index_prefix++] = exp[index++];
            }
        }
        // 如果当前字符是运算符,且栈为空
        else if (isEmptyStack(stack_operation)) {
            pushToStack(stack_operation, &ch);
        }
        // 如果当前字符是运算符,且栈不空
        // 则先一次性计算完堆栈中已有的同优先级或更高优先级的运算符
        // 而由于右操作数现在还不知道，所以还要先记录当前的运算符，以备后续能够计算
        else {
            do {
                getPeekFromStack(stack_operation, &peekOp);
                if (priority[peekOp] < priority[ch]) break;
                popFromStack(stack_operation, &peekOp);
                exp_prefix[index_prefix++] = peekOp;
            } while (!isEmptyStack(stack_operation));
            pushToStack(stack_operation, &ch);
        }
    }
    /* 清空操作符堆栈，得出最终结果 */
    while (!isEmptyStack(stack_operation)) {
        popFromStack(stack_operation, &peekOp);
        exp_prefix[index_prefix++] = peekOp;
    }
    /* 释放堆栈，返回最终结果 */
    freeStack(stack_operation);
    return index_prefix - start_prefix;
}

int main() {
    int total;
    char expression_infix[N] = {0};
    char expression_prefix[N] = {0};
    // 初始化优先级表
    priority['+'] = 0;
    priority['-'] = 0;
    priority['*'] = 1;
    priority['/'] = 1;
    gets(expression_infix);
    int size = solve(expression_infix, expression_prefix, 0, strlen(expression_infix), 0);
    
    for (int i = 0; i < size; i++) {
        printf(i == size - 1 ? "%c\n" : "%c ", expression_prefix[i]);
    }
    
}