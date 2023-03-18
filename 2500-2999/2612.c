#include <stdio.h>
#include <stdbool.h>
#include <string.h>

bool checkFields(int fields[]) {
    for (int i = 0; i < 4; i++) {
        if (fields[i] < 0 || fields[i] > 255) {
            return false;
        }
    }
    return true;
}

int main() {
    char str[100];
    int fields[4];
    memset(fields, -1, sizeof(fields));
    scanf("%s", str);
    sscanf(str, "%d.%d.%d.%d", fields, fields + 1, fields + 2, fields + 3);
    if (checkFields(fields)) {
        int val = 0;
        for (int i = 0; i < 4; i++) {
            val = (val << 8) + fields[i];
        }
        printf("%d\n%x", val, val);
    } else {
        puts("error");
    }
}