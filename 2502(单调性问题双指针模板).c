#include <stdio.h>
#include <string.h>

int main() {
    //��������
    int length1;
    int length2;
    char str1[200];
    char str2[200];
    gets(str1);
    gets(str2);
    length1 = strlen(str1);
    length2 = strlen(str2);
    //���
    int i = 0;
    int j = 0;
    int idx = 0;
    char ans[200];
    //��Ҫ��֤i��j����һ��ָ��û��Խ��
    while (i < length1 || j < length2) {
        if (i < length1 && j < length2 && str1[i] == str2[j]) {
            ans[idx++] = str1[i];
            ans[idx++] = str2[j];
            i++;
            j++;
        }
        //�ƶ�����ָ����Ҫ�������������
        //��һ�֣�����һ��ָ��Խ�磬��ֻ���ƶ�����һ��ָ��
        //�ڶ��֣�����ָ�붼û��Խ�磬�����ֵ����С
        else if (i >= length1 || j < length2 && str1[i] > str2[j]) {
            ans[idx++] = str2[j];
            j++;
        }
        //��Ħ�����ɿ���ִ֪��else����Ϊ����������
        //i < length1 && (j >= length2 || str1[i] < str2[j])
        //����jָ��Խ�磬��������ָ���δԽ�磬�ֵ���str[i]<str2[j]
        //���ȼ���j >= length2 || i < length1 && str1[i] < str2[j]
        //�������������������ϣ���������ȫ��ȷ��
        else {
            ans[idx++] = str1[i];
            i++;
        }
    }
    ans[idx] = '\0';
    puts(ans);
}