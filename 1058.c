#include <stdio.h>
#include <string.h>

int main() {
    int i;
    int j;
    int Anemone_Len;
    int Crab_Len;
    int Anemone[100000];
    int Crab[100000];
    char tempStr[100000];
    while (1) {
        //����������
        scanf("%s", tempStr);
        if (tempStr[0] == '0')  {
            break;
        }
        for (i = 0; tempStr[i]; i++) {
            Anemone[i] = (int)(tempStr[i] - 'A');
        }
        Anemone_Len = i;
        //����ľ�з����
        scanf("%s", tempStr);
        for (i = 0; tempStr[i]; i++) {
            Crab[i] = (int)(tempStr[i] - 'A');
        }
        Crab_Len = i;
        //�������޷������ľ�з�����
        if (Anemone_Len < Crab_Len) {
            printf("No\n");
            continue;
        }
        //ƥ�����
        i = 0;
        j = 0;
        int flag = 0;
        while (i < Anemone_Len && j < Crab_Len) {
            //���һ�����ߵ�ǰ����ƥ��
            if (Anemone[i] + Crab[j] == 25) {
                i++;
                j++;
                if (j == Crab_Len) {
                    flag = 1;
                    break;
                }
            }
            //����������ߵ�ǰ���岻ƥ��
            //�����ú�������һ���������ƥ��
            else {
                i++;
            }
        }
        if (flag) {
            printf("Yes\n");
        } else {
            printf("No\n");
        }
    }
}
