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
/* 栈模块结束 */

// 元素总数
int tot;

// 为了方便起见，就不实现一个真正的队列了
// 这里直接采用数组模拟队列的按序出列效果
int pushOrder[100];

// 实时记录出栈顺序的数组
int ans[100];

int ansArr[100][100];

int cnt;

void dfs(Stack* stack, int idx_pushOrder, int idx_ans) {
    // 所有元素都已出栈，搜索结束，输出结果
    if (idx_ans == tot) {
        for (int i = 0; i < tot; i++) {
            ansArr[cnt][i] = ans[i];
        }
        cnt++;
        return;
    }
    // 如果当前栈为空，则只能入栈元素
    if (isEmptyStack(stack)) {
        pushToStack(stack, pushOrder[idx_pushOrder]);
        dfs(stack, idx_pushOrder + 1, idx_ans);
        // 因为本题是多答案dfs，所以即使当前
        // 搜索节点没有其他递归调用，也必须加上回溯操作！！！
        popFromStack(stack);
    }
    // 如果所有元素已入栈，则只能出栈元素
    else if (idx_pushOrder == tot) {
        ans[idx_ans] = getPeekFromStack(stack);
        popFromStack(stack);
        dfs(stack, idx_pushOrder, idx_ans + 1);
        // 此处同理，回溯操作不能少！！！
        pushToStack(stack, ans[idx_ans]);
    }
    // 不然的话，尝试入栈元素/出栈元素两种操作
    else {
        // 如果出栈一个元素
        ans[idx_ans] = getPeekFromStack(stack);
        popFromStack(stack);
        dfs(stack, idx_pushOrder, idx_ans + 1);
        pushToStack(stack, ans[idx_ans]);  // 回溯
        // 如果入栈一个元素
        pushToStack(stack, pushOrder[idx_pushOrder]);
        dfs(stack, idx_pushOrder + 1, idx_ans);
        popFromStack(stack);  // 回溯
    }
}

int main() {
    cnt = 0;
    scanf("%d", &tot);
    for (int i = 0; i < tot; i++) {
        pushOrder[i] = i + 1;
    }
    Stack* stack = createStack(100);
    dfs(stack, 0 , 0);
    printf("%d\n", cnt);
    for (int i = 0; i < cnt; i++) {
        for (int j = 0; j < tot; j++) {
            printf(j == tot - 1 ? "%d\n" : "%d ", ansArr[i][j]);
        }
    }
}