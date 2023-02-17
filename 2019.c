#include <stdio.h>
#define N 2001

/*
参考资料：
https://blog.csdn.net/weixin_30367543/article/details/98148277
https://blog.csdn.net/u013514928/article/details/44903743
*/

//Map_IsNotPrime[i]为0，表示i是素数
//0,1都不是素数，2是素数 
//这里不设计成Map_IsPrime的原因在于，这样更便于利用数组初值为0的特性
int IsNotPrime[N] = {1, 0, 0};
int PrimeArray[N];
int PrimeCount = 0;

//打表
//初始化Map_IsPrime和PrimeArray
void init(){
    for (int i = 2; i < N; i++) {
        //当一个数是素数时，它与大于1的其他数的乘积一定不是素数
        //故直接将对应的Map_IsNotPrime标记为1即可
        if (!IsNotPrime[i]){
            PrimeArray[PrimeCount++] = i;
            for (int j = 2; j * i < N; j++){
                IsNotPrime[i * j] = 1;
            }
        }
    }
}

//从PrimeArray数组中找出被区间[left, right]包裹的子区间的右端点
//设计该函数是为了用于确定枚举的右边界
int findRightBorder(int key) {
    int left = 0;
    int right = PrimeCount - 1;
    int mid;
    while (left <= right) {
        mid = (left + right) / 2;
        if (key == PrimeArray[mid]) {
            return mid;
        }
        else if (key > PrimeArray[mid]) {
            left = mid + 1;
        } else {
            right = mid - 1;
        } 
     }
     return right;
}

//从PrimeArray数组中找出被区间[left, right]包裹的子区间的左端点
//设计该函数是为了用于确定枚举的左边界
int findLeftBorder(int key) {
    int left = 0;
    int right = PrimeCount - 1;
    int mid;
    while (left <= right) {
        mid = (left + right) / 2;
        if (key == PrimeArray[mid]) {
            return mid;
        }
        else if (key < PrimeArray[mid]) {
            right = mid - 1;
        }
        else {
            left = mid + 1;
        }
    }
    return left;
}
 
//求解
int func(int pos, int leftBorder, int rightBorder) {
    int midNum = PrimeArray[pos];
    int ans = 0;
    //借助双重循环，先确定较小的y，再顺势确定较大的y
    //根据分析，midNum + y和midNum + x所确定的元素顶多分别是第三大和第二大的，
    //故循环结束条件分别设置为rightBorder - 2和rightBorder - 1
    for (int i = pos + 1; i <= rightBorder - 2; i++){
        int y = PrimeArray[i] - midNum;
        //剪枝，确保由y确定的两个元素都是素数
        if (midNum - y < PrimeArray[leftBorder] || IsNotPrime[midNum - y] || IsNotPrime[midNum + y]) {
            continue;
        }
        for (int j = i + 1; j <= rightBorder - 1; j++){
            int x = PrimeArray[j] - midNum;
            int z = x - y;
            int w = x + y;
            //剪枝，首先确保由x确定的两个元素都是素数
            //（实际上此时也保证了z确定的元素不会越界）
            //其次，为了防止z和y相等，需要保证x ≠ 2 * y
            //最后，需要确保由w确定的两个元素不越界
            if (
                midNum - x < PrimeArray[leftBorder] || 
                IsNotPrime[midNum - x] ||
                IsNotPrime[midNum + x] ||
                x == 2 * y || 
                midNum - w < PrimeArray[leftBorder] ||
                midNum + w > PrimeArray[rightBorder]
            ) {
                continue;
            }
            if (!(IsNotPrime[midNum - z] + IsNotPrime[midNum + z] + IsNotPrime[midNum + w] + IsNotPrime[midNum - w])) {
                ans++;
            }
        }
    }
    return ans;
} 

int main(){
    init();
    int leftBorder;
    int rightBorder;
    scanf("%d,%d", &leftBorder, &rightBorder);
    int ans = 0;
    int accurLB = findLeftBorder(leftBorder);
    int accurRB = findRightBorder(rightBorder);
    //暴力枚举所有可能居于方阵中央的素数下标
    for (int pos = accurLB + 4; pos <= accurRB - 4; pos++){
        ans += func(pos, accurLB, accurRB);
    }
    printf("共%d个素数幻方\n", ans);
    return 0;
}