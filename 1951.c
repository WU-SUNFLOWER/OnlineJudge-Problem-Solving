#include <stdio.h>
//�߿��������£�����Ƥ��ÿ����غ󷴵��������ĸ߶�Ϊǰһ�θ߶ȵ�50%��
//��˷������������ڵ�10�����ʱ�����ĸ߶ȣ�����12�����ʱ��������·�̣�

int main() {
    double distance = 0;
   double height = 100;
   for (int i = 1; i <= 12; i++) {
       if (i == 1) {
           distance += height;
       } else {
           distance += height * 2;
       }
       height *= 0.5;
       if (i == 10) {
           printf("%lf,", height);
       }
   }
   printf("%lf", distance);
}