#include <stdio.h>
#include <time.h>
#include <string.h>

int getTimeStamp(char* timeStr) {
    //ʱ��ṹ��
    struct tm date;
    //����sscanf������ȡ�ַ�����Ϣ�����浽�ṹ����ȥ
    sscanf(timeStr, "%d/%d/%d %d:%d:%d", &date.tm_year, &date.tm_mon, &date.tm_mday, &date.tm_hour, &date.tm_min, &date.tm_sec);
    //�����ṹ���е�����
    //�˴��ɲμ�https://www.runoob.com/cprogramming/c-function-mktime.html
    date.tm_year -= 1900; 
    date.tm_mon -= 1;
    //���1970.01.01���ض����ڵ�����,������
    return mktime(&date);
}

int main() {
    char tempStr[100];
    int ts1;
    int ts2;
    //׼������
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
    //���ʱ���֮���λs��
    int residue;
    int dateDiff = ts1 - ts2;
    //�����������
    int years = dateDiff / (24 * 3600 * 365);
    residue = dateDiff % (24 * 3600 * 365);
    //�����������
    int months = residue / (24 * 3600 * 30);
    residue = residue % (24 * 3600 * 30);
    //������������
    int days = residue / (24 * 3600);
    residue = residue % (24 * 3600);
    //�����Сʱ��
    int hours = residue / 3600;
    residue = residue % 3600;
    //������������
    int minutes = residue / 60;
    residue = residue % 60;
    //�����������
    int seconds = residue;
    printf("%04d/%02d/%02d %02d:%02d:%02d\n", years, months, days, hours, minutes, seconds);
}