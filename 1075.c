#include <stdio.h>
#include <math.h>

int main() {
    int m;
	int n;
    int f[1000];
	int g[1000];
    scanf("%d %d", &m, &n);
    for (int i = 0; i < m; i++) {
        scanf("%d", &f[i]);
    }
    for (int i = 0; i < n; i++) {
        scanf("%d", &g[i]);
    }
    int min = abs(f[0]-g[0]);  
    int i = 0;
	int j = 0;  
    while (i < m && j < n) {
        if (f[i] == g[j]) {  
			min = 0;  
            break;  
        }
		if (f[i] < g[j]) { 
			int temp = g[j] - f[i];
            if (temp < min)  min = temp;  
            i++;  
        } 
		else {  
			int temp = f[i] - g[j];
            if (temp < min)  min = temp;
			j++;
		}
    }
    printf("%d\n", min);
	return 0;  
}  