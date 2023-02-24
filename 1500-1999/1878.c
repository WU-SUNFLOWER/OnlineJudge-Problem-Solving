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

/*
Ackerman 函数定义如下：
                        ┌ n+1　　　                        当m=0时
        AKM ( m , n ) = │ AKM( m-1 ,1)                   当m≠0 ，n=0时
                        └ AKM( m-1, AKM( m,n-1))  当m≠0, n ≠ 0时
*/

int ack(int m, int n, Stack* stack_m, Stack* stack_n) {
    //先把起始的m、n压入调用栈中
    pushToStack(stack_m, m);
    pushToStack(stack_n, n);
    //栈m和栈n是同步更新的，因此只需要关注其中一个栈是否为空即可
    while (!isEmptyStack(stack_n)) {
        if (m == 0) {
            //递归调用求解出结果，就进行回溯，回到进入递归的地方
            n = n + 1;
            while (!isEmptyStack(stack_n) && getPeekFromStack(stack_n) != -1) {
                popFromStack(stack_m);
                popFromStack(stack_n);
            }
            if (!isEmptyStack(stack_n) && getPeekFromStack(stack_n) == -1) {
                //将m恢复成调用栈中保存的，进入嵌套调用时原先的m
                m = getPeekFromStack(stack_m);
                //将原先待求解n=-1换成求解出来的答案
                popFromStack(stack_n);
                pushToStack(stack_n, n);
            }
        }
        else if (n == 0) {
            m = m - 1;
            n = 1;
            //别忘了更新调用栈
            pushToStack(stack_m, m);
            pushToStack(stack_n, n);
        }
        else {
            //更新调用栈，用n=-1标记此处发生了嵌套调用
            pushToStack(stack_m, m - 1);
            pushToStack(stack_n, -1);
            //由于m、n用于保存调用栈栈顶元素的参数情况
            //所以m保持不动，n需要减1
            n = n - 1;
        }
    }
    //最后求解出的答案与n有关
    return n;
}

int main() {
    int m;
    int n;
    Stack* stack_m = createStack(100);
    Stack* stack_n = createStack(100);
    scanf("%d %d", &m, &n);
    printf("%d\n", ack(m, n, stack_m, stack_n));
}