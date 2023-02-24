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

/*
Ackerman �����������£�
                        �� n+1������                        ��m=0ʱ
        AKM ( m , n ) = �� AKM( m-1 ,1)                   ��m��0 ��n=0ʱ
                        �� AKM( m-1, AKM( m,n-1))  ��m��0, n �� 0ʱ
*/

int ack(int m, int n, Stack* stack_m, Stack* stack_n) {
    //�Ȱ���ʼ��m��nѹ�����ջ��
    pushToStack(stack_m, m);
    pushToStack(stack_n, n);
    //ջm��ջn��ͬ�����µģ����ֻ��Ҫ��ע����һ��ջ�Ƿ�Ϊ�ռ���
    while (!isEmptyStack(stack_n)) {
        if (m == 0) {
            //�ݹ��������������ͽ��л��ݣ��ص�����ݹ�ĵط�
            n = n + 1;
            while (!isEmptyStack(stack_n) && getPeekFromStack(stack_n) != -1) {
                popFromStack(stack_m);
                popFromStack(stack_n);
            }
            if (!isEmptyStack(stack_n) && getPeekFromStack(stack_n) == -1) {
                //��m�ָ��ɵ���ջ�б���ģ�����Ƕ�׵���ʱԭ�ȵ�m
                m = getPeekFromStack(stack_m);
                //��ԭ�ȴ����n=-1�����������Ĵ�
                popFromStack(stack_n);
                pushToStack(stack_n, n);
            }
        }
        else if (n == 0) {
            m = m - 1;
            n = 1;
            //�����˸��µ���ջ
            pushToStack(stack_m, m);
            pushToStack(stack_n, n);
        }
        else {
            //���µ���ջ����n=-1��Ǵ˴�������Ƕ�׵���
            pushToStack(stack_m, m - 1);
            pushToStack(stack_n, -1);
            //����m��n���ڱ������ջջ��Ԫ�صĲ������
            //����m���ֲ�����n��Ҫ��1
            n = n - 1;
        }
    }
    //��������Ĵ���n�й�
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