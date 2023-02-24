#include <stdio.h>

//utf-8编码一个汉字占3~4个字节
char ChineseCharArr[][4] = {"零", "一", "二", "三", "四", "五", "六", "七", "八", "九", "十"};

void handleTensNumber(int num) {
    int digit_ten = num / 10;
    int digit_one = num % 10;
    digit_ten != 1 && printf("%s", ChineseCharArr[digit_ten]);
    printf("十");
    digit_one > 0 && printf("%s", ChineseCharArr[digit_one]);
}

void handleHundredsNumber(int num) {
    int digit_hundred = num / 100;
    int digit_ten = num % 100;
    digit_hundred > 0 && printf("%s百", ChineseCharArr[digit_hundred]);
    if (0 < digit_ten && digit_ten <= 9) {
        printf("零%s", ChineseCharArr[digit_ten]);
    } 
    else if (0 < digit_ten) {
        digit_ten / 10 == 1 && printf("一");
        handleTensNumber(digit_ten);
    }
}

void handleThousandsNumber(int num) {
    int digit_thousand = num / 1000;
    int digit_hundred = num / 100 % 10;
    int digit_hundred_total = num % 1000;
    printf("%s千", ChineseCharArr[digit_thousand]);
    if (0 < digit_hundred_total && digit_hundred_total <= 9) {
        printf("零%s", ChineseCharArr[digit_hundred_total]);
    } 
    else if (0 < digit_hundred_total) {
        digit_hundred == 0 && printf("零");
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