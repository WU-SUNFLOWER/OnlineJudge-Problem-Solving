#include <stdio.h>
#include <string.h>

int main() {
    int temp;
    int num;
    int count;
    int indexArr[200];
    int priceArr[200];
    char nameArr[200][200];
    scanf("%d", &count);
    while (count > 0) {
        scanf("%d", &num);
        for (int i = 0; i < num; i++) {
            indexArr[i] = i;
            scanf("%s %d", nameArr[i], &priceArr[i]);
        }
        for (int i = 0; i < num - 1; i++) {
            for (int j = 0; j < num - 1 - i; j++) {
                if (priceArr[indexArr[j]] > priceArr[indexArr[j + 1]]) {
                    temp = indexArr[j];
                    indexArr[j] = indexArr[j + 1];
                    indexArr[j + 1] = temp;
                }
            }
        }
        for (int i = 0; i < num; i++) {
            printf("%s %d\n", nameArr[indexArr[i]], priceArr[indexArr[i]]);
        }
        count--;  
    }
}