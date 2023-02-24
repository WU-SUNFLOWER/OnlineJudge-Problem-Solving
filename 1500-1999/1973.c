#include <stdio.h>
#include <math.h>

int main() {
	int arr[7];
    //数组map用于建立已装3*3商品的盒子中所含3*3商品的数量
    //与其中仍可装入2*2商品数量的关系
    //注意map[0]表示装3*3商品的盒子都恰好装满，也就是没有装了3*3商品但有空余空间的盒子
    int map[] = {0, 5, 3, 1};  
    while (scanf("%d %d %d %d %d %d", &arr[1], &arr[2], &arr[3], &arr[4], &arr[5], &arr[6]) != EOF) {
	    int ans = 0;
    	if (arr[1] + arr[2] + arr[3] + arr[4] + arr[5] + arr[6] == 0) {
    		break;
		}
	    //处理大号商品
	    ans += arr[6] + arr[5] + arr[4] + ceil(arr[3] / 4.0);
	    //放置2*2的商品
	    //首先尝试将2*2商品塞入已装大号商品的盒子中
	    int freePlaceFor2 = arr[4] * 5 + map[arr[3] % 4];
	    //如果2*2商品还有多余，再开新的盒子来装
	    if (arr[2] > freePlaceFor2) {
	        ans += ceil(arr[2] / 9.0);
	    }
	    //至此2*2~6*6的全部商品都已放置完毕
	    //最后放置1*1的商品，该商品直接找任意盒子的空隙来塞即可
	    int freePlaceFor1 = ans * 36 - arr[2] * 4 - arr[3] * 9 - arr[4] * 16 - arr[5] * 25;
	    //如果1*1商品还有多余，再开新的盒子来装
	    if (arr[1] > freePlaceFor1) {
	        ans += ceil(arr[1] / 36.0);
	    }
	    printf("%d\n", ans);
	}
	return 0;
}