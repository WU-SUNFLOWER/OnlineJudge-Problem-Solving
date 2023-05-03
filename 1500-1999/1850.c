#include <stdio.h>
#include <stdlib.h>
#define N 250

/*
参考资料：
https://blog.csdn.net/qq_33369979/article/details/109127673
*/

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

/* dfs全排列开始 */
int OrderIdx = -1;
int PopOrder[N][N];

void swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void dfs(int arr[], int k, int length) {
    //搜索结束，将所得结果拷贝到OrderArr里头
    if (k == length) {
        OrderIdx++;
        for (int i = 0; i < length; i++) {
            PopOrder[OrderIdx][i] = arr[i];
        }
        return;
    }
    for (int i = k; i < length; i++) {
        swap(&arr[k], &arr[i]);
        dfs(arr, k + 1, length);
        //当前搜索路径结束之后需要进行回溯
        //类似于八皇后问题，需要使得arr数组恢复到交换前的状态
        swap(&arr[k], &arr[i]);
    }
}
/* dfs全排列结束 */

int main() {
    int length;
    int PushOrder[N];
    scanf("%d", &length);
    //初始化PushOrder数组
    for (int i = 0; i < length; i++) {
        scanf("%d", &PushOrder[i]);
    }
    //搜索出PushOrder的全排列,把结果存到PopOrder里
    dfs(PushOrder, 0, length);
    //对搜索出来的全排列逐一进行校验，确认其是否为可行的出栈顺序
    for (int i = 0; i <= OrderIdx; i++) {
        Stack* stack = createStack(N);
        if (checkLegalOrder(stack, length, PushOrder, PopOrder[i])) {
            for (int j = 0; j < length; j++) {
                printf(j == length - 1 ? "%d\n" : "%d ", PopOrder[i][j]);
            }
        }
    }
}