#include <stdio.h>
//高空自由落下，假设皮球每次落地后反弹，反弹的高度为前一次高度的50%，
//如此反复，请问它在第10次落地时反弹的高度，及第12次落地时经过的总路程？

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