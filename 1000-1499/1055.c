#include <stdio.h>
#include <string.h>

/*
����Ԩ��ԭ��һ��BBS�ϵ�����Ϊzvbo941987,Ϊ�˷�����䣬��ͨ��һ���㷨���������任��YUANzi1987��
����������������ֺͳ�����ݣ���ô���������ˣ����ҿ�����Ŀ�ŵ��ط������۵ĵط�����������֪�����������롣 
������ô�任�ģ���Ҷ�֪���ֻ��ϵ���ĸ�� 1--1�� abc--2, def--3, ghi--4, jkl--5, mno--6, pqrs--7, tuv--8
 wxyz--9, 0--0,����ô�򵥣�Ԩ�Ӱ������г��ֵ�Сд��ĸ����ɶ�Ӧ�����֣����ֺ������ķ��Ŷ������任��
 
 ������������û�пո񣬶������г��ֵĴ�д��ĸ��߳�Сд֮��������һλ��
 �磺X���ȱ߳�Сд����������һλ��������y����򵥰ɡ���ס��z��������aŶ��
*/

/*
�����������������ݡ�������һ�����ģ����볤�Ȳ�����100���ַ�������ֱ���ļ���β��
������Ԩ�����������ġ�

���룺
YUANzi1987

�����
zvbo941987
*/

int main() {
	char password[100];
	while (scanf("%s", &password) != EOF) {
		int length = strlen(&password[0]);
		for (int idx = 0; idx < length; idx++) {
			if ('A' <= password[idx] && password[idx] <= 'Y') {
				password[idx] = password[idx] - 'A' + 'a' + 1;
			}
			else if (password[idx] == 'Z') {
				password[idx] = 'a';
			}
			else if ('a' <= password[idx] && password[idx] <= 'c') {
				password[idx] = '2';
			}
			else if ('d' <= password[idx] && password[idx] <= 'f') {
				password[idx] = '3';
			}
			else if ('g' <= password[idx] && password[idx] <= 'i') {
				password[idx] = '4';
			}
			else if ('j' <= password[idx] && password[idx] <= 'l') {
				password[idx] = '5';
			}
			else if ('m' <= password[idx] && password[idx] <= 'o') {
				password[idx] = '6';
			}
			else if ('p' <= password[idx] && password[idx] <= 's') {
				password[idx] = '7';
			}
			else if ('t' <= password[idx] && password[idx] <= 'v') {
				password[idx] = '8';
			}
			else if ('w' <= password[idx] && password[idx] <= 'z') {
				password[idx] = '9';
			}
		}
		printf("%s\n", password);
	}
	return 0;
}