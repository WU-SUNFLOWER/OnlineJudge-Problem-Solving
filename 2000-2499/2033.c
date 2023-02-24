#include <stdio.h>
#include <stdlib.h>

/* ջģ�鿪ʼ */

typedef int ElementType;

typedef struct {
    ElementType* arr;
    ElementType size;
    ElementType maxSize;
} Stack;

Stack* createStack(int maxSize) {
    Stack* stack = (Stack*)malloc(sizeof(Stack));
    stack->arr = (ElementType*)malloc(sizeof(ElementType) * maxSize);
    stack->size = 0;
    stack->maxSize = maxSize;
    return stack;
}

void freeStack(Stack* stack) {
    free(stack->arr);
    free(stack);
}

Stack* pushToStack(Stack* stack, ElementType ele) {
    if (stack->size < stack->maxSize) {
        stack->arr[stack->size] = ele;
        stack->size++;
    }
    return stack;
}

ElementType popFromStack(Stack* stack) {
    ElementType ans = -1;
    if (stack->size > 0) {
        ans = stack->arr[stack->size - 1];
        stack->size--;
        stack->arr[stack->size] = -1;
    }
    return ans;
}

int isEmptyStack(Stack* stack) {
    return !(stack->size);
}

ElementType getPeekFromStack(Stack* stack) {
    if (stack->size <= 0) {
        return -1;
    } else {
        return stack->arr[stack->size - 1];
    }
}

//У���ջ˳���Ƿ�Ϸ�
//ע�⴫��ʱpushOrder��popOrder���ߵĳ��ȱ�����ȣ��ұ���С��stack��maxSize
int checkLegalOrder(Stack* stack, int length, ElementType pushOrder[], ElementType popOrder[]) {
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

//���ַ���ָ���±꿪ʼ��ȡ����
char getNumber(char str[], int* index) {
    int ans = 0;
    while ('0' <= str[*index] && str[*index] <= '9') {
        ans = ans * 10 + str[*index] - '0';
        (*index)++;
    }
    return ans;
}

int isOperation(char ch) {
    return ch == '+' || ch == '*' || ch == '-' || ch == '/';
}

int main() {
    char expression[500];
    Stack* tokenStack = createStack(500);
    Stack* operationStack = createStack(500);
    gets(expression);
    for (int i = 0; expression[i]; i++) {
        char ch = expression[i];
        //��һ��������������������򽫲�������ջ
        //�ڶ��������������ʶ��')',�򴥷���ջ��ֱ������'('Ϊֹ
        //������������������ֻ��ʶ��'('����������ջ
        if (isOperation(ch)) {
            pushToStack(operationStack, ch);
        }
        else if (ch == ')') {
            int ans = 0;
            int tempNum = 0;
            char op = popFromStack(operationStack);
            switch (op) {
                case '+':
                    while (getPeekFromStack(tokenStack) != '(') {
                        ans += getPeekFromStack(tokenStack);
                        popFromStack(tokenStack);
                    }
                    break;
                case '*':
                    ans = 1;
                    while (getPeekFromStack(tokenStack) != '(') {
                        ans *= getPeekFromStack(tokenStack);
                        popFromStack(tokenStack);
                    }
                    break;
                case '-':
                    while (1) {
                        if (getPeekFromStack(tokenStack) == '(') {
                            ans += tempNum;
                            break;
                        } else {
                            ans -= tempNum;
                            tempNum = popFromStack(tokenStack);
                        }
                    }
                    break;
                case '/':
                    ans = tempNum = 1;
                    while (1) {
                        if (getPeekFromStack(tokenStack) == '(') {
                            ans = tempNum / ans;
                            break;
                        } else {
                            ans *= tempNum;
                            tempNum = popFromStack(tokenStack);
                        }
                    }
                    break;
            }
            //�����Ҫ��'('����
            popFromStack(tokenStack);
            pushToStack(tokenStack, ans);
        }
        else if (ch == '('){
            pushToStack(tokenStack, ch);
        }
        else if ('0' <= ch && ch <= '9'){
            pushToStack(tokenStack, getNumber(expression, &i));
            i--;
        }
    }
    printf("%d\n", getPeekFromStack(tokenStack));
}