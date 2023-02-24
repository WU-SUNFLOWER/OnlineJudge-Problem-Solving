#include<stdio.h>
#include<stdlib.h>

void sort(int* s[], int len) {
	int i, j;
	for (i = 0; i < len; i++) {
		for (j = i; j < len; j++) {
            //s[i]就是s指针数组中第i个元素保存的一级指针，再次解引用就是最终的数据空间
			if (*(s[i]) > *(s[j])) {
				int tmp = *(s[i]); //指针的好处在于直接通过赋值可以改变指向
				*(s[i]) = *(s[j]);  //只要交换了字符串的地址就实现了字符串的交换
				*(s[j]) = tmp;//因此通过指针指向的交换就能够实现数组中字符串的排序
			}
		}
	}
}

int main() {
	int count;
    while (~scanf("%d", &count)) {
        //创建int数组用于存放输入数据
    	int* integers = (int*)malloc(count * sizeof(int));
    	//创建int*数组用于存放数组中每个元素的指针
        int** p = (int**)malloc(count * sizeof(int*));
    	for (int i = 0; i < count; i++) {
    		p[i] = integers + i; //将数组中每个int元素空间的首地址赋值给指针数组中的各个元素
    		scanf("%d", p[i]);//p[i]就保存时第i个数据的地址，因此这里不用取地址
    	}
    	sort(p, count);
    	for (int i = 0; i < count; i++) {
    		printf(i == count - 1 ? "%d\n" : "%d ", integers[i]);
    	}
    	free(integers);
    	free(p);        
    }
	return 0;
}