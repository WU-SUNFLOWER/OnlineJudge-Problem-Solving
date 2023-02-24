#include <stdio.h>
#include <string.h>

//У���Ƿ���������ظ��Ӵ�
int isSimpleString(char str[], int tailIdx) {
    int ans = 0;
    int maxStep = (tailIdx + 1) / 2;
    //���ѭ������У���׺�ļ�ಽ����С
    //�ڲ�ѭ�����к�׺�����У��
    for (int i = 1; i <= maxStep; i++) {
        int j;
        for (j = tailIdx; j >= tailIdx - i + 1; j--) {
            //���ֵ�ǰ�����³��ֲ�ƥ�䣬��ֹͣУ�飬������һ�ֲ���
            if (str[j] != str[j - i]) {
                break;
            }
        }
        if (j == tailIdx - i) {
            ans = 1;
            break;
        }
    }
    return ans;
}

int dfs(int* cntNode, int targetNode, int curLen, int dictSize, char ans[]) {
    if (*cntNode == targetNode) {
        for (int i = 0; i < curLen; i++) {
            printf("%c", ans[i]);
        }
        return 1;
    }
    //�����ֵ���˳�򣬴�С����أ�ö���ֵ��е������ַ����г���
    for (char i = 'A'; i <= 'A' + (char)dictSize - 1; i++) {
        //�Ƚ�ö�ٵ��ַ�д�����飬Ȼ�����У��
        //���У��ɹ�����˵���������ڵ�Ĵ����������У�������������
        ans[curLen] = i;
        if (!isSimpleString(ans, curLen)) {
            (*cntNode)++;
            if (dfs(cntNode, targetNode, curLen + 1, dictSize, ans)) {
                return 1;
            }
        }
    }
    return 0;
}

int main() {
    int cntNode = 0;  //��¼�Ѿ����ҵ��������ڵ�����
    int dictSize;
    int targetNode;
    char ans[10010];
    scanf("%d %d", &targetNode, &dictSize);
    dfs(&cntNode, targetNode, 0, dictSize, ans);
}