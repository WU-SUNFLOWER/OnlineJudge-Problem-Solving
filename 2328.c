#include <stdio.h>
#include <time.h>
#include <string.h>

int getTimeStamp(char* timeStr) {
    //时间结构体
    struct tm date;
    //利用sscanf函数提取字符串信息，保存到结构体里去
    sscanf(timeStr, "%d/%d/%d %d:%d:%d", &date.tm_year, &date.tm_mon, &date.tm_mday, &date.tm_hour, &date.tm_min, &date.tm_sec);
    //修正结构体中的数据
    //此处可参见https://www.runoob.com/cprogramming/c-function-mktime.html
    date.tm_year -= 1900; 
    date.tm_mon -= 1;
    //求解1970.01.01到特定日期的秒数,并返回
    return mktime(&date);
}

int main() {
    char tempStr[100];
    int ts1;
    int ts2;
    //准备工作
    gets(tempStr);
    ts1 = getTimeStamp(tempStr);
    gets(tempStr);
    ts2 = getTimeStamp(tempStr);
    if (ts2 > ts1) {
        int temp = ts1;
        ts1 = ts2;
        ts2 = temp;
        putchar('-');
    }
    //求解时间戳之差（单位s）
    int residue;
    int dateDiff = ts1 - ts2;
    //计算相差年数
    int years = dateDiff / (24 * 3600 * 365);
    residue = dateDiff % (24 * 3600 * 365);
    //计算相差月数
    int months = residue / (24 * 3600 * 30);
    residue = residue % (24 * 3600 * 30);
    //计算出相差天数
    int days = residue / (24 * 3600);
    residue = residue % (24 * 3600);
    //计算出小时数
    int hours = residue / 3600;
    residue = residue % 3600;
    //计算相差分钟数
    int minutes = residue / 60;
    residue = residue % 60;
    //计算相差秒数
    int seconds = residue;
    printf("%04d/%02d/%02d %02d:%02d:%02d\n", years, months, days, hours, minutes, seconds);
}