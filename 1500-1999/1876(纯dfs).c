#include <stdio.h>
#include <stdlib.h>

/* ջģ�鿪ʼ */
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

//У���ջ˳���Ƿ�Ϸ�
//ע�⴫��ʱpushOrder��popOrder���ߵĳ��ȱ�����ȣ��ұ���С��stack��maxSize
int checkLegalOrder(Stack* stack, int length, int pushOrder[], int popOrder[]) {
    int i = 0;  //��������pushOrder��ָ��
    int j = 0;  //��������popOrder��ָ��
    for (; i < length; i++) {
        pushToStack(stack, pushOrder[i]);
        while (j < length && !isEmptyStack(stack) && popOrder[j] == getPeekFromStack(stack)) {
            popFromStack(stack);
            j++;
        }
    }
    return isEmptyStack(stack);
}
/* ջģ����� */

/* dfsģ�鿪ʼ */
void dfs(Stack* stack, int fullSize, int leftNum, int* ans) {
    //��һ�����������Ԫ�ؾ�������ջ�����µ���ջ������������
    if (leftNum == fullSize && stack->size == 0) {
        (*ans)++;
        return;
    }
    //�ڶ����������ǰջδ�����һ���Ԫ��δ���ջ��ע��ÿһ��Ԫ��ֻ��һ�γ���ջ�Ļ��ᣩ��������ջ
    if (stack->size < fullSize && leftNum < fullSize) {
        //������ĿֻҪ�����������Ҫ���о�ÿ���ջ����
        //�������ֱ���ó���ġ�0��������ʵ�ʳ���ջ��Ԫ��
        pushToStack(stack, 0);
        dfs(stack, fullSize, leftNum, ans);
        //�����˻���
        popFromStack(stack);        
    }
    //�������������ǰջ�ǿգ��򵯳�ջ��Ԫ��
    if (stack->size > 0) {
        popFromStack(stack);
        dfs(stack, fullSize, leftNum + 1, ans);
        //�����˻���
        pushToStack(stack, 0);
    }
}
/* dfsģ����� */

int main() {
    int size;
    int ans = 0;
    Stack* stack;
    scanf("%d", &size);
    stack = createStack(size);
    dfs(stack, size, 0, &ans);
    printf("%d\n", ans);
}