#include <stdio.h>
#include <stdbool.h>
#define n 10

/*
给定10个整数input[i]: 0  1  2  3  4  5  6  7  8  9  
输出10个整数output[i]: 6  2  1  0  0  0  1  0  0  0  
在输出的10个数中，0刚好出现6次，1出现2次，2出现1次，3出现0次，…，6出现1次，…
*/


int ar_input[n];

int ar_output[n];
/*
分析：
1. 在input[i]中，0≤某项<10，所有项之和=10
2. output[i]表示input[i]在output序列中出现的总个数
*/

bool check(int left) {
    // 如果剩余额度>0，则肯定不是符合题意的解
    if (left == 0) {
        // 逐个检查output[i]是否等于input[i]在output序列中的个数
        for (int i = 0; i < n; i++) {
            int cnt = 0;
            for (int j = 0; j < n; j++) {
                if (ar_output[j] == ar_input[i]) cnt++;
            }
            if (cnt != ar_output[i]) return false;
        }
        return true;
    } else {
        return false;
    }    
}

bool dfs(int pos, int left) {
    // 所有位置已经生成完毕，校验序列是否符合题意
    if (pos == n) {
        return check(left);
    } 
    // 否则进行递归搜索
    else {
        for (int cut = 0; cut <= left; cut++) {
            ar_output[pos] = cut;
            if (dfs(pos + 1, left - cut)) return true;
        }
        return false;
    }
}

int main() {
    
    for (int i = 0; i < n; i++) {
        scanf("%d", ar_input + i);
    }
    
    if (dfs(0, n)) {
        for (int i = 0; i < n; i++) {
            printf(i == n - 1 ? "%d\n" : "%d ", ar_output[i]);
        }
    } else {
        puts("No answer!");
    }
    
}