#include <stdio.h>

/*
�ڴ�ѧ��ܶ൥�ʶ���һ�ʶ��壬ż���������ﻹҪ�������塣������Redraiment�ܳ���ʱ�䡣
����ʼ�Ѽ���Щ���ʵ��������塣��������һЩ���ɣ�����
��a�����á�e��������, ��c�����á�f�������桭��
��������������ĸ���滻����������ʾ��A��E�滻��B��C�滻���������ơ�
A B C D E F G H I J K L M N O P Q R S T U V W X Y Z
E C F A J K L B D G H I V W Z Y M N O P Q R S T U X
a b c d e f g h i j k l m n o p q r s t u v w x y z
e r w q t y g h b n u i o p s j k d l f a z x c v m
*/

/*
�����������������ݡ� ÿ���������Ϊһ�У�Ϊ������ĸ�Ϳո���ɵ��ַ���(�ո񲻱�)�� �����Ե��С�#��������

���룺
Ilttabaje zaujljg
#

�����
��Ӧÿ��������ݣ��滻��������������塣
Different meaning
*/

int main() {
	char ch;
	char upperCaseArr[] = {'E', 'C', 'F', 'A', 'J', 'K', 'L', 'B', 'D', 'G', 'H', 'I', 'V', 'W', 'Z', 'Y', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'X'};
	char lowerCaseArr[] = {'e', 'r', 'w', 'q', 't', 'y', 'g', 'h', 'b', 'n', 'u', 'i', 'o', 'p', 's', 'j', 'k', 'd', 'l', 'f', 'a', 'z', 'x', 'c', 'v', 'm'};
	while((ch = getchar()) != '#') {
		if ('a' <= ch && ch <= 'z') {
			ch = lowerCaseArr[ch - 'a'];
		}
		else if ('A' <= ch && ch <= 'Z') {
			ch = upperCaseArr[ch - 'A'];
		}
		putchar(ch);
	}
	return 0;
}