#include <stdio.h>

//utf-8����һ������ռ3~4���ֽ�
char ChineseCharArr[][4] = {"��", "һ", "��", "��", "��", "��", "��", "��", "��", "��", "ʮ"};

void handleTensNumber(int num) {
    int digit_ten = num / 10;
    int digit_one = num % 10;
    digit_ten != 1 && printf("%s", ChineseCharArr[digit_ten]);
    printf("ʮ");
    digit_one > 0 && printf("%s", ChineseCharArr[digit_one]);
}

void handleHundredsNumber(int num) {
    int digit_hundred = num / 100;
    int digit_ten = num % 100;
    digit_hundred > 0 && printf("%s��", ChineseCharArr[digit_hundred]);
    if (0 < digit_ten && digit_ten <= 9) {
        printf("��%s", ChineseCharArr[digit_ten]);
    } 
    else if (0 < digit_ten) {
        digit_ten / 10 == 1 && printf("һ");
        handleTensNumber(digit_ten);
    }
}

void handleThousandsNumber(int num) {
    int digit_thousand = num / 1000;
    int digit_hundred = num / 100 % 10;
    int digit_hundred_total = num % 1000;
    printf("%sǧ", ChineseCharArr[digit_thousand]);
    if (0 < digit_hundred_total && digit_hundred_total <= 9) {
        printf("��%s", ChineseCharArr[digit_hundred_total]);
    } 
    else if (0 < digit_hundred_total) {
        digit_hundred == 0 && printf("��");
        handleHundredsNumber(digit_hundred_total);
    }
}

int main() {
    int num;
    while (scanf("%d", &num) != EOF) {
        if (0 <= num && num <= 9) {
            printf("%s", ChineseCharArr[num]);
        }
        else if (10 <= num && num <= 99) {
            handleTensNumber(num);
        }
        else if (100 <= num && num <= 999) {
            handleHundredsNumber(num);
        }
        else {
            handleThousandsNumber(num);
        }
        printf("\n"); 
    }
}