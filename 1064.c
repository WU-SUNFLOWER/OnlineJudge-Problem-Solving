#include <stdio.h>

int main() {
	char ch;
	int ans[4] = {0, 0, 0, 0};
	while (1) {
      	ch = getchar();
        if (ch == '\n') {
		  	printf("%d %d %d %d\n",ans[0],ans[1],ans[2],ans[3]);
			ans[0] = ans[1] = ans[2] = ans[3] = 0;
           	continue;
        } 
        else if (ch == EOF) {
           	break;
        }
		else if (ch >= 'A' && ch <= 'Z' || ch >='a' && ch <='z') {
           	ans[0]++;
        }
		else if (ch >='0' && ch <='9') {
           	ans[1]++;
		}
		else if (ch == ' ') {
           	ans[2]++;
        }
		else {
           	ans[3]++;
        }
	}
}