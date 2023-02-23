#include <stdio.h>
#include <string.h>

int main() {
	int k,len1,l;
    char a[100];
    char c[100];
	scanf(" ‰»Îi=%d,len=%d,j=%d",&k,&len1,&l);
    do {
        gets(a);
    } while (strlen(a) < 5);
    do {
        gets(c);
    } while (strlen(c) < 5);
	int b[10000]= {0},d[10000]= {0},m,n;
	m=0;
	for(int i=0; i < strlen(a); i++ ) {
		if(( a[i] >= '0' && a[i] <= '9')||a[i]==' ') {
			if(a[i]!=' ') {
				b[m]=b[m]*10+a[i]-'0';
			} else if(i == strlen(a) - 1) {
				b[m]=b[m]*10+a[i]-'0';
				m++;
			} else {
				m++;
			}
		}
	}
	n=0;
	for(int i=0; i < strlen(c); i++ ) {
		if(( c[i] >= '0' && c[i] <= '9')||c[i]==' ') {
			if(c[i]!=' ') {
				d[n]=d[n]*10+c[i]-'0';

			} else if(i == strlen(c) - 1) {
				d[n]=d[n]*10+c[i]-'0';
				n++;
			} else {
				n++;
			}
		}
	}
	for(int j=k-1; j<=m; j++) {
		b[j]=b[j+len1];
	}
	for(int j=0; j<l-1; j++) {
        printf("%d ", d[j]);
	}
	for(int j=0; j<=m-len1; j++) {
        printf("%d ", b[j]);
	}
	for(int j=l-1; j<=n; j++) {
        printf("%d ", d[j]);
	}
}