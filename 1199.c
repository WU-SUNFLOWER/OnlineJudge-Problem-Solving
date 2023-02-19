#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define N 110

/* ջģ�� ��ʼ */
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
/* ջģ�� ���� */

// ���ȼ����˳������ȼ����ڼӼ�
int priority[0x7f];

// ����ƥ�亯��������ָ��λ��������ƥ���������λ��
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

// ע��start�����ڱ��������ڣ�end�������ڱ���������
double solve(char* exp, int start, int end) {
    Stack* stack_digit = createStack(N, sizeof(double));
    Stack* stack_operation = createStack(N, sizeof(char));
    int index = start;
    /* ɨ����ʽ����ʼ����ջ��״̬ */
    while (index < end) {
        int curIndex = index;
        char ch = exp[index++];
        // �����ǰ�ַ��������ţ����ҳ������ţ��ݹ����
        if (ch == '(') {
            double newDigit;
            index = findRightBracket(exp, curIndex);
            newDigit = solve(exp, curIndex + 1, index);
            pushToStack(stack_digit, &newDigit);
            // �����˸���index�ڱ�������ָ��)�ұߵĵ�һ���ַ�
            index++;
        }
        // �����ǰ�ַ�������,��ͨ��������ȡһ�����������ֳ���
        else if ('0' <= ch && ch <= '9') {
            double newDigit = 0;
            // Ϊ���㴦���������ڱ��˻ص���һ�������ַ���λ��
            index--;
            while (1) {
                if (exp[index] < '0' || exp[index] > '9') break;
                newDigit = newDigit * 10 + (exp[index] - '0');
                index++;
            }
            pushToStack(stack_digit, &newDigit);
        }
        // �����ǰ�ַ��������,��ջΪ��
        else if (isEmptyStack(stack_operation)) {
            pushToStack(stack_operation, &ch);
        }
        // �����ǰ�ַ��������,��ջ����
        else {
            char peekOp;
            getPeekFromStack(stack_operation, &peekOp);
            // ��ջ��Ԫ�رȵ�ǰ�����õ��Ĳ����������и��͵����ȼ�ʱ
            // ����ջ����+�����ڱ���������*
            // �Ȳ����ż��㣬���µõ��Ĳ�����ѹ���ջ
            if (priority[ch] > priority[peekOp]) {
                pushToStack(stack_operation, &ch);
            } else {
                double a = 0;
                double b = 0;
                double newDigit;
                // �����ջ��Ԫ��
                popFromStack(stack_operation, &peekOp);
                // ����ջ�����������м���
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
    /* ��ղ�������ջ���ó����ս�� */
    while (!isEmptyStack(stack_operation)) {
        char peekOp;
        double a = 0;
        double b = 0;
        double newDigit;
        // �����ջ��Ԫ��
        popFromStack(stack_operation, &peekOp);
        // ����ջ�����������м���
        popFromStack(stack_digit, &a);
        // ����������������ڵ����������+1
        if (!isEmptyStack(stack_digit)) {
            popFromStack(stack_digit, &b);
        }
        newDigit = compute(peekOp, b, a);
        pushToStack(stack_digit, &newDigit);
    }
    /* �ͷŶ�ջ���������ս�� */
    double ans;
    getPeekFromStack(stack_digit, &ans);
    freeStack(stack_digit);
    freeStack(stack_operation);
    return ans;
}

int main() {
    char expression[N];
    // ��ʼ�����ȼ���
    priority['+'] = 0;
    priority['-'] = 0;
    priority['*'] = 1;
    priority['/'] = 1;
    while (gets(expression) != NULL) {
        printf("%.3lf\n", solve(expression, 0, strlen(expression)));
    }
}