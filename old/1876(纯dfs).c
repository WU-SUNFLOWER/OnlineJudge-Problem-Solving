#include <stdio.h>
#include <stdlib.h>

/* 栈模块开始 */
typedef struct {
    int* arr;
    int size;
    int maxSize;
} Stack;

Stack* createStack(int maxSize) {
    Stack* stack = (Stack*)malloc(sizeof(Stack));
    stack->arr = (int*)malloc(sizeof(int) * maxSize);
    stack->size = 0;
    stack->maxSize = maxSize;
    return stack;
}

void freeStack(Stack* stack) {
    free(stack->arr);
    free(stack);
}

Stack* pushToStack(Stack* stack, int ele) {
    if (stack->size < stack->maxSize) {
        stack->arr[stack->size] = ele;
        stack->size++;
    }
    return stack;
}

Stack* popFromStack(Stack* stack) {
    if (stack->size > 0) {
        stack->size--;
        stack->arr[stack->size] = -1;
    }
    return stack;
}

int isEmptyStack(Stack* stack) {
    return !(stack->size);
}

int getPeekFromStack(Stack* stack) {
    if (stack->size <= 0) {
        return -1;
    } else {
        return stack->arr[stack->size - 1];
    }
}

//校验出栈顺序是否合法
//注意传入时pushOrder，popOrder两者的长度必须相等，且必须小于stack的maxSize
int checkLegalOrder(Stack* stack, int length, int pushOrder[], int popOrder[]) {
    int i = 0;  //用于数组pushOrder的指针
    int j = 0;  //用于数组popOrder的指针
    for (; i < length; i++) {
        pushToStack(stack, pushOrder[i]);
        while (j < length && !isEmptyStack(stack) && popOrder[j] == getPeekFromStack(stack)) {
            popFromStack(stack);
            j++;
        }
    }
    return isEmptyStack(stack);
}
/* 栈模块结束 */

/* dfs模块开始 */
void dfs(Stack* stack, int fullSize, int leftNum, int* ans) {
    //第一种情况：所有元素均已在入栈后重新弹出栈，则搜索结束
    if (leftNum == fullSize && stack->size == 0) {
        (*ans)++;
        return;
    }
    //第二种情况：当前栈未满，且还有元素未入过栈（注意每一个元素只有一次出入栈的机会），则将其入栈
    if (stack->size < fullSize && leftNum < fullSize) {
        //由于题目只要求情况数，不要求列举每组出栈方案
        //这里可以直接用抽象的“0”来代替实际出入栈的元素
        pushToStack(stack, 0);
        dfs(stack, fullSize, leftNum, ans);
        //别忘了回溯
        popFromStack(stack);        
    }
    //第三种情况：当前栈非空，则弹出栈首元素
    if (stack->size > 0) {
        popFromStack(stack);
        dfs(stack, fullSize, leftNum + 1, ans);
        //别忘了回溯
        pushToStack(stack, 0);
    }
}
/* dfs模块结束 */

int main() {
    int size;
    int ans = 0;
    Stack* stack;
    scanf("%d", &size);
    stack = createStack(size);
    dfs(stack, size, 0, &ans);
    printf("%d\n", ans);
}